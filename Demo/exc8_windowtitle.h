#pragma once

#include "dui_base.h"

/* �������ⶼ��XML�ڶ��е� <Window>�ڵ�����ӡ�
1��Ϊʲô�����������϶���
    ��Ҫ��<Window>�ڵ���� caption="0,0,0,32"�������32��ָ�������ĸ߶�
2����ô�ô��ڴ�С����ͨ����ק��������
    ��Ҫ��<Window>�ڵ���� sizebox="4,4,4,4"�� �����4��ָ����ƶ����߿�4�����صķ�Χ�ڣ����ͻ���ʾ��ק��ʽ��
	��ʱ�Ϳ��Ե������ڴ�С��
 
    ����Alberl��һһ������XML�������˼���󲿷ֵط���������ע���ˣ��ص�Ҫ���͵ľ���HorizontalLayout��VerticalLayout
	�Լ�Button����ʽ�ˡ�
    ��һ���Ƚ���Button����ʽ����ҿ��Կ����رհ�ť�����������ȥ�в�ͬ��ۣ�����һ����ʾ������Щ��������һ�д�����
	ָ���ģ�
	<Button 
	name="closebtn"		//Ψһ��ʶ��ť��������ť��name���������ظ�
	tooltip="�ر�"		//�����Ǹ���ʾ��������
	float="true"		//����ť��λ���Ǿ��Զ�λ����λ����pos����ָ��
	pos="44,5,74,24"	//����ť��λ�þ��󣬷ֱ�Ϊ�������ϡ��ҡ����ĸ���
	width="28"			//����ťͼƬ��ʾ�Ŀ�ȣ�������Բ���������ڰ�ťͼƬû�����ã�
						//�������Ļ���ͼƬ�ᱻ�����е�ʧ�棩
	normalimage=" file='SysBtn\CloseNormal.bmp' " //��������״̬�°�ť��ʾ��ͼƬ·��
	hotimage=" file='SysBtn\CloseFocus.bmp' "	  //�����������ȥʱ����ť��ʾ��ͼƬ·��
	pushedimage=" file='SysBtn\CloseFocus.bmp' "  //�����������ťʱ����ť��ʾ��ͼƬ·��
	/>
3,����ΪUTF-8��ʽ����Ҫʹ��windows�Դ��ļ��±��༭������ʹ��UltraEdit��EditPlus�ȱ༭��������
*/

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const {
		return _T("DUIMainFrame");
	}
	virtual CDuiString GetSkinFile() {
		return _T("..\\Demo\\exc8.xml");
	}
	virtual CDuiString GetSkinFolder() {
		return _T("");
	}
};

