// lotteryDlg.h : header file
//

#if !defined(AFX_LOTTERYDLG_H__6DFACA08_03DF_41A5_B78F_A14086740794__INCLUDED_)
#define AFX_LOTTERYDLG_H__6DFACA08_03DF_41A5_B78F_A14086740794__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLotteryDlg dialog

class CLotteryDlg : public CDialog
{
// Construction
public:
	BOOL DisplayNumbers(CString *DisplayStr, int *Select, int *SpecialN);
	BOOL SelectNumber(int *Select);
	BOOL SelectNumber(int *Select, int *SpecialN);
	BOOL Sorting(int *Sort);
	CStatic *pInfo;
	//int Number[6];

	CButton *pOK;
	CButton *pCancel;
	BOOL CheckValue(int *Select, int i);
	CLotteryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLotteryDlg)
	enum { IDD = IDD_LOTTERY_DIALOG };
	int		m_int_lottery;
	int		m_int_wari;
	int		m_int_N;
	CString	m_strValues;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLotteryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	//int final_N;
	// Generated message map functions
	//{{AFX_MSG(CLotteryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnChangeEdit1();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOTTERYDLG_H__6DFACA08_03DF_41A5_B78F_A14086740794__INCLUDED_)
