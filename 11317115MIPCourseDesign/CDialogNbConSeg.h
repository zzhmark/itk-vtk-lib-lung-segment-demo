#pragma once


// CDialogNbConSeg 对话框

class CDialogNbConSeg : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogNbConSeg)

public:
	CDialogNbConSeg(int low, int high, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogNbConSeg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NB_CON_SEG };
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
	int m_editGrowLow;
	int m_editGrowHigh;
	CSliderCtrl m_binLowSlider;
	CSliderCtrl m_binHighSlider;
	CSliderCtrl m_growLowSlider;
	CSliderCtrl m_growHighSlider;
	int radius, low, high;
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int GetBinLower();
	int GetBinUpper();
	int GetGrowLower();
	int GetGrowUpper();
};
