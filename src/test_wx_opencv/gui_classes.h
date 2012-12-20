///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_CLASSES_H__
#define __GUI_CLASSES_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class c_ocv_canvas;

#include <wx/scrolwin.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
#include <wx/frame.h>
#include <wx/statbox.h>
#include <wx/panel.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ImageFrame
///////////////////////////////////////////////////////////////////////////////
class ImageFrame : public wxFrame 
{
	private:
	
	protected:
		c_ocv_canvas* m_ocv_canvas;
		wxMenuBar* mImageFrameMenuBar;
		wxMenu* mFileMenu;
		wxMenu* mViewMenu;
		wxMenu* mImageMenu;
		wxMenu* mToolsMenu;
		wxMenu* mHelpMenu;
		wxStatusBar* mImageFrameStatusBar;
		wxToolBar* mImageFrameToolBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void on_erase_background( wxEraseEvent& event ) { event.Skip(); }
		virtual void on_menu_open( wxCommandEvent& event ) { event.Skip(); }
		virtual void on_menu_exit( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ImageFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~ImageFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GraphFrame
///////////////////////////////////////////////////////////////////////////////
class GraphFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* mGraphFrameMenuBar;
		wxMenu* mFileMenu;
		wxMenu* mHelpMenu;
		wxToolBar* mGraphFrameToolBar;
	
	public:
		
		GraphFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GraphFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class OverviewFrame
///////////////////////////////////////////////////////////////////////////////
class OverviewFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* mOverviewFrameMenuBar;
		wxMenu* mFileMenu;
		wxMenu* mHelpMenu;
		
		// Virtual event handlers, overide them in your derived class
		virtual void on_close( wxCloseEvent& event ) { event.Skip(); }
		virtual void on_size( wxSizeEvent& event ) { event.Skip(); }
		
	
	public:
		
		OverviewFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~OverviewFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class OverviewImgSubPanel
///////////////////////////////////////////////////////////////////////////////
class OverviewImgSubPanel : public wxPanel 
{
	private:
	
	protected:
		c_ocv_canvas* m_img_canvas_left;
		c_ocv_canvas* m_img_canvas_mid;
		c_ocv_canvas* m_img_canvas_right;
		
		// Virtual event handlers, overide them in your derived class
		virtual void on_left_dbl_clk( wxMouseEvent& event ) { event.Skip(); }
		virtual void on_paint( wxPaintEvent& event ) { event.Skip(); }
		
	
	public:
		
		OverviewImgSubPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,150 ), long style = wxRAISED_BORDER|wxSIMPLE_BORDER|wxSTATIC_BORDER|wxSUNKEN_BORDER|wxTAB_TRAVERSAL ); 
		~OverviewImgSubPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class OverviewGraphSubPanel 
///////////////////////////////////////////////////////////////////////////////
class OverviewGraphSubPanel  : public wxPanel 
{
	private:
	
	protected:
		
		// Virtual event handlers, overide them in your derived class
		virtual void on_paint( wxPaintEvent& event ) { event.Skip(); }
		
	
	public:
		
		OverviewGraphSubPanel ( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL ); 
		~OverviewGraphSubPanel ();
	
};

#endif //__GUI_CLASSES_H__