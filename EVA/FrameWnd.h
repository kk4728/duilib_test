#pragma once

#include "../include/dui_base.h"


class CDuiFrameWnd : public CXMLWnd
{
public:
	explicit CDuiFrameWnd(LPCTSTR pszXMLPath);

	virtual void InitWindow();

	virtual void Notify(TNotifyUI& msg);

	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
};