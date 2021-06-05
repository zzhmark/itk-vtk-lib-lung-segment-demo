#pragma once

// CDialogSegment 对话框

class CDialogSegment : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogSegment)

public:
	CDialogSegment(int lower, int upper, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogSegment();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEGMENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_sliderLow;
	CSliderCtrl m_sliderHigh;
	int lower, upper;
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CEdit m_editLow;
	CEdit m_editHigh;
	int GetUpper();
	int GetLower();
	int m_editLower;
	int m_editHigher;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
