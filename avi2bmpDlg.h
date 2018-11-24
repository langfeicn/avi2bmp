// avi2bmpDlg.h : header file
//

#if !defined(AFX_AVI2BMPDLG_H__F6123B92_CD34_45FA_8903_E3AC9E6429A8__INCLUDED_)
#define AFX_AVI2BMPDLG_H__F6123B92_CD34_45FA_8903_E3AC9E6429A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#include<vfw.h>
#pragma comment(lib,"vfw32.lib")



#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAvi2bmpDlg dialog

class CAvi2bmpDlg : public CDialog
{
// Construction
public:
	CAvi2bmpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAvi2bmpDlg)
	enum { IDD = IDD_AVI2BMP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAvi2bmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
	public:
		CString strAVIFileName;
		CString strBmpDir;

		void avitobmp(CString strAVIFileName, CString strBmpDir);



protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAvi2bmpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVI2BMPDLG_H__F6123B92_CD34_45FA_8903_E3AC9E6429A8__INCLUDED_)
