// EVA.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "EVA.h"



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
	
	::CoUninitialize(); //exc13

	return 0;
}

