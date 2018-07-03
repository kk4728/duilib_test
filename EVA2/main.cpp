#include "stdafx.h"
#include "EVA2.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin"));
	//CPaintManagerUI::SetResourceZip(_T("360SafeRes.zip"));

	HRESULT Hr = ::CoInitialize(NULL);
	if( FAILED(Hr) ) return 0;

	CEVA* pFrame = new CEVA();
	if( pFrame == NULL ) return 0;
	pFrame->Create(NULL, _T("EVA Tester"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 800, 572);
	pFrame->CenterWindow();
	//::ShowWindow(*pFrame, SW_SHOW);
	pFrame->ShowModal();

	//CPaintManagerUI::MessageLoop();

	::CoUninitialize();

	return (int) 0;
}


