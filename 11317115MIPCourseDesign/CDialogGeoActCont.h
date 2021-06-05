#pragma once


// CDialogGeoActCont 对话框

class CDialogGeoActCont : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogGeoActCont)

public:
	CDialogGeoActCont(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogGeoActCont();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GEO_ACT_CONT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_prop;
	double m_curv;
	double m_adv;
	double rmse;
	int iteration;
	double m_dConduct;
	int m_dIteration;
	double m_alpha;
	double m_beta;
	double m_sigma;
};
