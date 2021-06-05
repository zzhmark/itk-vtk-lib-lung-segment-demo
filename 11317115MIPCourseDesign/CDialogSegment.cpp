// CDialogSegment.cpp: 实现文件
//

#include "pch.h"
#include "11317115MIPCourseDesign.h"
#include "CDialogSegment.h"
#include "afxdialogex.h"


// CDialogSegment 对话框

IMPLEMENT_DYNAMIC(CDialogSegment, CDialogEx)

CDialogSegment::CDialogSegment(int lower, int upper, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SEGMENT, pParent), lower(lower), upper(upper)
	, m_editLower(0)
	, m_editHigher(0)
{
	
}

CDialogSegment::~CDialogSegment()
{
}

void CDialogSegment::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_sliderLow);
	DDX_Control(pDX, IDC_SLIDER2, m_sliderHigh);
	DDX_Control(pDX, IDC_EDIT1, m_editLow);
	DDX_Control(pDX, IDC_EDIT2, m_editHigh);
	DDX_Text(pDX, IDC_EDIT1, m_editLower);
	DDX_Text(pDX, IDC_EDIT2, m_editHigher);
	DDV_MinMaxInt(pDX, m_editLower, lower, upper);
	DDV_MinMaxInt(pDX, m_editHigher, lower, upper);
}


BEGIN_MESSAGE_MAP(CDialogSegment, CDialogEx)
	
	ON_WM_VSCROLL()
	ON_EN_CHANGE(IDC_EDIT1, &CDialogSegment::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CDialogSegment::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CDialogSegment 消息处理程序


BOOL CDialogSegment::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_sliderLow.SetBuddy(GetDlgItem(IDC_EDIT1));
	m_sliderHigh.SetBuddy(GetDlgItem(IDC_EDIT2));

	m_sliderHigh.SetRange(lower, upper);
	m_sliderLow.SetRange(lower, upper);
	m_sliderHigh.SetPos(lower);
	m_sliderLow.SetPos(upper);
	
	SetDlgItemInt(IDC_EDIT1, lower);
	SetDlgItemInt(IDC_EDIT2, upper);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}



void CDialogSegment::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (pScrollBar)
	{
		CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
		if (pSlider->GetDlgCtrlID() == IDC_SLIDER1)
		{
			SetDlgItemInt(IDC_EDIT1, GetLower());
		}

		if (pSlider->GetDlgCtrlID() == IDC_SLIDER2)
		{
			SetDlgItemInt(IDC_EDIT2, GetUpper());
		}
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


int CDialogSegment::GetUpper()
{
	// TODO: 在此处添加实现代码.
	return upper + lower - m_sliderHigh.GetPos();
}


int CDialogSegment::GetLower()
{
	// TODO: 在此处添加实现代码.
	return upper + lower - m_sliderLow.GetPos();
}


void CDialogSegment::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_sliderLow.SetPos(upper + lower - m_editLower);
}


void CDialogSegment::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_sliderHigh.SetPos(upper + lower - m_editHigher);
}
