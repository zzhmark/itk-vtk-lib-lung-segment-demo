// CDialogShapeDetect.cpp: 实现文件
//

#include "pch.h"
#include "11317115MIPCourseDesign.h"
#include "CDialogShapeDetect.h"
#include "afxdialogex.h"


// CDialogShapeDetect 对话框

IMPLEMENT_DYNAMIC(CDialogShapeDetect, CDialogEx)

CDialogShapeDetect::CDialogShapeDetect(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SHAPE_DETECT, pParent)
	, prop(1.0)
	, curv(0.05)
	, rmse(0.02)
	, iteration(800)
	, m_dConduct(9.0)
	, m_dIteration(10)
	, m_alpha(-0.5)
	, m_beta(3.0)
	, m_sigma(1.0)
{

}

CDialogShapeDetect::~CDialogShapeDetect()
{
}

void CDialogShapeDetect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, prop);
	DDV_MinMaxDouble(pDX, prop, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT2, curv);
	DDV_MinMaxDouble(pDX, curv, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT3, rmse);
	DDV_MinMaxDouble(pDX, rmse, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT4, iteration);
	DDV_MinMaxInt(pDX, iteration, 1, INT_MAX);
	DDX_Text(pDX, IDC_EDIT8, m_dConduct);
	DDV_MinMaxDouble(pDX, m_dConduct, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT9, m_dIteration);
	DDV_MinMaxInt(pDX, m_dIteration, 1, INT_MAX);
	DDX_Text(pDX, IDC_EDIT6, m_alpha);
	DDX_Text(pDX, IDC_EDIT7, m_beta);
	DDX_Text(pDX, IDC_EDIT5, m_sigma);
	DDV_MinMaxDouble(pDX, m_sigma, 0, DBL_MAX);
}


BEGIN_MESSAGE_MAP(CDialogShapeDetect, CDialogEx)
END_MESSAGE_MAP()


// CDialogShapeDetect 消息处理程序
