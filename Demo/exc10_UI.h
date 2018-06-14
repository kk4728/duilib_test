#pragma once

#include "dui_base.h"

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const {
		return _T("DUIMainFrame");
	}
	virtual CDuiString GetSkinFile() {

		const TCHAR* file = _T("..\\Demo\\exc10_UI.xml");   //标题栏-按钮位置自定义
		
		return file;
	}
	virtual CDuiString GetSkinFolder() {
		return _T("");
	}
};
