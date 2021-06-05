
// 11317115MIPCourseDesignView.h: C11317115MIPCourseDesignView 类的接口
//

#pragma once

#include "11317115MIPCourseDesign.h"

class C11317115MIPCourseDesignView : public CView
{
protected: // 仅从序列化创建
	C11317115MIPCourseDesignView() noexcept;
	DECLARE_DYNCREATE(C11317115MIPCourseDesignView)

// 特性
public:
	C11317115MIPCourseDesignDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C11317115MIPCourseDesignView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	vtkNew<vtkImageViewer2> m_pImageViewer;
	vtkNew<vtkRenderWindowInteractor>  m_pRenderWindowInteractor;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // 11317115MIPCourseDesignView.cpp 中的调试版本
inline C11317115MIPCourseDesignDoc* C11317115MIPCourseDesignView::GetDocument() const
   { return reinterpret_cast<C11317115MIPCourseDesignDoc*>(m_pDocument); }
#endif
