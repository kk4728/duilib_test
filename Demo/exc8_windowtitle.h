#pragma once

#include "dui_base.h"

/* 以下问题都在XML第二行的 <Window>节点里添加。
1、为什么标题栏不能拖动？
    需要在<Window>节点添加 caption="0,0,0,32"，这里的32是指标题栏的高度
2、怎么让窗口大小可以通过拖拽来调整？
    需要在<Window>节点添加 sizebox="4,4,4,4"， 这里的4是指鼠标移动到边框4个像素的范围内，鼠标就会显示拖拽样式，
	这时就可以调整窗口大小了
 
    下面Alberl来一一解释下XML代码的意思。大部分地方都有明显注释了，重点要解释的就是HorizontalLayout、VerticalLayout
	以及Button的样式了。
    这一节先介绍Button的样式，大家可以看到关闭按钮除了鼠标移上去有不同外观，还有一个提示条。这些都是在这一行代码里
	指定的：
	<Button 
	name="closebtn"		//唯一标识按钮，其他按钮的name不能与其重复
	tooltip="关闭"		//就是那个提示条的文字
	float="true"		//代表按钮的位置是绝对定位，其位置由pos属性指定
	pos="44,5,74,24"	//代表按钮的位置矩阵，分别为矩阵左、上、右、下四个点
	width="28"			//代表按钮图片显示的宽度（这个可以不填，但是由于按钮图片没有做好，
						//如果不填的话，图片会被拉伸有点失真）
	normalimage=" file='SysBtn\CloseNormal.bmp' " //代表正常状态下按钮显示的图片路径
	hotimage=" file='SysBtn\CloseFocus.bmp' "	  //代表鼠标移上去时，按钮显示的图片路径
	pushedimage=" file='SysBtn\CloseFocus.bmp' "  //代表鼠标点击按钮时，按钮显示的图片路径
	/>
3,保存为UTF-8格式（不要使用windows自带的记事本编辑，可以使用UltraEdit、EditPlus等编辑器）】。
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

