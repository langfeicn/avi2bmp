// avi2bmp.h : main header file for the AVI2BMP application
//

#if !defined(AFX_AVI2BMP_H__6019215E_2A80_4AB9_AC27_DB90424C91A7__INCLUDED_)
#define AFX_AVI2BMP_H__6019215E_2A80_4AB9_AC27_DB90424C91A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAvi2bmpApp:
// See avi2bmp.cpp for the implementation of this class
//

class CAvi2bmpApp : public CWinApp
{
public:
	CAvi2bmpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAvi2bmpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAvi2bmpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVI2BMP_H__6019215E_2A80_4AB9_AC27_DB90424C91A7__INCLUDED_)
