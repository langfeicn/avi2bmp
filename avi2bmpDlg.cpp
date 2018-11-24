// avi2bmpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "avi2bmp.h"
#include "avi2bmpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAvi2bmpDlg dialog

CAvi2bmpDlg::CAvi2bmpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAvi2bmpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAvi2bmpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAvi2bmpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAvi2bmpDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAvi2bmpDlg, CDialog)
	//{{AFX_MSG_MAP(CAvi2bmpDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAvi2bmpDlg message handlers

BOOL CAvi2bmpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	strAVIFileName="D:\\avitest\\Capture.avi";
	strBmpDir="D:\\avitest\\bmp";
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAvi2bmpDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAvi2bmpDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAvi2bmpDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAvi2bmpDlg::avitobmp(CString strAVIFileName, CString strBmpDir)
{
  // TODO: 在此添加控件通知处理程序代码
  AVIFileInit();
  PAVIFILE avi;
  int res=AVIFileOpen(&avi, strAVIFileName, OF_READ, NULL);
 int n = GetLastError();
 if (res!=AVIERR_OK)
 {
  //an error occures
  if (avi!=NULL)
   AVIFileRelease(avi);
  return ;
 }
 AVIFILEINFO avi_info;
 AVIFileInfo(avi, &avi_info, sizeof(AVIFILEINFO));
 PAVISTREAM pStream;
 res=AVIFileGetStream(avi, &pStream, streamtypeVIDEO /*video stream*/, 
   0 /*first stream*/);
 if (res!=AVIERR_OK)
 {
  if (pStream!=NULL)
   AVIStreamRelease(pStream);
   AVIFileExit();
  return ;
 }
 //do some task with the stream
 int iNumFrames;
 int iFirstFrame;
 iFirstFrame=AVIStreamStart(pStream);
 if (iFirstFrame==-1)
 {
  //Error getteing the frame inside the stream
  if (pStream!=NULL)
   AVIStreamRelease(pStream);
  AVIFileExit();
  return ;
 }
 iNumFrames=AVIStreamLength(pStream);
 if (iNumFrames==-1)
 {
  //Error getteing the number of frames inside the stream
  if (pStream!=NULL)
   AVIStreamRelease(pStream);
  AVIFileExit();
  return ;
 }
 //getting bitmap from frame
 BITMAPINFOHEADER bih;
 ZeroMemory(&bih, sizeof(BITMAPINFOHEADER));
 bih.biBitCount=24; //24 bit per pixel
 bih.biClrImportant=0;
 bih.biClrUsed = 0;
 bih.biCompression = BI_RGB;
 bih.biPlanes = 1;
 bih.biSize = 40;
 bih.biXPelsPerMeter = 0;
 bih.biYPelsPerMeter = 0;
 //calculate total size of RGBQUAD scanlines (DWORD aligned)
 bih.biSizeImage = (((bih.biWidth * 3) + 3) & 0xFFFC) * bih.biHeight ;
 PGETFRAME pFrame;
 pFrame=AVIStreamGetFrameOpen(pStream, NULL );
 AVISTREAMINFO streaminfo;
 AVIStreamInfo(pStream,&streaminfo,sizeof(AVISTREAMINFO));
 //Get the first frame
 BITMAPINFOHEADER bih2;
 long lsize = sizeof(bih2);
 int index=0;
 for (int i=iFirstFrame; i<iNumFrames; i++)
 {
  index= i-iFirstFrame;
  BYTE* pDIB = (BYTE*) AVIStreamGetFrame(pFrame, index); //
  AVIStreamReadFormat(pStream,index,&bih2,&lsize);
  BITMAPFILEHEADER stFileHdr;
  BYTE* Bits=new BYTE[bih2.biSizeImage];
  AVIStreamRead(pStream,index,1,Bits,bih2.biSizeImage,NULL,NULL);
  //RtlMoveMemory(Bits, pDIB + sizeof(BITMAPINFOHEADER), bih2.biSizeImage);
  bih2.biClrUsed =0;			//这个值决定了每一个像素的位值，可以利用此值二值化图像。
  stFileHdr.bfOffBits=sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
  stFileHdr.bfSize=sizeof(BITMAPFILEHEADER);
  stFileHdr.bfType=0x4d42; 
  CString FileName;
  FileName.Format(_T("Frame-%05d.bmp"), index);
  CString strtemp = strBmpDir;
  strtemp += "\\";
  strtemp += FileName;
  FILE* fp=_tfopen(strtemp ,_T("wb"));//_tfopen
  fwrite(&stFileHdr,1,sizeof(BITMAPFILEHEADER),fp);
  fwrite(&bih2,1,sizeof(BITMAPINFOHEADER),fp);
  int ff = fwrite(Bits,1,bih2.biSizeImage,fp);
  int e = GetLastError();
  fclose(fp);
  /////
  delete Bits;
  //CreateFromPackedDIBPointer(pDIB, index);
 }
 AVIStreamGetFrameClose(pFrame);
 //close the stream after finishing the task
 if (pStream!=NULL)
  AVIStreamRelease(pStream);
 AVIFileExit();
}

void CAvi2bmpDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	avitobmp(strAVIFileName, strBmpDir);
}
