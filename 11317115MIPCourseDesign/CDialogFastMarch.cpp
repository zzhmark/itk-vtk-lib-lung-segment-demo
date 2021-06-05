// CDialogFastMarch.cpp: 实现文件
//

#include "pch.h"
#include "11317115MIPCourseDesign.h"
#include "CDialogFastMarch.h"
#include "afxdialogex.h"


// CDialogFastMarch 对话框

IMPLEMENT_DYNAMIC(CDialogFastMarch, CDialogEx)

CDialogFastMarch::CDialogFastMarch(int low, int high, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_FAST_MARCH, pParent)
	, m_editBinLow(0)
	, m_editBinHigh(0)
	, m_editTimeLow(0)
	, m_editTimeHigh(0)
	, m_sigma(0)
	, m_alpha(0)
	, m_beta(0), low(low), high(high)
	, m_dConduct(0)
	, m_dIteration(0)
{
}

CDialogFastMarch::~CDialogFastMarch()
{
}

void CDialogFastMarch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editBinLow);
	DDX_Text(pDX, IDC_EDIT2, m_editBinHigh);
	DDX_Text(pDX, IDC_EDIT3, m_editTimeLow);
	DDV_MinMaxDouble(pDX, m_editTimeLow, 0, (high - low)*1.0);
	DDX_Text(pDX, IDC_EDIT4, m_editTimeHigh);
	DDV_MinMaxDouble(pDX, m_editTimeHigh, 0, (high - low)*1.0);
	DDX_Text(pDX, IDC_EDIT5, m_sigma);
	DDV_MinMaxDouble(pDX, m_sigma, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT6, m_alpha);
	DDX_Text(pDX, IDC_EDIT7, m_beta);
	DDX_Control(pDX, IDC_SLIDER1, m_binLowSlider);
	DDX_Control(pDX, IDC_SLIDER2, m_binHighSlider);
	DDX_Control(pDX, IDC_SLIDER3, m_timeLowSlider);
	DDX_Control(pDX, IDC_SLIDER4, m_timeHighSlider);
	DDX_Text(pDX, IDC_EDIT8, m_dConduct);
	DDX_Text(pDX, IDC_EDIT9, m_dIteration);
	DDV_MinMaxInt(pDX, m_dIteration, 1, INT_MAX);
}


BEGIN_MESSAGE_MAP(CDialogFastMarch, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CDialogFastMarch::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CDialogFastMarch::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CDialogFastMarch::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CDialogFastMarch::OnEnChangeEdit4)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CDialogFastMarch 消息处理程序


void CDialogFastMarch::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_binLowSlider.SetPos(high + low - m_editBinLow);
}


void CDialogFastMarch::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_binHighSlider.SetPos(high + low - m_editBinHigh);
}


void CDialogFastMarch::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_timeLowSlider.SetPos(high - low - m_editTimeLow);
}


void CDialogFastMarch::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_timeHighSlider.SetPos(high - low - m_editTimeHigh);
}


BOOL CDialogFastMarch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	SetDlgItemInt(IDC_EDIT9, 10);
	m_binLowSlider.SetRange(low, high);
	m_binHighSlider.SetRange(low, high);
	m_timeLowSlider.SetRange(0, high - low);
	m_timeHighSlider.SetRange(0, high - low);
	m_binLowSlider.SetPos(low);
	m_binHighSlider.SetPos(high);
	m_timeLowSlider.SetPos(0);
	m_timeHighSlider.SetPos(100);

	SetDlgItemInt(IDC_EDIT1, low);
	SetDlgItemInt(IDC_EDIT2, high);
	SetDlgItemText(IDC_EDIT3, "0.0");
	SetDlgItemText(IDC_EDIT4, "100.0");
	SetDlgItemText(IDC_EDIT5, "1.0");
	SetDlgItemText(IDC_EDIT6, "-0.5");
	SetDlgItemText(IDC_EDIT7, "3.0");
	SetDlgItemText(IDC_EDIT8, "9.0");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogFastMarch::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
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
			SetDlgItemInt(IDC_EDIT2, GetBinHigher());
		}
		if (pSlider->GetDlgCtrlID() == IDC_SLIDER3 && std::abs(m_editTimeLow - GetTimeLower()) >= 1)
		{
			SetDlgItemInt(IDC_EDIT3, GetTimeLower());
		}

		if (pSlider->GetDlgCtrlID() == IDC_SLIDER4 && std::abs(m_editTimeHigh - GetTimeHigher()) >= 1)
		{
			SetDlgItemInt(IDC_EDIT4, GetTimeHigher());
		}
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


int CDialogFastMarch::GetBinLower()
{
	// TODO: 在此处添加实现代码.
	return high + low - m_binLowSlider.GetPos();
}


int CDialogFastMarch::GetBinHigher()
{
	// TODO: 在此处添加实现代码.
	return high + low - m_binHighSlider.GetPos();
}


int CDialogFastMarch::GetTimeLower()
{
	// TODO: 在此处添加实现代码.
	return high - low - m_timeLowSlider.GetPos();
}


int CDialogFastMarch::GetTimeHigher()
{
	// TODO: 在此处添加实现代码.
	return high - low - m_timeHighSlider.GetPos();
}
