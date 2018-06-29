#ifndef DUI_BASE_H_
#define DUI_BASE_H_

#include <Windows.h>

#ifdef WIN32_LEAN_AND_MEAN
#undef WIN32_LEAN_AND_MEAN
#endif

#include <UIlib.h>
using namespace DuiLib;



#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "D:\\SoftSDK\\duilib\\lib\\DuiLib_ud.lib")
#   else
#       pragma comment(lib, "D:\\SoftSDK\\duilib\\lib\\DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "D:\\SoftSDK\\duilib\\lib\\DuiLib_u.lib")
#   else
#       pragma comment(lib, "D:\\SoftSDK\\duilib\\lib\\DuiLib.lib")
#   endif
#endif

#endif //DUI_BASE_H_
