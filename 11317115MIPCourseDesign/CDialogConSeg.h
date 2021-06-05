#pragma once


// CDialogConSeg 对话框

class CDialogConSeg : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogConSeg)

public:
	CDialogConSeg(int low, int high, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogConSeg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CON_SEG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_binLowSlider;
	CSliderCtrl m_binHighSlider;
	CSliderCtrl m_growLowSlider;
	CSliderCtrl m_growHighSlider;
	int m_editBinLow;
	int m_editBinHigh;
	int m_editGrowLow;
	int m_editGrowHigh;
	int low;
	int high;
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int GetBinLower();
	int GetBinUpper();
	int GetGrowLower();
	int GetGrowUpper();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
};
