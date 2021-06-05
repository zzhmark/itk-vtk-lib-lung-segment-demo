#pragma once


// CDialogConf 对话框

class CDialogConf : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogConf)

public:
	CDialogConf(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogConf();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CONF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_multi;
	int m_epoch;
	virtual BOOL OnInitDialog();
};
