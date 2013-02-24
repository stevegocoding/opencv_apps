#include <algorithm>
#include <fstream>
#include "image.h"

c_ocv_image_manager* get_ocv_img_mgr()
{
	static c_ocv_image_manager instance; 
	return &instance; 
} 

c_ocv_image_manager::c_ocv_image_manager()
{
	m_grayscale_imgs.reserve(k_num_images); 
	m_hists.reserve(k_num_images); 

	for (int i = 0; i < k_num_images; ++i)
		m_grayscale_imgs.push_back(ocv_mat_ptr()); 
	for (int i = 0; i < k_num_images; ++i)
		m_hists.push_back(ocv_mat_ptr()); 
}

c_ocv_image_manager::~c_ocv_image_manager()
{
	release_all(); 
}

ocv_mat_ptr c_ocv_image_manager::load_from_file(const std::string& file_name, e_image_idx idx, int flag)
{
	if (!is_image_valid(idx))
	{
		unload(idx); 
	}
	
	cv::Mat temp = cv::imread(file_name.c_str(), flag);
	m_grayscale_imgs[idx].reset(new cv::Mat(temp));
	// *m_grayscale_imgs[idx] = temp.clone();
	
	if (!m_grayscale_imgs[idx]->data)
	{
		ptr_delete(m_grayscale_imgs[idx]); 
		return ocv_mat_ptr(); 
	}

	// m_grayscale_imgs[idx] = new_mat; 

	return m_grayscale_imgs[idx]; 
}

void c_ocv_image_manager::unload(e_image_idx idx)
{
	if (is_image_valid(idx))
	{ 
		/*
		m_grayscale_imgs[idx].delete_obj();
		m_hists[idx].delete_obj(); 
		*/
		ptr_delete(m_grayscale_imgs[idx]);
		ptr_delete(m_hists[idx]); 
	}
}

void c_ocv_image_manager::unload_util_img(const std::string& name) 
{
	name_img_map::iterator it = m_util_imgs.find(name);
	if (it != m_util_imgs.end()) 
	{
		ptr_delete(it->second);
		m_util_imgs.erase(it);
	} 
}

ocv_mat_ptr c_ocv_image_manager::calc_grayscale_hist(e_image_idx idx)
{
	int hist_size = 256;
	float range[] = {0, 256};
	const float *hist_range = {range}; 
	
	cv::Mat hist(256, 1, CV_8UC1);
	bool uniform = true; 
	bool accum = false;
	cv::calcHist(get_ptr_raw(m_grayscale_imgs[idx]), 1, 0, cv::Mat(), hist, 1, &hist_size, &hist_range, uniform, accum); 

	ocv_mat_ptr hist_mat = ocv_mat_ptr(new cv::Mat(hist)); 
	m_hists[idx] = hist_mat; 

	/*
	std::ofstream ofs("hist_debug.txt"); 
	ofs << "hist mat: " << hist; 
	ofs.close();
	*/ 

	return hist_mat; 
}

void c_ocv_image_manager::calc_mtf(e_image_idx idx, const cv::Point2i& p1, const cv::Point2i& p2, mtf_data_vec& mtf_data)
{
	ocv_mat_ptr img = m_grayscale_imgs[idx];
	cv::LineIterator it(*img, p1, p2, 8, true);
	mtf_data.clear(); 

	for (int i = 0; i < it.count; ++i, ++it)
	{
		float v = img->at<float>(it.pos());
		mtf_data.push_back((unsigned char)v);
	} 
}

ocv_mat_ptr c_ocv_image_manager::resize_img(e_image_idx img, cv::Size& size, int interpolation /* = cv::INTER_LINEAR */)
{
	ocv_mat_ptr src_img = get_grayscale_img(img);
	assert(!is_ptr_null(src_img) && src_img->data);
	ocv_mat_ptr dest_img = ocv_mat_ptr(new cv::Mat(*src_img));
	assert(dest_img->data);
	
	cv::resize(*src_img, *dest_img, size, 0.0, 0.0, interpolation);
	assert(dest_img->data); 

	return dest_img; 
}

ocv_mat_ptr c_ocv_image_manager::get_grayscale_img(e_image_idx idx)
{
	if (m_grayscale_imgs.empty()) 
		return  ocv_mat_ptr(); 
	else
		return m_grayscale_imgs[idx];
}

ocv_mat_ptr c_ocv_image_manager::new_greyscale_img(e_image_idx img_idx, int width, int height)
{
	if (get_grayscale_img(img_idx) == ocv_mat_ptr()) 
	{
		m_grayscale_imgs[img_idx].reset(new cv::Mat(width, height, CV_8UC1));
	}
	return get_grayscale_img(img_idx);
} 

ocv_mat_ptr c_ocv_image_manager::new_grayscale_img(int width, int height)
{
	if (width < 0 || height < 0)
		return ocv_mat_ptr(); 
	
	ocv_mat_ptr new_img;
	new_img.reset(new cv::Mat(width, height, CV_8UC1));
	return new_img; 
}

ocv_mat_ptr c_ocv_image_manager::add_grayscale_img(const std::string& name, int width, int height)
{
	name_img_map::iterator it = m_util_imgs.find(name);
	if (it != m_util_imgs.end()) 
	{
		return it->second; 
	} 
	ocv_mat_ptr new_img = new_grayscale_img(width, height); 
	m_util_imgs.insert(std::pair<std::string, ocv_mat_ptr>(name, new_img)); 
	return new_img; 
} 

//////////////////////////////////////////////////////////////////////////


int hist_mat_to_vector(ocv_mat_ptr hist, hist_data_vec& hist_vec)
{
	if (is_ptr_null(hist))
		return -1;  

	hist_vec.clear(); 

	size_t elem_size = hist->elemSize();
	int elem_depth = hist->depth();

	for(int i = 0; i < hist->rows; ++i)
	{	
		float *pv = hist->ptr<float>(i); 
		hist_vec.push_back((int)*pv); 
	} 
	
	return (int)(hist_vec.size()); 
}

