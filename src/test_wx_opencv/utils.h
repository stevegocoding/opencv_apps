#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include "wx/string.h"

std::string wxstr_to_std(const wxString& str); 
wxString stdstr_to_wx(const std::string& str); 

//////////////////////////////////////////////////////////////////////////
/// Logging Functions

void wx_log_fatal(const char *str, ...);

void wx_log_error(const char *str, ...);

void wx_log_warning(const char *str, ...);

void wx_log_message(const char *str, ...);


#endif