// EVA.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "EVA.h"

#include "FrameWnd.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	HRESULT hr = ::CoInitialize(NULL); 
	if(FAILED(hr)) return 0; 

	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); 

	CDuiFrameWnd*  pDuiFrame = new CDuiFrameWnd(_T("..\\EVA\\eva.xml"));
	if(!pDuiFrame) {
		::CoUninitialize();
		return 0;
	}
	pDuiFrame->Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pDuiFrame->CenterWindow();
	pDuiFrame->ShowModal();
	

	if(pDuiFrame) delete pDuiFrame;
	::CoUninitialize(); 


	return 0;
}

