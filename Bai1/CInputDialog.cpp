// CInputDialog.cpp : implementation file
//

#include "pch.h"
#include "Bai1.h"
#include "afxdialogex.h"
#include "CInputDialog.h"


// CInputDialog dialog

IMPLEMENT_DYNAMIC(CInputDialog, CDialogEx) 
CInputDialog::CInputDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INPUT_DIALOG, pParent)
{

}

CInputDialog::~CInputDialog()
{
}

void CInputDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GIOITINH, m_cbbSex);
	DDX_Control(pDX, IDC_BUTTON1, m_btOK);
	DDX_Control(pDX, IDC_NGAYSINH, m_dtcTime);
}
BOOL CInputDialog::OnInitDialog()
{
	CDialog::OnInitDialog(); 
	m_cbbSex.AddString(_T("Nam")); 
	m_cbbSex.AddString(_T("Nữ"));


	return TRUE; 

}
void CInputDialog::OnBnClicked()
{
	CString HoTen, QueQuan, Account, TruongHoc, SoDienThoai, NgaySinh, GioiTinh;
	GetDlgItem(IDC_HOTEN)->GetWindowTextW(HoTen);
	GetDlgItem(IDC_ACCOUNT)->GetWindowTextW(Account);
	GetDlgItem(IDC_QUEQUAN)->GetWindowTextW(QueQuan);
	GetDlgItem(IDC_TRUONGHOC)->GetWindowTextW(TruongHoc);
	GetDlgItem(IDC_SODIENTHOAI)->GetWindowTextW(SoDienThoai);
	GetDlgItem(IDC_GIOITINH)->GetWindowTextW(GioiTinh);
	int ngaySinh; 
	COleDateTime date; 
	m_dtcTime.GetTime(date); 
	SoDienThoai.Format(_T("%02d/%02d/%04d"), date.GetDay(), date.GetMonth(), date.GetYear()); 
	if (NgaySinh == _T("Nam"))
		ngaySinh = 1;
	else
		ngaySinh = 0; 
	CString noti = _T("");
	if (Account.IsEmpty())
	{
		noti += _T("Account, ");
	}

	if (QueQuan.IsEmpty())
	{
		noti += _T("QueQuan, ");

	}

	if (HoTen.IsEmpty())
	{
		noti += _T("HoTen, ");
	}

	if (SoDienThoai.IsEmpty())
	{
		noti += _T("SoDienThoai ");
	}
	noti += _T("không được bỏ trống!");
	if (noti != _T("không được bỏ trống!")) {
		AfxMessageBox(noti); 
	} else if (!(noti = CheckNumberPhone(SoDienThoai)).IsEmpty())
	{
		AfxMessageBox(noti); 
	}
	else
	{
		CDialog::OnOK(); 
	}


}

CString CInputDialog::CheckNumberPhone(CString SoDienThoai)
{
	if (SoDienThoai.GetLength() != 10 && SoDienThoai.GetLength() != 11)
	{
		return _T("Chiều dài số điện thoại không hợp lệ"); 
	}

	std::vector<CString> vec = { _T("0"), _T("84"), _T("+84")};
	bool check = false; 
	for (int i = 0; i <= 2; i++) 
	{
		if (vec[i] == SoDienThoai.Mid(0, i + 1))
			check = true;
	}
	if (!check) return _T("Sai định dạng số điện thoại");
	CString tmp = SoDienThoai.Mid(1); 
	for (int i = 0; i < tmp.GetLength(); i++)
	{
		if (!_istdigit(tmp[i]) )
			return _T("Số điện thoại chứa kí tự không hợp lệ");
	}
	return _T("");
}


BEGIN_MESSAGE_MAP(CInputDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CInputDialog::OnBnClicked) 
END_MESSAGE_MAP()


// CInputDialog message handlers
