#pragma once
#include "afxdialogex.h"


// CInputDialog dialog

class CInputDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDialog)

public:
	CInputDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CInputDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUT_DIALOG };
#endif

protected:
	CString CheckNumberPhone(CString SoDienThoai);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClicked();
	DECLARE_MESSAGE_MAP()
	CComboBox m_cbbSex;
	CButton m_btOK;
	CDateTimeCtrl m_dtcTime;
};
