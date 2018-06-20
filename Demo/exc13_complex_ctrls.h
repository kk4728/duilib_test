#pragma once

#include "dui_base.h"

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR		GetWindowClassName() const {
		return _T("DUIMainFrame");
	}
	virtual CDuiString	GetSkinFile() {
		//return _T("..\\Demo\\exc13_ComplexCtrl.xml");
		return _T("..\\Demo\\exc13_ComplexCtrl.xml");
	}
	virtual CDuiString	GetSkinFolder()	{
		return _T("");
	}

	virtual void InitWindow() {
		/**/
		CActiveXUI* pAxUI = static_cast<CActiveXUI*> (m_PaintManager.FindControl(_T("ActiveXDemo1")));
		if(pAxUI) {
			IWebBrowser2* pWebBrowser = NULL;
			// �൱�ڽ�����������DelayCreate���Ը�ΪFALSE��
			// ��duilib�Դ���FlashDemo����Կ���������ΪTRUE             
			pAxUI->SetDelayCreate(false);

			// �൱�ڽ�����������Clsid����������{8856F961-340A-11D0-A96B-00C04FD705A2}��
			// ������CLSID_WebBrowser������뿴��Ӧ��ֵ�����<ExDisp.h>
			pAxUI->CreateControl(CLSID_WebBrowser);
			pAxUI->GetControl(IID_IWebBrowser2, (void**)&pWebBrowser);
			if(pWebBrowser) {
				//pWebBrowser->Navigate(L"https://code.google.com/p/duilib/",NULL,NULL,NULL,NULL);
				pWebBrowser->Navigate(_T("http://www.baidu.com/"), NULL, NULL, NULL, NULL);
				pWebBrowser->Release();
			}
		}
		//
		CProgressUI* pProgress = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("ProgressDemo1")));    
		pProgress->SetValue(100);

		CProgressUI* pCBX = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("cbx_Demo1"))); 

		CDuiString str;
		CListUI* pList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("ListDemo1")));

		// ���List�б����ݣ�������Add(pListElement)����SetText
		for (int i = 0; i < 100; i++)
		{
			CListTextElementUI* pListElement = new CListTextElementUI;
			pListElement->SetTag(i);
			pList->Add(pListElement);

			str.Format(_T("%d"), i);
			pListElement->SetText(0, str);
			pListElement->SetText(1, _T("haha"));
		}
		
	}

	virtual void Notify( TNotifyUI& msg ) {
		if(msg.sType == _T("selectchanged")) {
			CDuiString    strName     = msg.pSender->GetName();
			CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tabTest")));

			if(strName == _T("OptionDemo1"))
				pControl->SelectItem(0);
			else if(strName == _T("OptionDemo2"))
				pControl->SelectItem(1);
			else if(strName == _T("OptionDemo3"))
				pControl->SelectItem(2);
		}

		__super::Notify(msg);
	}
};
