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
				//��ģʽ���ڵ�����ʾ����Ľ�
				::MessageBox(NULL, _T("���ǰ�ť"), _T("����˰�ť"), NULL);
				//AfxMessageBox(_T("���ǰ�ť"));
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
				// ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ����
				// ���ǿ�����Notify����������Ϣ����
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