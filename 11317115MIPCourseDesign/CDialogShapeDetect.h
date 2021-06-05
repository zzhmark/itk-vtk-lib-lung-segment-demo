#pragma once


// CDialogShapeDetect 对话框

class CDialogShapeDetect : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogShapeDetect)

public:
	CDialogShapeDetect(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogShapeDetect();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SHAPE_DETECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double prop;
	double curv;
	double rmse;
	int iteration;
	double m_dConduct;
	int m_dIteration;
	double m_alpha;
	double m_beta;
	double m_sigma;
};
