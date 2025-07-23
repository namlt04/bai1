
// Bai1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Bai1.h"
#include "Bai1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBai1Dlg dialog



CBai1Dlg::CBai1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BAI1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBai1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBai1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(1102,  &CBai1Dlg::OnAddButtonClicked)

	ON_BN_CLICKED(1103,  &CBai1Dlg::OnAddButtonClicked)
	ON_BN_CLICKED(1104,  &CBai1Dlg::OnAddButtonClicked)
END_MESSAGE_MAP()


// CBai1Dlg message handlers

BOOL CBai1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	
	this->SetWindowPos(NULL, 0, 0, 800, 600, SWP_NOMOVE | SWP_NOZORDER); 
	
	CRect rClient; 
	GetClientRect(&rClient); 
	UINT height = rClient.Height(); 
	UINT width = rClient.Width(); 
	m_font.CreateFont(
		height / 25, 
		0, 
		0, 
		0, 
		FW_NORMAL, 
		FALSE, 
		FALSE,
		FALSE,
		DEFAULT_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_DONTCARE, 
		_T("Segoe UI")
	); 
	m_listCtrl.Create(WS_CHILD | WS_VISIBLE |LVS_REPORT, CRect(0, 0, rClient.Width(), rClient.Height() - 150), this, 1101);
	m_listCtrl.SetFont(&m_font); 
	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_listCtrl.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 50); 

	m_listCtrl.InsertColumn(1, _T("Account"), LVCFMT_CENTER, 100); 
	m_listCtrl.InsertColumn(2, _T("HoTen"), LVCFMT_CENTER, 100);
	m_listCtrl.InsertColumn(3, _T("QueQuan"), LVCFMT_CENTER, 100);
	m_listCtrl.InsertColumn(4, _T("NgaySinh"), LVCFMT_CENTER, 100);
	m_listCtrl.InsertColumn(5, _T("NgaySinh"), LVCFMT_CENTER, 100);
	m_listCtrl.InsertColumn(6, _T("GioiTinh"), LVCFMT_CENTER, 100);
	m_listCtrl.InsertColumn(7, _T("TruongHoc"), LVCFMT_CENTER, 100);
	m_listCtrl.InsertColumn(8, _T("SoDienThoai"), LVCFMT_CENTER, 100);


	//listCtrl.InsertItem(_T(""), )
	int row0 = m_listCtrl.InsertItem(0, _T("1"));

	m_listCtrl.SetItemText(row0, 1, _T("Nam")); 
	m_listCtrl.SetItemText(row0, 2, _T("19")); 

int row1 = m_listCtrl.InsertItem(0, _T("2"));

	m_listCtrl.SetItemText(row1, 1, _T("Nam")); 
	m_listCtrl.SetItemText(row1, 2, _T("19")); 

int row2 = m_listCtrl.InsertItem(0, _T("3"));

	m_listCtrl.SetItemText(row2, 1, _T("Nam")); 
	m_listCtrl.SetItemText(row2, 2, _T("19")); 


	m_addButton.Create(_T("Them"), WS_CHILD | WS_VISIBLE, CRect(0, rClient.Height() - 100, rClient.Width() / 3, rClient.Height()), this, 1102); 
	m_editButton.Create(_T("Sua"), WS_CHILD | WS_VISIBLE, CRect(rClient.Width() / 3, rClient.Height() - 100,2 * rClient.Width() / 3, rClient.Height()), this, 1103);
	m_removeButton.Create(_T("Xoa"), WS_CHILD | WS_VISIBLE, CRect(2 * rClient.Width() / 3, rClient.Height() - 100, rClient.Width(), rClient.Height()), this, 1104);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBai1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBai1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBai1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CBai1Dlg::OnAddButtonClicked()
{

	//AfxMessageBox(_T("Da click vao Add"));
	int row = m_listCtrl.InsertItem(0, _T("0x112"));
	m_listCtrl.SetItemText(row, 1, _T("column_1"));
	m_listCtrl.SetItemText(row, 2, _T("column_2"));
	m_listCtrl.SetItemText(row, 3, _T("column_3"));
	m_listCtrl.SetItemText(row, 4, _T("column_4"));
	m_listCtrl.SetItemText(row, 5, _T("column_5"));
	m_listCtrl.SetItemText(row, 6, _T("column_6"));
	m_listCtrl.SetItemText(row, 7, _T("column_7"));
	m_listCtrl.SetItemText(row, 8, _T("column_8"));
}
void CBai1Dlg::OnEditButtonClicked()
{
	AfxMessageBox(_T("Da click vao Edit"));

}
void CBai1Dlg::OnRemoveButtonClicked()
{

	AfxMessageBox(_T("Da click vao Remove"));
}
