// lotteryDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "lottery.h"
#include "lotteryDlg.h"

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
// CLotteryDlg dialog

CLotteryDlg::CLotteryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLotteryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLotteryDlg)
	m_int_lottery = -1;
	m_int_wari = 0;
	m_int_N = 1;
	m_strValues = _T("");
//	final_N = 38;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLotteryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLotteryDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_int_lottery);
	DDX_Radio(pDX, IDC_RADIO2, m_int_wari);
	DDX_Text(pDX, IDC_EDIT1, m_int_N);
	DDV_MinMaxInt(pDX, m_int_N, 1, 10);
	DDX_Text(pDX, IDC_STATIC_BBS, m_strValues);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLotteryDlg, CDialog)
	//{{AFX_MSG_MAP(CLotteryDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLotteryDlg message handlers

BOOL CLotteryDlg::OnInitDialog()
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

	pInfo   = (CStatic*)GetDlgItem(IDC_STATIC_INFO);
	pOK     = (CButton*)GetDlgItem(IDOK);
	pCancel = (CButton*)GetDlgItem(IDCANCEL);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLotteryDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLotteryDlg::OnPaint() 
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
HCURSOR CLotteryDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLotteryDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}

BOOL CLotteryDlg::Sorting(int *Sort)
{
	int i, temp;
	BOOL SortFlag;

	do{//排一次
		SortFlag = 0;
		for(i=1;i<6;++i)
		{
			if( *(Sort+(i-1)) > *(Sort+i))
			{
                         temp = *(Sort+i);
                *(Sort+i)     = *(Sort+(i-1));
                *(Sort+(i-1)) = temp;
				SortFlag = 1;
			}
		}
	}while(SortFlag);

	return !SortFlag;
}

//大樂透
void CLotteryDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_int_wari=-1;
	UpdateData(FALSE);
}
//威力彩
void CLotteryDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_int_lottery=-1;
	UpdateData(FALSE);
}

BOOL CLotteryDlg::CheckValue(int *Select, int i)
{
	int j;
	for(j=0;j<i;++j)
	{
		if(*(Select-i+j)==*Select)
			return 0;
	}
	return 1;
}

//抽威力彩
BOOL CLotteryDlg::SelectNumber(int *Select, int *SpecialN)
{

	//取出不重覆的六個數字
	int i;
	long Check = 1;
	CString str;
	for(i=0;i<6;++i)
	{
		*(Select+i) = rand()%38+1;
		if(!CheckValue(Select+i,i))
		{
			//str.Format("%d",Select+i );
			//MessageBox (TEXT (str), TEXT ("取亂數"), MB_OK);
			--i;
			continue;
		}
		Check *= *(Select+i);
	}

	if(m_int_wari == 0)
	{
		*SpecialN = rand()%8+1;
		Check *= *SpecialN;
	}
	
	return Check;
}

//抽大樂透
BOOL CLotteryDlg::SelectNumber(int *Select)
{
	//取出不重覆的六個數字
	int i;
	for(i=0;i<6;++i)
	{
		*(Select+i)=rand()%49+1;
		if(!CheckValue(Select+i,i))
		{
			--i;
			continue;
		}
		if(*(Select+i)==0)
			return 0;
	}
	return 1;
}

BOOL CLotteryDlg::DisplayNumbers(CString *DisplayStr, int *Select,int *SpecialN)
{
	int i;
	CString TempStr;
	
	TempStr = *DisplayStr = " ";
	
		for(i=0;i<6;++i)
		{
            TempStr.Format("%2d",*(Select+i));
			 *DisplayStr += i ? ("\t" + TempStr) : (TempStr);
			
// 			if(i==0)
// 				*DisplayStr += TempStr;
// 			else
// 				*DisplayStr += "  " + TempStr;
			
		}
		if(!m_int_wari)
		{
			TempStr.Format("%2d",*SpecialN);
			*DisplayStr += "\t" + TempStr;
		}
		if(i>=5)
			return 1;
		else
			return 0;
		
}

void CLotteryDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
//    m_strValues.Format("%d,%d",m_int_lottery,m_int_wari);

	int j, WariSpecialN;
	CString DisplayString;
	srand(time(NULL));
	int Number[6];

    m_strValues = " ";

	for(j=0;j<6;++j)
	{
		Number[j]=0;
	}
	
	for(j=0;j<m_int_N;++j)
	{
		//取值
		if(!m_int_wari)	
		{
			if(!SelectNumber(Number, &WariSpecialN)) 
				MessageBox (TEXT ("取到了0耶!\n不能中獎了!"), TEXT ("取亂數"), MB_OK);
		}
		else if(!m_int_lottery)	
		{
			if(!SelectNumber(Number))
				MessageBox (TEXT ("取到了0耶!\n不能中獎了!"), TEXT ("取亂數"), MB_OK);
		}

		//排序數字
		if(!Sorting(Number))
			MessageBox (TEXT ("排序失敗!\n怎麼會?"), TEXT ("取亂數"), MB_OK);

		//顯示數字
		if(!DisplayNumbers(&DisplayString,Number, &WariSpecialN))
            MessageBox (TEXT ("無法顯示!\n不能中獎了!〒〒(哭哭)"), TEXT ("取亂數"), MB_OK);

		m_strValues += DisplayString + "\n ";
	}

	pOK    -> ShowWindow(SW_SHOW);
	pCancel-> ShowWindow(SW_HIDE);
	pInfo  -> ShowWindow(SW_SHOW);

    UpdateData(FALSE);
}