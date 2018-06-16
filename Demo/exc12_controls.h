#pragma  once


#include "dui_base.h"

class CDuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR    GetWindowClassName() const   {   return _T("DUIMainFrame");  }
	virtual CDuiString GetSkinFile()                {   
		return _T("..\\Demo\\exc12_controls_1.xml");    
		//return _T("..\\Demo\\exc12_controls_2.xml"); 
	}
	virtual CDuiString GetSkinFolder()              {   return _T("");  }
};

