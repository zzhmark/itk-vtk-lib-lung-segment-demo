
// 11317115MIPCourseDesignDoc.h: C11317115MIPCourseDesignDoc 类的接口
//


#pragma once

#include "11317115MIPCourseDesign.h"

class C11317115MIPCourseDesignDoc : public CDocument
{
protected: // 仅从序列化创建
	C11317115MIPCourseDesignDoc() noexcept;
	DECLARE_DYNCREATE(C11317115MIPCourseDesignDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~C11317115MIPCourseDesignDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileOpen();
	DicomReader::Pointer m_pDicomReader;
	Itk2VtkFilter::Pointer m_pImageInterface;
	afx_msg void OnSegment();
	afx_msg void OnRestore();
	afx_msg void OnConnectSegment();
	afx_msg void OnNbConThr();
	afx_msg void OnConfGrow();
	afx_msg void OnWatershed();
	afx_msg void OnFastMarch();
	afx_msg void OnShapeDetect();
	afx_msg void OnGeoActCont();
};
