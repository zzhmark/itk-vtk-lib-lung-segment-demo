// CDialogWatershed.cpp: 实现文件
//

#include "pch.h"
#include "11317115MIPCourseDesign.h"
#include "CDialogWatershed.h"
#include "afxdialogex.h"


// CDialogWatershed 对话框

IMPLEMENT_DYNAMIC(CDialogWatershed, CDialogEx)

CDialogWatershed::CDialogWatershed(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_WATERSHED, pParent)
	, m_dLevel(0)
	, m_dThr(0)
	, m_dConduct(0)
	, m_nIteration(0)
{

}

CDialogWatershed::~CDialogWatershed()
{
}

void CDialogWatershed::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_dLevel);
	DDV_MinMaxDouble(pDX, m_dLevel, 0, 1);
	DDX_Text(pDX, IDC_EDIT2, m_dThr);
	DDV_MinMaxDouble(pDX, m_dThr, 0, 1);
	DDX_Text(pDX, IDC_EDIT5, m_dConduct);
	DDV_MinMaxDouble(pDX, m_dConduct, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT6, m_nIteration);
	DDV_MinMaxInt(pDX, m_nIteration, 1, INT_MAX);
}


BEGIN_MESSAGE_MAP(CDialogWatershed, CDialogEx)
END_MESSAGE_MAP()


// CDialogWatershed 消息处理程序


BOOL CDialogWatershed::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	SetDlgItemText(IDC_EDIT1, "0.05");
	SetDlgItemText(IDC_EDIT2, "0.02");
	SetDlgItemText(IDC_EDIT5, "2.0");
	SetDlgItemInt(IDC_EDIT6, 10);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
