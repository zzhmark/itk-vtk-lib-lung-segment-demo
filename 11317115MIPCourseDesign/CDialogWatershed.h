#pragma once


// CDialogWatershed 对话框

class CDialogWatershed : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogWatershed)

public:
	CDialogWatershed(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogWatershed();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_WATERSHED };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_dLevel;
	double m_dThr;
	double m_dConduct;
	int m_nIteration;
	virtual BOOL OnInitDialog();
};
