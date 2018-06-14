#pragma once


#include "dui_base.h"
/*
��duilib��Դ������Կ�����
(1) XML�� <VerticalLayout> �ڵ��Ӧ��duilib���CVerticalLayoutUI�ؼ�
(2) CVerticalLayoutUI�ؼ��̳���CContainerUI����CContainerUI�̳���CControlUI��
	������ʵCVerticalLayoutUI Ҳ��һ���ؼ�����������CButtonUIͬ�ȶԴ����ͱȽϺ�����ˡ�
	Ϊ�˽�һ���������ǵ����ƣ����Խ�XML�����VerticalLayout ���� Button��Control��Container ���ԣ�
	��ᷢ��Ч����һ����Ŷ~

�ٴ�ǿ����win32/MFC�Ľ��� ��duilib ���������
	(1)MFC�н���ť���˵����������ȵȶ�������ͬ�Ķ��������������ֻ�ܷ��������棬��ť����ֱ���ϵ��������ȵȣ���
	duilib�н����еĶ�����ͬ�ȶԴ������Դ��������ǳ����㣨��˵�Ѱ�ť�ŵ��������ϣ�����ѱ��������ڰ�ť�϶�û���⣩��
	(2)MFC�����еĴ��ںͿؼ����Ǽ̳���CWnd��win32�̳���HWND����
	duilib�����еĿؼ����̳���CControlUI�����еĴ��ڶ��̳���CWindowWnd���ڲ���װ��HWND����
	���������MFC��һ�����棬��ô������Ǻܶ��CWnd����Spy++���Կ�����ͬ�Ĵ��ھ����
	�����duilib��һ�����棬��ô������Ǻܶ��CControlUI��������Spy++ֻ�ܿ���һ�����ھ����
	������Ϊduilib��������ֻ��һ��HWND��������CControlUI��Ȼ�ǿؼ���������ʵ�����Լ����Ƴ����ģ�������������HWND��
	��������԰���Щ�ؼ����Ϊ�Ի棬����duilib�Ľ�����ƣ��������Ի�һ��HWND��

	����height="32" ��ָ���HorizontalLayout ֻռ��32�����ظ߶ȡ�

	����ֻ����һ�д���<HorizontalLayout />�����ñ������Ƶ������棬���д������˼�ǣ�ռ�ݿհ׵Ĳ��֡�
	�������д�����ڱ�����HorizontalLayout �����棬���Ա�������������ȥ������ŵ����棬��û��Ч����

	Ϊʲô���������ܵ��м����أ� 
	�ڱ���������������涼��һ��ռ��λ��<HorizontalLayout />�����û��ָ���߶ȣ���ô���ǻ�Ĭ�ϸ�ռһ��߶ȣ��൱����һ��Ĭ�ϵ����� height="***"

*/

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const {
		return _T("ABLE-MainFrame");
	}
	virtual CDuiString GetSkinFile() {
		//const TCHAR* file = _T("..\\Demo\\exc9_1.xml"); //�ޱ�����
		//const TCHAR* file = _T("..\\Demo\\exc9_2.xml"); //�������ڶ���,ֻ���ڶ���ʱ��˫�����������Զ���󻯣�����
		//const TCHAR* file = _T("..\\Demo\\exc9_3.xml");   //�������ڵײ�
		//const TCHAR* file = _T("..\\Demo\\exc9_4.xml");   //���������м�
		//const TCHAR* file = _T("..\\Demo\\exc9_5.xml");   //������-��С��
		const TCHAR* file = _T("..\\Demo\\exc9_6.xml");   //������-��С����󡢹ر�
		//const TCHAR* file = _T("..\\Demo\\exc9_7.xml");   //������-��ťλ���Զ���
		
		return file;
	}
	virtual CDuiString GetSkinFolder() {
		return _T("");
	}
};

