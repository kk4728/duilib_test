#pragma once

#include "dui_base.h"

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const {
		return _T("DUIMainFrame");
	}
	virtual CDuiString GetSkinFile() {
		return _T("..\\demo\\duilib.xml");
	}
	virtual CDuiString GetSkinFolder() {
		return _T("");
	}
};