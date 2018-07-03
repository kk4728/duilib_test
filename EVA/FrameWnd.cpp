#include "stdafx.h"
#include "Resource.h"
#include "FrameWnd.h"
#include "MenuWnd.h"

CDuiFrameWnd::CDuiFrameWnd(LPCTSTR pszXMLPath)
	: CXMLWnd(pszXMLPath)
{

}

void CDuiFrameWnd::InitWindow() {
	SetIcon(IDI_ICON1); // 设置任务栏图标
	CenterWindow();

	//初始化进度条
	CProgressUI* pProgress = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("pbx_percent")));
	pProgress->SetValue(100);
	pProgress->SetText(_T("50%"));

	{
		CProgressUI* pProgress = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("pbx_percent_ng")));
		pProgress->SetValue(100);
		pProgress->SetText(_T("50%"));
		RECT rect = pProgress->GetPos();
	}
	

	//初始化List控件
	CDuiString str;
	CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("lbx_proInfo")));
	for (int i = 0; i < 8; i++)
	{
		CListTextElementUI* pListElement = new CListTextElementUI;
		pListElement->SetTag(i);
		pList->Add(pListElement);
		
		pListElement->SetBorderSize(2);
		pListElement->SetBorderColor(0xFFffffff);
		switch(i)
		{
		case 0:
			pListElement->SetText(0, _T("Batch filename"));
			pListElement->SetText(1, _T("BR17_EVA100_C_V6.0_8S.bat"));
			break;
		case 1:
			pListElement->SetText(0, _T("Program name"));
			pListElement->SetText(1, _T("BR17_EVA100_C_V6.0_8S.atelier"));
			break;
		case 2:
			pListElement->SetText(0, _T("Flow name"));
			pListElement->SetText(1, _T("Test Flow"));
			break;
		case 3:
			pListElement->SetText(0, _T("Number of DUIs"));
			pListElement->SetText(1, _T("8"));
			break;
		case 4:
			pListElement->SetText(0, _T("Product No."));
			pListElement->SetText(1, _T("BR17"));
			break;
		case 5:
			pListElement->SetText(0, _T("Lot No."));
			pListElement->SetText(1, _T("AP19645"));
			break;
		case 6:
			pListElement->SetText(0, _T("Operator name"));
			pListElement->SetText(1, _T("BR17"));
			break;
		case 7:
			pListElement->SetText(0, _T("Comment"));
			pListElement->SetText(1, _T("1"));
			break;
		default:
			break;
		}	
	} 

	//初始化List - Log控件
	{
		CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("lbx_log")));
		for (int i = 0; i < 2; i++)
		{
			CListTextElementUI* pListElement = new CListTextElementUI;
			pListElement->SetTag(i);
			pList->Add(pListElement);
			switch(i)
			{
			case 0:
				pListElement->SetText(0, _T("12/2/2017 06:27:44 AM: Data log file has been generated. :C\\eva\\PETOOL\\User\\log\\BR17_AP19645-10_20171202050421_Dlog.txt"));
				pListElement->SetBkColor(0xFFA5A5A5);
				break;
			case 1:
				pListElement->SetBkColor(0x005A5A5A);
				pListElement->SetText(0, _T("12/2/2017 08:37:56 AM: Summary file has been generated. :C\\eva\\PETOOL\\User\\log\\BR17_AP19645-10_20171202050421_Summry.txt"));
				break;
			default:
				break;
			}	
		}
	}
	
}

void CDuiFrameWnd::Notify(TNotifyUI& msg) {
	if( msg.sType == _T("click") ) {
		if( msg.pSender->GetName() == _T("btnMenu") ) {
			POINT pt = {msg.ptMouse.x, msg.ptMouse.y};
			CMenuWnd *pMenu = new CMenuWnd(_T("../res/Menu/menu.xml"));

			pMenu->Init(*this, pt);
			pMenu->ShowWindow(TRUE);
		}
		else if(msg.pSender->GetName() == _T("btn_start")) {
			CProgressUI* pControl = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("pbx_percent")));
			int var = pControl->GetValue();
	
			var -=10;
			CDuiString str;
			str.Format(_T("%.2f"), var);
			pControl->SetFixedWidth(pControl->GetWidth()*0.9);
			//pControl->SetValue(var);
			pControl->SetText(str+_T("%"));
			
		}

	}
	else if(msg.sType == _T("selectchanged"))
	{
		CDuiString    strName     = msg.pSender->GetName();
		CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tab_sys")));

		if(strName == _T("opt_program_load"))		pControl->SelectItem(0);
		else if(strName == _T("opt_user_param"))	pControl->SelectItem(1);
		else if(strName == _T("opt_pfmeter"))		pControl->SelectItem(2);
		else if(strName == _T("opt_hwbin"))			pControl->SelectItem(4);
		else if(strName == _T("opt_swbin"))			pControl->SelectItem(5);
		else if(strName == _T("opt_datalog"))		pControl->SelectItem(6);
	}

	__super::Notify(msg);
}

CControlUI* CDuiFrameWnd::CreateControl(LPCTSTR pstrClass) {
	if (_tcsicmp(pstrClass, _T("Wnd")) == 0)
	{
		CWndUI  *pUI  = new CWndUI;            
		HWND    hWnd  = CreateWindow(_T("BUTTON"), _T("win32"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 0, 0, 0, 0, m_PaintManager.GetPaintWindow(), NULL, NULL, NULL);
		pUI->Attach(hWnd);  

		//// 上面用的是win32的按钮，下面这段用MFC的按钮
		//CButton *pBtn = new CButton;    // 记得释放内存
		//pBtn->Create(_T("MFC"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, CRect(0, 0, 0, 0), CWnd::FromHandle(m_PaintManager.GetPaintWindow()), 0);
		//pUI->Attach(*pBtn);            
		return pUI;
	}

	return NULL;
}