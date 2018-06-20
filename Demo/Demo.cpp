// Demo.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Demo.h"

//#include "exc5_nclient.h"
//#include "exc6_xml.h"
//#include "exc7_xmlclass.h"
//#include "exc8_windowtitle.h"

//#include "exc9_layout.h"
//#include "exc10_UI.h"

//#include "exc12_controls.h"
#include "exc13_complex_ctrls.h"





int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	HRESULT hr = ::CoInitialize(NULL); //exc13
	if(FAILED(hr)) return 0; //exc13

	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); //exc6

	CDuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();

	/* exc13 
	CDuiFrameWnd* pFrame = new CDuiFrameWnd;
	pFrame->Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pFrame->CenterWindow();
	pFrame->ShowModal();*/
	
	::CoUninitialize(); //exc13
	return 0;
}

