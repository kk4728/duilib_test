#pragma  once

#include "dui_base.h"


class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const {
		return _T("DUIMainFrame");
	}

	virtual void Notify(TNotifyUI& msg) {}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
		LRESULT lRes = 0;
		
		switch (uMsg)
		{
		case WM_CREATE:
			{
				CControlUI* pWnd = new CButtonUI;
				pWnd->SetName(_T("btnHello")); //¿Ø¼þID
				pWnd->SetText(_T("Hello World"));
				pWnd->SetBkColor(0xFF00FF00);

				m_paintManager.Init(m_hWnd);
				m_paintManager.AttachDialog(pWnd);
				m_paintManager.AddNotifier(this);
				return lRes;
			}
		case WM_NCACTIVATE:
			{
				if(! ::IsIconic(m_hWnd)) {
					return (wParam == 0) ? TRUE : FALSE;
				}

			}
		case WM_NCCALCSIZE: {
				return 0;
			}
		case WM_NCPAINT:
			{
				return 0;
			}

		}

		if(m_paintManager.MessageHandler(uMsg,wParam, lParam, lRes)) {
			return lRes;
		}

		return __super::HandleMessage(uMsg,wParam, lParam);
	}

protected:
	CPaintManagerUI m_paintManager;
};
