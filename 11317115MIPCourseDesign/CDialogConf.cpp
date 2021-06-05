// CDialogConf.cpp: 实现文件
//

#include "pch.h"
#include "11317115MIPCourseDesign.h"
#include "CDialogConf.h"
#include "afxdialogex.h"


// CDialogConf 对话框

IMPLEMENT_DYNAMIC(CDialogConf, CDialogEx)

CDialogConf::CDialogConf(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CONF, pParent)
	, m_multi(0)
	, m_epoch(0)
{

}

CDialogConf::~CDialogConf()
{
}

void CDialogConf::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_multi);
	DDX_Text(pDX, IDC_EDIT2, m_epoch);
	DDV_MinMaxInt(pDX, m_epoch, 1, INT_MAX);
	DDV_MinMaxInt(pDX, m_epoch, 1, INT_MAX);
	DDV_MinMaxDouble(pDX, m_multi, 0, DBL_MAX);
}


BEGIN_MESSAGE_MAP(CDialogConf, CDialogEx)
END_MESSAGE_MAP()


// CDialogConf 消息处理程序


BOOL CDialogConf::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	SetDlgItemInt(IDC_EDIT1, 3);
	SetDlgItemInt(IDC_EDIT2, 1);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
