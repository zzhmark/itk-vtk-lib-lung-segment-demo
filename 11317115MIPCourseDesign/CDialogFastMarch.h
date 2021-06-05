#pragma once


// CDialogFastMarch 对话框

class CDialogFastMarch : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogFastMarch)

public:
	CDialogFastMarch(int low, int high, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogFastMarch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FAST_MARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	int m_editBinLow;
	int m_editBinHigh;
	double m_editTimeLow;
	double m_editTimeHigh;
	double m_sigma;
	double m_alpha;
	double m_beta;
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int low;
	int high;
	int GetBinLower();
	int GetBinHigher();
	CSliderCtrl m_binLowSlider;
	CSliderCtrl m_binHighSlider;
	CSliderCtrl m_timeLowSlider;
	CSliderCtrl m_timeHighSlider;
	int GetTimeLower();
	int GetTimeHigher();
	double m_dConduct;
	int m_dIteration;
};
