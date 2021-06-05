// CDialogGeoActCont.cpp: 实现文件
//

#include "pch.h"
#include "11317115MIPCourseDesign.h"
#include "CDialogGeoActCont.h"
#include "afxdialogex.h"


// CDialogGeoActCont 对话框

IMPLEMENT_DYNAMIC(CDialogGeoActCont, CDialogEx)

CDialogGeoActCont::CDialogGeoActCont(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GEO_ACT_CONT, pParent)
	, m_prop(2.0)
	, m_curv(1.0)
	, m_adv(1.0)
	, rmse(0.02)
	, iteration(800)
	, m_dConduct(9.0)
	, m_dIteration(10)
	, m_alpha(-0.5)
	, m_beta(3.0)
	, m_sigma(1.0)
{

}

CDialogGeoActCont::~CDialogGeoActCont()
{
}

void CDialogGeoActCont::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_prop);
	DDV_MinMaxDouble(pDX, m_prop, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT2, m_curv);
	DDV_MinMaxDouble(pDX, m_curv, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT10, m_adv);
	DDV_MinMaxDouble(pDX, m_adv, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT3, rmse);
	DDV_MinMaxDouble(pDX, rmse, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT4, iteration);
	DDV_MinMaxInt(pDX, iteration, 1, INT_MAX);
	DDX_Text(pDX, IDC_EDIT8, m_dConduct);
	DDV_MinMaxDouble(pDX, m_dConduct, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT9, m_dIteration);
	DDV_MinMaxInt(pDX, m_dIteration, 0, INT_MAX);
	DDX_Text(pDX, IDC_EDIT6, m_alpha);
	DDX_Text(pDX, IDC_EDIT7, m_beta);
	DDX_Text(pDX, IDC_EDIT5, m_sigma);
	DDV_MinMaxDouble(pDX, m_sigma, 0, DBL_MAX);
}


BEGIN_MESSAGE_MAP(CDialogGeoActCont, CDialogEx)
END_MESSAGE_MAP()


// CDialogGeoActCont 消息处理程序
