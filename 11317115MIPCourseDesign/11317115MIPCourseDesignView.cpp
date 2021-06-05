
// 11317115MIPCourseDesignView.cpp: C11317115MIPCourseDesignView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "11317115MIPCourseDesign.h"
#endif

#include "11317115MIPCourseDesignDoc.h"
#include "11317115MIPCourseDesignView.h"
#include "InteractorStyleFor2DSlices.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C11317115MIPCourseDesignView

IMPLEMENT_DYNCREATE(C11317115MIPCourseDesignView, CView)

BEGIN_MESSAGE_MAP(C11317115MIPCourseDesignView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// C11317115MIPCourseDesignView 构造/析构

C11317115MIPCourseDesignView::C11317115MIPCourseDesignView() noexcept
{
	// TODO: 在此处添加构造代码
}

C11317115MIPCourseDesignView::~C11317115MIPCourseDesignView()
{
}

BOOL C11317115MIPCourseDesignView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C11317115MIPCourseDesignView 绘图

void C11317115MIPCourseDesignView::OnDraw(CDC* /*pDC*/)
{
	C11317115MIPCourseDesignDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C11317115MIPCourseDesignView 诊断

#ifdef _DEBUG
void C11317115MIPCourseDesignView::AssertValid() const
{
	CView::AssertValid();
}

void C11317115MIPCourseDesignView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C11317115MIPCourseDesignDoc* C11317115MIPCourseDesignView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C11317115MIPCourseDesignDoc)));
	return (C11317115MIPCourseDesignDoc*)m_pDocument;
}
#endif //_DEBUG


// C11317115MIPCourseDesignView 消息处理程序

void ResetWindow(vtkObject* caller, unsigned long eid, void* clientdata, void* calldata)
{
	auto t = static_cast<InteractorStyleFor2DSlices*>(caller);
	t->ResetWindowWidthLevel();
}

int C11317115MIPCourseDesignView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	// 窗口设置
	m_pImageViewer->SetParentId(GetSafeHwnd());
	m_pImageViewer->SetupInteractor(m_pRenderWindowInteractor);

	auto myStyle = vtkSmartPointer<InteractorStyleFor2DSlices>::New();
	
	// 图层文字显示
	auto sliceTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	auto scliceTextProperty = vtkSmartPointer<vtkTextProperty>::New();
	auto sliceTextActor = vtkSmartPointer<vtkActor2D>::New();
	scliceTextProperty->SetFontFamilyToTimes();
	scliceTextProperty->SetVerticalJustificationToBottom();
	scliceTextProperty->SetJustificationToLeft();
	sliceTextMapper->SetInput("");
	sliceTextMapper->SetTextProperty(scliceTextProperty);
	sliceTextActor->SetMapper(sliceTextMapper);
	sliceTextActor->SetPosition(15, 10);

	// reset回调
	auto resetCallback = vtkSmartPointer<vtkCallbackCommand>::New();
	resetCallback->SetCallback(ResetWindow);

	// 窗宽窗位显示
	auto windowTextMapper = vtkSmartPointer<vtkTextMapper>::New();
	auto windowTextProperty = vtkSmartPointer<vtkTextProperty>::New();
	auto windowTextActor = vtkSmartPointer<vtkActor2D>::New();
	windowTextProperty->SetFontFamilyToTimes();
	windowTextProperty->SetVerticalJustificationToBottom();
	windowTextProperty->SetJustificationToLeft();
	windowTextMapper->SetInput("");
	windowTextMapper->SetTextProperty(windowTextProperty);
	windowTextActor->SetMapper(windowTextMapper);
	windowTextActor->SetPosition(15, 30);

	// 交互样式定义
	myStyle->SetImageViewer(m_pImageViewer);
	myStyle->SetStatusMapper(sliceTextMapper);
	myStyle->SetWindowMapper(windowTextMapper);
	myStyle->AddObserver(vtkCommand::ResetWindowLevelEvent, resetCallback);
	m_pRenderWindowInteractor->SetInteractorStyle(myStyle);
	m_pImageViewer->GetRenderer()->AddActor2D(sliceTextActor);
	m_pImageViewer->GetRenderer()->AddActor2D(windowTextActor);
	return 0;
}


void C11317115MIPCourseDesignView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	CRect rect;
	GetClientRect(rect);
	m_pImageViewer->SetSize(rect.Width(), rect.Height());
}


void C11317115MIPCourseDesignView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CView::OnUpdate(NULL, lHint, pHint);

	// TODO: 在此添加专用代码和/或调用基类
	if (lHint & MY_INIT_VIEWER)
	{
		C11317115MIPCourseDesignDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		auto imageData = pDoc->m_pImageInterface->GetOutput();
		auto l = imageData->GetScalarRange()[0];
		auto r = imageData->GetScalarRange()[1];
		m_pImageViewer->SetColorWindow(std::abs(r - l));
		m_pImageViewer->SetColorLevel((l + r) / 2.0);
		m_pImageViewer->SetInputData(imageData);
		auto interStyle = static_cast<InteractorStyleFor2DSlices*>(m_pRenderWindowInteractor->GetInteractorStyle());
		interStyle->InitWindowWidthLevel();
		interStyle->InitSlice();
	}
	if (lHint & MY_UPDATE_VIEWER)
	{
		C11317115MIPCourseDesignDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;
		auto imageData = pDoc->m_pImageInterface->GetOutput();
		auto l = imageData->GetScalarRange()[0];
		auto r = imageData->GetScalarRange()[1];
		m_pImageViewer->SetColorWindow(std::abs(r - l));
		m_pImageViewer->SetColorLevel((l + r) / 2.0);
		m_pImageViewer->SetInputData(imageData);
		auto interStyle = static_cast<InteractorStyleFor2DSlices*>(m_pRenderWindowInteractor->GetInteractorStyle());
		interStyle->InitWindowWidthLevel();
		interStyle->InitSlice();
	}
}
