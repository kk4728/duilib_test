#pragma once

#include "resource.h"

#include "../include/dui_base.h"
#include "ControlEx.h"

class CEVA : public CWindowWnd, public INotifyUI
{
public:
	CEVA() {

	}

	LPCTSTR GetWindowClassName() const {
		return _T("EVA.ABJ.Frame");
	}

	UINT GetClassStyle() const {
		return CS_DBLCLKS;
	}

	void Init() {
		m_pCloseBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("closebtn")));
		m_pMaxBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("maxbtn")));
		m_pRestoreBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("restorebtn")));
		m_pMinBtn = static_cast<CButtonUI*>(m_pm.FindControl(_T("minbtn")));

		SetIcon(IDI_ICON1); // 设置任务栏图标

		//////////////////////////////////////////////////////////////////////////
		//初始化List控件
		CDuiString str;
		CListUI* pList = static_cast<CListUI*>(m_pm.FindControl(_T("lbx_proInfo")));
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
			CListUI* pList = static_cast<CListUI*>(m_pm.FindControl(_T("lbx_log")));
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

	void OnPrepare() {

	}

	void Notify(TNotifyUI& msg) {
		if( msg.sType == _T("windowinit") ) OnPrepare();
		else if( msg.sType == _T("click") ) {
			if( msg.pSender == m_pCloseBtn ) {
				PostQuitMessage(0);
				return; 
			}
			else if( msg.pSender == m_pMinBtn ) { 
				SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0); return; }
			else if( msg.pSender == m_pMaxBtn ) { 
				SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0); return; }
			else if( msg.pSender == m_pRestoreBtn ) { 
				SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0); return; }
		}
		else if(msg.sType==_T("selectchanged"))
		{
			CDuiString    strName     = msg.pSender->GetName();
			CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_pm.FindControl(_T("tab_sys")));

			if(strName == _T("opt_program_load"))		pControl->SelectItem(0);
			else if(strName == _T("opt_user_param"))	pControl->SelectItem(1);
			else if(strName == _T("opt_pfmeter"))		pControl->SelectItem(2);
			else if(strName == _T("opt_hwbin"))			pControl->SelectItem(4);
			else if(strName == _T("opt_swbin"))			pControl->SelectItem(5);
			else if(strName == _T("opt_datalog"))		pControl->SelectItem(6);
		}
	}

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		SetIcon(IDI_ICON1);

		LONG styleValue = ::GetWindowLong(*this, GWL_STYLE);
		styleValue &= ~WS_CAPTION;
		::SetWindowLong(*this, GWL_STYLE, styleValue | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

		m_pm.Init(m_hWnd);
		CDialogBuilder builder;
		CDialogBuilderCallbackEx cb;
		CControlUI* pRoot = builder.Create(_T("..\\EVA2\\eva2.xml"), (UINT)0,  &cb, &m_pm);
		ASSERT(pRoot && "Failed to parse XML");
		m_pm.AttachDialog(pRoot);
		m_pm.AddNotifier(this);

		Init();
		return 0;
	}

	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		bHandled = FALSE;
		return 0;
	}

	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		::PostQuitMessage(0L);

		bHandled = FALSE;
		return 0;
	}

	LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		if( ::IsIconic(*this) ) bHandled = FALSE;
		return (wParam == 0) ? TRUE : FALSE;
	}

	LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		return 0;
	}

	LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		return 0;
	}

	LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		POINT pt; pt.x = GET_X_LPARAM(lParam); pt.y = GET_Y_LPARAM(lParam);
		::ScreenToClient(*this, &pt);

		RECT rcClient;
		::GetClientRect(*this, &rcClient);

		// 		if( !::IsZoomed(*this) ) {
		// 			RECT rcSizeBox = m_pm.GetSizeBox();
		// 			if( pt.y < rcClient.top + rcSizeBox.top ) {
		// 				if( pt.x < rcClient.left + rcSizeBox.left ) return HTTOPLEFT;
		// 				if( pt.x > rcClient.right - rcSizeBox.right ) return HTTOPRIGHT;
		// 				return HTTOP;
		// 			}
		// 			else if( pt.y > rcClient.bottom - rcSizeBox.bottom ) {
		// 				if( pt.x < rcClient.left + rcSizeBox.left ) return HTBOTTOMLEFT;
		// 				if( pt.x > rcClient.right - rcSizeBox.right ) return HTBOTTOMRIGHT;
		// 				return HTBOTTOM;
		// 			}
		// 			if( pt.x < rcClient.left + rcSizeBox.left ) return HTLEFT;
		// 			if( pt.x > rcClient.right - rcSizeBox.right ) return HTRIGHT;
		// 		}

		RECT rcCaption = m_pm.GetCaptionRect();
		if( pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right \
			&& pt.y >= rcCaption.top && pt.y < rcCaption.bottom ) {
				CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(pt));
				if( pControl && _tcscmp(pControl->GetClass(), DUI_CTR_BUTTON) != 0 && 
					_tcscmp(pControl->GetClass(), DUI_CTR_OPTION) != 0 &&
					_tcscmp(pControl->GetClass(), DUI_CTR_TEXT) != 0 )
					return HTCAPTION;
		}

		return HTCLIENT;
	}

	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		SIZE szRoundCorner = m_pm.GetRoundCorner();
		if( !::IsIconic(*this) && (szRoundCorner.cx != 0 || szRoundCorner.cy != 0) ) {
			CDuiRect rcWnd;
			::GetWindowRect(*this, &rcWnd);
			rcWnd.Offset(-rcWnd.left, -rcWnd.top);
			rcWnd.right++; rcWnd.bottom++;
			HRGN hRgn = ::CreateRoundRectRgn(rcWnd.left, rcWnd.top, rcWnd.right, rcWnd.bottom, szRoundCorner.cx, szRoundCorner.cy);
			::SetWindowRgn(*this, hRgn, TRUE);
			::DeleteObject(hRgn);
		}

		bHandled = FALSE;
		return 0;
	}

	LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		MONITORINFO oMonitor = {};
		oMonitor.cbSize = sizeof(oMonitor);
		::GetMonitorInfo(::MonitorFromWindow(*this, MONITOR_DEFAULTTOPRIMARY), &oMonitor);
		CDuiRect rcWork = oMonitor.rcWork;
		rcWork.Offset(-oMonitor.rcMonitor.left, -oMonitor.rcMonitor.top);

		LPMINMAXINFO lpMMI = (LPMINMAXINFO) lParam;
		lpMMI->ptMaxPosition.x	= rcWork.left;
		lpMMI->ptMaxPosition.y	= rcWork.top;
		lpMMI->ptMaxSize.x		= rcWork.right;
		lpMMI->ptMaxSize.y		= rcWork.bottom;

		bHandled = FALSE;
		return 0;
	}

	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		// 有时会在收到WM_NCDESTROY后收到wParam为SC_CLOSE的WM_SYSCOMMAND
		if( wParam == SC_CLOSE ) {
			::PostQuitMessage(0L);
			bHandled = TRUE;
			return 0;
		}
		BOOL bZoomed = ::IsZoomed(*this);
		LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);
		if( ::IsZoomed(*this) != bZoomed ) {
			if( !bZoomed ) {
				CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(_T("maxbtn")));
				if( pControl ) pControl->SetVisible(false);
				pControl = static_cast<CControlUI*>(m_pm.FindControl(_T("restorebtn")));
				if( pControl ) pControl->SetVisible(true);
			}
			else {
				CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(_T("maxbtn")));
				if( pControl ) pControl->SetVisible(true);
				pControl = static_cast<CControlUI*>(m_pm.FindControl(_T("restorebtn")));
				if( pControl ) pControl->SetVisible(false);
			}
		}
		return lRes;
	}

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		BOOL bHandled = TRUE;
		switch( uMsg ) {
		case WM_CREATE:        lRes = OnCreate(uMsg, wParam, lParam, bHandled); break;
		case WM_CLOSE:         lRes = OnClose(uMsg, wParam, lParam, bHandled); break;
		case WM_DESTROY:       lRes = OnDestroy(uMsg, wParam, lParam, bHandled); break;
		case WM_NCACTIVATE:    lRes = OnNcActivate(uMsg, wParam, lParam, bHandled); break;
		case WM_NCCALCSIZE:    lRes = OnNcCalcSize(uMsg, wParam, lParam, bHandled); break;
		case WM_NCPAINT:       lRes = OnNcPaint(uMsg, wParam, lParam, bHandled); break;
		case WM_NCHITTEST:     lRes = OnNcHitTest(uMsg, wParam, lParam, bHandled); break;
		case WM_SIZE:          lRes = OnSize(uMsg, wParam, lParam, bHandled); break;
		case WM_GETMINMAXINFO: lRes = OnGetMinMaxInfo(uMsg, wParam, lParam, bHandled); break;
		case WM_SYSCOMMAND:    lRes = OnSysCommand(uMsg, wParam, lParam, bHandled); break;
		default:
			bHandled = FALSE;
		}
		if( bHandled ) return lRes;
		if( m_pm.MessageHandler(uMsg, wParam, lParam, lRes) ) return lRes;
		return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
	}








public:
	CPaintManagerUI m_pm;

private:
	CButtonUI* m_pCloseBtn;
	CButtonUI* m_pMaxBtn;
	CButtonUI* m_pRestoreBtn;
	CButtonUI* m_pMinBtn;
};

