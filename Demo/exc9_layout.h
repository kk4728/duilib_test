#pragma once


#include "dui_base.h"
/*
从duilib的源码里可以看到：
(1) XML的 <VerticalLayout> 节点对应于duilib里的CVerticalLayoutUI控件
(2) CVerticalLayoutUI控件继承于CContainerUI，而CContainerUI继承于CControlUI。
	所以其实CVerticalLayoutUI 也是一个控件啦，把它和CButtonUI同等对待，就比较好理解了。
	为了进一步表现他们的类似，可以将XML里面的VerticalLayout 换成 Button、Control、Container 试试，
	你会发现效果是一样的哦~

再次强调下win32/MFC的界面 和duilib 界面的区别：
	(1)MFC中将按钮、菜单、标题栏等等都当作不同的东西（例如标题栏只能放在最上面，按钮不能直接拖到标题栏等等）；
	duilib中将所有的东西都同等对待，所以处理起来非常方便（别说把按钮放到标题栏上，就算把标题栏放在按钮上都没问题）。
	(2)MFC中所有的窗口和控件都是继承于CWnd（win32继承于HWND）。
	duilib中所有的控件都继承于CControlUI，所有的窗口都继承于CWindowWnd（内部包装了HWND）。
	所以如果用MFC做一个界面，那么上面就是很多个CWnd，用Spy++可以看到不同的窗口句柄。
	如果用duilib做一个界面，那么上面就是很多个CControlUI，但是用Spy++只能看到一个窗口句柄。
	这是因为duilib整个窗口只有一个HWND，其他的CControlUI虽然是控件，但是其实都是自己绘制出来的，并不是真正的HWND，
	所以你可以把这些控件理解为自绘，整个duilib的界面绘制，就是在自绘一个HWND。

	其中height="32" 是指这个HorizontalLayout 只占用32个像素高度。

	这里只加了一行代码<HorizontalLayout />，就让标题栏移到了下面，这行代码的意思是：占据空白的部分。
	由于这行代码放在标题栏HorizontalLayout 的上面，所以标题栏被挤了下去，如果放到下面，是没有效果的

	为什么标题栏就跑到中间了呢？ 
	在标题栏的上面和下面都有一个占空位的<HorizontalLayout />，如果没有指定高度，那么他们会默认各占一半高度，相当于有一个默认的属性 height="***"

*/

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const {
		return _T("ABLE-MainFrame");
	}
	virtual CDuiString GetSkinFile() {
		//const TCHAR* file = _T("..\\Demo\\exc9_1.xml"); //无标题栏
		//const TCHAR* file = _T("..\\Demo\\exc9_2.xml"); //标题栏在顶部,只有在顶部时，双击标题栏才自动最大化！！！
		//const TCHAR* file = _T("..\\Demo\\exc9_3.xml");   //标题栏在底部
		//const TCHAR* file = _T("..\\Demo\\exc9_4.xml");   //标题栏在中间
		//const TCHAR* file = _T("..\\Demo\\exc9_5.xml");   //标题栏-最小化
		const TCHAR* file = _T("..\\Demo\\exc9_6.xml");   //标题栏-最小、最大、关闭
		//const TCHAR* file = _T("..\\Demo\\exc9_7.xml");   //标题栏-按钮位置自定义
		
		return file;
	}
	virtual CDuiString GetSkinFolder() {
		return _T("");
	}
};

