#pragma  once

#include "dui_base.h"

class CDuiFrameWnd : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const {
		return _T("DUIMainFrame");
	}

	virtual void Notify(TNotifyUI& msg) {
		if(msg.sType == _T("click")) {
			if(msg.pSender->GetName() == _T("btnHello")) {
				//非模式窗口弹出提示，需改进
				::MessageBox(NULL, _T("我是按钮"), _T("点击了按钮"), NULL);
				//AfxMessageBox(_T("我是按钮"));
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
		LRESULT lRes = 0;

		switch (uMsg)
		{
		case WM_CREATE:
			{
				m_paintManager.Init(m_hWnd);

				CDialogBuilder builder;
				CControlUI* pRoot = builder.Create(_T("duilib.xml"), 0, NULL, &m_paintManager);
				ASSERT(pRoot && "FAILed to parse XML");

				m_paintManager.AttachDialog(pRoot);
				// 添加控件等消息响应，这样消息就会传达到duilib的消息循环，
				// 我们可以在Notify函数里做消息处理
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