// lottery.h : main header file for the LOTTERY application
//

#if !defined(AFX_LOTTERY_H__24BBA792_A457_4507_AC9C_4ADCDE63C873__INCLUDED_)
#define AFX_LOTTERY_H__24BBA792_A457_4507_AC9C_4ADCDE63C873__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLotteryApp:
// See lottery.cpp for the implementation of this class
//

class CLotteryApp : public CWinApp
{
public:
	CLotteryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLotteryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLotteryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOTTERY_H__24BBA792_A457_4507_AC9C_4ADCDE63C873__INCLUDED_)
