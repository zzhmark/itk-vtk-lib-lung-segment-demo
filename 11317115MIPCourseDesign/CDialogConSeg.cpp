// CDialogConSeg.cpp: 实现文件
//

#include "pch.h"
#include "11317115MIPCourseDesign.h"
#include "CDialogConSeg.h"
#include "afxdialogex.h"


// CDialogConSeg 对话框

IMPLEMENT_DYNAMIC(CDialogConSeg, CDialogEx)

CDialogConSeg::CDialogConSeg(int low, int high, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CON_SEG, pParent)
	, m_editBinLow(0)
	, m_editBinHigh(0)
	, m_editGrowLow(0)
	, m_editGrowHigh(0)
	, low(low)
	, high(high)
{
}

CDialogConSeg::~CDialogConSeg()
{
}

void CDialogConSeg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_binLowSlider);
	DDX_Control(pDX, IDC_SLIDER2, m_binHighSlider);
	DDX_Control(pDX, IDC_SLIDER3, m_growLowSlider);
	DDX_Control(pDX, IDC_SLIDER4, m_growHighSlider);
	DDX_Text(pDX, IDC_EDIT1, m_editBinLow);
	DDV_MinMaxInt(pDX, m_editBinLow, low, high);
	DDX_Text(pDX, IDC_EDIT2, m_editBinHigh);
	DDV_MinMaxInt(pDX, m_editBinHigh, low, high);
	DDX_Text(pDX, IDC_EDIT3, m_editGrowLow);
	DDV_MinMaxInt(pDX, m_editGrowLow, low, high);
	DDX_Text(pDX, IDC_EDIT4, m_editGrowHigh);
	DDV_MinMaxInt(pDX, m_editGrowHigh, low, high);
}


BEGIN_MESSAGE_MAP(CDialogConSeg, CDialogEx)
	ON_WM_VSCROLL()
	ON_EN_CHANGE(IDC_EDIT1, &CDialogConSeg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CDialogConSeg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CDialogConSeg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CDialogConSeg::OnEnChangeEdit4)
END_MESSAGE_MAP()


// CDialogConSeg 消息处理程序


BOOL CDialogConSeg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_binLowSlider.SetRange(low, high);
	m_binHighSlider.SetRange(low, high);
	m_growLowSlider.SetRange(low, high);
	m_growHighSlider.SetRange(low, high);
	m_binLowSlider.SetPos(low);
	m_binHighSlider.SetPos(high);
	m_growLowSlider.SetPos(low);
	m_growHighSlider.SetPos(high);

	SetDlgItemInt(IDC_EDIT1, low);
	SetDlgItemInt(IDC_EDIT2, high);
	SetDlgItemInt(IDC_EDIT3, low);
	SetDlgItemInt(IDC_EDIT4, high);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogConSeg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (pScrollBar)
	{
		CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
		if (pSlider->GetDlgCtrlID() == IDC_SLIDER1)
		{
			SetDlgItemInt(IDC_EDIT1, GetBinLower());
		}

		if (pSlider->GetDlgCtrlID() == IDC_SLIDER2)
		{
			SetDlgItemInt(IDC_EDIT2, GetBinUpper());
		}
		if (pSlider->GetDlgCtrlID() == IDC_SLIDER3)
		{
			SetDlgItemInt(IDC_EDIT3, GetGrowLower());
		}

		if (pSlider->GetDlgCtrlID() == IDC_SLIDER4)
		{
			SetDlgItemInt(IDC_EDIT4, GetGrowUpper());
		}
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


int CDialogConSeg::GetBinLower()
{
	// TODO: 在此处添加实现代码.
	return high + low - m_binLowSlider.GetPos();
}


int CDialogConSeg::GetBinUpper()
{
	// TODO: 在此处添加实现代码.
	return high + low - m_binHighSlider.GetPos();
}


int CDialogConSeg::GetGrowLower()
{
	// TODO: 在此处添加实现代码.
	return high + low - m_growLowSlider.GetPos();
}


int CDialogConSeg::GetGrowUpper()
{
	// TODO: 在此处添加实现代码.
	return high + low - m_growHighSlider.GetPos();
}


void CDialogConSeg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_binLowSlider.SetPos(high + low - m_editBinLow);
}


void CDialogConSeg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_binHighSlider.SetPos(high + low - m_editBinHigh);
}


void CDialogConSeg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_growLowSlider.SetPos(high + low - m_editGrowLow);
}


void CDialogConSeg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_growHighSlider.SetPos(high + low - m_editGrowHigh);
}
