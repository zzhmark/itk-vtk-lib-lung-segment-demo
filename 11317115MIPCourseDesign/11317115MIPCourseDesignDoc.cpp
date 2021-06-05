
// 11317115MIPCourseDesignDoc.cpp: C11317115MIPCourseDesignDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "11317115MIPCourseDesign.h"
#endif

#include "11317115MIPCourseDesignDoc.h"
#include <propkey.h>
#include "CDialogSegment.h"
#include "CDialogConSeg.h"
#include "CDialogNbConSeg.h"
#include "CDialogConf.h"
#include "CDialogWatershed.h"
#include "CDialogFastMarch.h"
#include "CDialogShapeDetect.h"
#include "CDialogGeoActCont.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C11317115MIPCourseDesignDoc

IMPLEMENT_DYNCREATE(C11317115MIPCourseDesignDoc, CDocument)

BEGIN_MESSAGE_MAP(C11317115MIPCourseDesignDoc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &C11317115MIPCourseDesignDoc::OnFileOpen)
	ON_COMMAND(ID_SEGMENT, &C11317115MIPCourseDesignDoc::OnSegment)
	ON_COMMAND(ID_RESTORE, &C11317115MIPCourseDesignDoc::OnRestore)
	ON_COMMAND(ID_CONNECT_SEGMENT, &C11317115MIPCourseDesignDoc::OnConnectSegment)
	ON_COMMAND(ID_NB_CON_THR, &C11317115MIPCourseDesignDoc::OnNbConThr)
	ON_COMMAND(ID_CONF_GROW, &C11317115MIPCourseDesignDoc::OnConfGrow)
	ON_COMMAND(ID_WATERSHED, &C11317115MIPCourseDesignDoc::OnWatershed)
	ON_COMMAND(ID_FAST_MARCH, &C11317115MIPCourseDesignDoc::OnFastMarch)
	ON_COMMAND(ID_SHAPE_DETECT, &C11317115MIPCourseDesignDoc::OnShapeDetect)
	ON_COMMAND(ID_GEO_ACT_CONT, &C11317115MIPCourseDesignDoc::OnGeoActCont)
END_MESSAGE_MAP()


// C11317115MIPCourseDesignDoc 构造/析构

C11317115MIPCourseDesignDoc::C11317115MIPCourseDesignDoc() noexcept
{
	// TODO: 在此添加一次性构造代码
	using DicomIO = itk::GDCMImageIO;
	auto dicomIO = DicomIO::New();
	m_pDicomReader = DicomReader::New();
	m_pDicomReader->SetImageIO(dicomIO);
	m_pImageInterface = Itk2VtkFilter::New();
}

C11317115MIPCourseDesignDoc::~C11317115MIPCourseDesignDoc()
{
}

BOOL C11317115MIPCourseDesignDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// C11317115MIPCourseDesignDoc 序列化

void C11317115MIPCourseDesignDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void C11317115MIPCourseDesignDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void C11317115MIPCourseDesignDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void C11317115MIPCourseDesignDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C11317115MIPCourseDesignDoc 诊断

#ifdef _DEBUG
void C11317115MIPCourseDesignDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C11317115MIPCourseDesignDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C11317115MIPCourseDesignDoc 命令


void C11317115MIPCourseDesignDoc::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFolderPickerDialog dlg(NULL, OFN_HIDEREADONLY, NULL);
	if (dlg.DoModal() == IDOK)
	{
		// 用ITK读取DICOM图像数据，转换成VTK
		auto fileNames = itk::GDCMSeriesFileNames::New();
		fileNames->SetUseSeriesDetails(true);
		fileNames->SetInputDirectory( dlg.GetPathName().GetString() );
		m_pDicomReader->SetFileNames( fileNames->GetInputFileNames() );
		m_pDicomReader->ForceOrthogonalDirectionOff();
		m_pDicomReader->Update();
		m_pImageInterface->SetInput(m_pDicomReader->GetOutput());
		m_pImageInterface->Update();
		UpdateAllViews(NULL, MY_INIT_VIEWER);
	}
}


void C11317115MIPCourseDesignDoc::OnSegment()
{
	// TODO: 在此添加命令处理程序代码
	auto itkImage = m_pImageInterface->GetInput();
	if (!itkImage)
		return;
	auto minMax = itk::MinimumMaximumImageCalculator<Itk3D>::New();
	minMax->SetImage(itkImage);
	minMax->Compute();
	CDialogSegment dlg(minMax->GetMinimum(), minMax->GetMaximum());
	if (dlg.DoModal() == IDOK)
	{
		using BinFilter = itk::BinaryThresholdImageFilter<Itk3D, Itk3D>;
		auto bin = BinFilter::New();
		bin->SetInput(itkImage);
		bin->SetOutsideValue(0);
		bin->SetInsideValue(MAXSHORT);
		bin->SetUpperThreshold(dlg.m_editHigher);
		bin->SetLowerThreshold(dlg.m_editLower);
		m_pImageInterface->SetInput(bin->GetOutput());
		m_pImageInterface->Update();
		UpdateAllViews(NULL, MY_UPDATE_VIEWER);
	}
}


void C11317115MIPCourseDesignDoc::OnRestore()
{
	// TODO: 在此添加命令处理程序代码
	if (m_pDicomReader->GetFileNames().size() == 0)
		return;
	m_pImageInterface->SetInput(m_pDicomReader->GetOutput());
	m_pImageInterface->Update();
	UpdateAllViews(NULL, MY_INIT_VIEWER);
}


void C11317115MIPCourseDesignDoc::OnConnectSegment()
{
	// TODO: 在此添加命令处理程序代码
	auto itkImage = m_pImageInterface->GetInput();
	if (!itkImage)
		return;
	auto minMax = itk::MinimumMaximumImageCalculator<Itk3D>::New();
	minMax->SetImage(itkImage);
	minMax->Compute();
	CDialogConSeg dlg(minMax->GetMinimum(), minMax->GetMaximum());
	if (dlg.DoModal() == IDOK)
	{
		// binarize to take seeds
		using BinFilter = itk::BinaryThresholdImageFilter<Itk3D, Itk3D>;
		auto bin = BinFilter::New();
		bin->SetInput(itkImage);
		bin->SetOutsideValue(0);
		bin->SetInsideValue(1);
		bin->SetUpperThreshold(dlg.m_editBinHigh);
		bin->SetLowerThreshold(dlg.m_editBinLow);
		bin->Update();
		auto mask = bin->GetOutput();
		
		// convert short to float type
		using FloatType = itk::Image<float, 3>;
		using Cast2FloatFilter = itk::CastImageFilter<Itk3D, FloatType>;
		auto toFloat = Cast2FloatFilter::New();
		toFloat->SetInput(itkImage);

		// smooth and preserve edge
		using CurvFlowFilter = itk::CurvatureFlowImageFilter<FloatType, FloatType>;
		auto smoothing = CurvFlowFilter::New();
		smoothing->SetInput(toFloat->GetOutput());
		smoothing->SetTimeStep(0.0625);
		smoothing->SetNumberOfIterations(10);

		// convert back to short
		using Cast2ShortFilter = itk::CastImageFilter<FloatType, Itk3D>;
		auto toShort = Cast2ShortFilter::New();
		toShort->SetInput(smoothing->GetOutput());

		// set up connect filter
		using ConnectFilter = itk::ConnectedThresholdImageFilter<Itk3D, Itk3D>;
		auto con = ConnectFilter::New();
		con->SetInput(toShort->GetOutput());
		con->SetUpper(dlg.m_editGrowHigh);
		con->SetLower(dlg.m_editGrowLow);
		con->SetReplaceValue(MAXSHORT);

		// take seeds
		using IteratorType = itk::ImageRegionIterator<Itk3D>;
		IteratorType itBin(mask, mask->GetRequestedRegion());
		itBin.GoToBegin();
		while (!itBin.IsAtEnd())
		{
			if (itBin.Get() > 0)
			{
				con->AddSeed(itBin.GetIndex());
			}
			++itBin;
		}
		m_pImageInterface->SetInput(con->GetOutput());
		m_pImageInterface->Update();
		UpdateAllViews(NULL, MY_UPDATE_VIEWER);
	}
}


void C11317115MIPCourseDesignDoc::OnNbConThr()
{
	// TODO: 在此添加命令处理程序代码
	auto itkImage = m_pImageInterface->GetInput();
	if (!itkImage)
		return;
	auto minMax = itk::MinimumMaximumImageCalculator<Itk3D>::New();
	minMax->SetImage(itkImage);
	minMax->Compute();
	CDialogNbConSeg dlg(minMax->GetMinimum(), minMax->GetMaximum());
	if (dlg.DoModal() == IDOK)
	{
		// binarize to take seeds
		using BinFilter = itk::BinaryThresholdImageFilter<Itk3D, Itk3D>;
		auto bin = BinFilter::New();
		bin->SetInput(itkImage);
		bin->SetOutsideValue(0);
		bin->SetInsideValue(1);
		bin->SetUpperThreshold(dlg.m_editBinHigh);
		bin->SetLowerThreshold(dlg.m_editBinLow);
		bin->Update();
		auto mask = bin->GetOutput();

		// convert short to float type
		using FloatType = itk::Image<float, 3>;
		using Cast2FloatFilter = itk::CastImageFilter<Itk3D, FloatType>;
		auto toFloat = Cast2FloatFilter::New();
		toFloat->SetInput(itkImage);

		// smooth and preserve edge
		using CurvFlowFilter = itk::CurvatureFlowImageFilter<FloatType, FloatType>;
		auto smoothing = CurvFlowFilter::New();
		smoothing->SetInput(toFloat->GetOutput());
		smoothing->SetTimeStep(0.0625);
		smoothing->SetNumberOfIterations(10);

		// convert back to short
		using Cast2ShortFilter = itk::CastImageFilter<FloatType, Itk3D>;
		auto toShort = Cast2ShortFilter::New();
		toShort->SetInput(smoothing->GetOutput());

		// set up connect filter
		using NbConnectFilter = itk::NeighborhoodConnectedImageFilter<Itk3D, Itk3D>;
		auto con = NbConnectFilter::New();
		con->SetInput(toShort->GetOutput());
		con->SetUpper(dlg.m_editGrowHigh);
		con->SetLower(dlg.m_editGrowLow);
		con->SetReplaceValue(MAXSHORT);
		Itk3D::SizeType radius;
		radius[0] = radius[1] = radius[2] = dlg.radius;
		con->SetRadius(radius);

		// take seeds
		using IteratorType = itk::ImageRegionIterator<Itk3D>;
		IteratorType itBin(mask, mask->GetRequestedRegion());
		itBin.GoToBegin();
		while (!itBin.IsAtEnd())
		{
			if (itBin.Get() > 0)
			{
				con->AddSeed(itBin.GetIndex());
			}
			++itBin;
		}
		m_pImageInterface->SetInput(con->GetOutput());
		m_pImageInterface->Update();
		UpdateAllViews(NULL, MY_UPDATE_VIEWER);
	}
}


void C11317115MIPCourseDesignDoc::OnConfGrow()
{
	// TODO: 在此添加命令处理程序代码
	auto itkImage = m_pImageInterface->GetInput();
	if (!itkImage)
		return;
	auto minMax = itk::MinimumMaximumImageCalculator<Itk3D>::New();
	minMax->SetImage(itkImage);
	minMax->Compute();
	CDialogSegment dlg1(minMax->GetMinimum(), minMax->GetMaximum());
	CDialogConf dlg2;
	if (dlg1.DoModal() == IDOK && dlg2.DoModal() == IDOK)
	{
		// binarize to take seeds
		using BinFilter = itk::BinaryThresholdImageFilter<Itk3D, Itk3D>;
		auto bin = BinFilter::New();
		bin->SetInput(itkImage);
		bin->SetOutsideValue(0);
		bin->SetInsideValue(1);
		bin->SetUpperThreshold(dlg1.m_editHigher);
		bin->SetLowerThreshold(dlg1.m_editLower);
		bin->Update();
		auto mask = bin->GetOutput();
		
		// convert short to float type
		using FloatType = itk::Image<float, 3>;
		using Cast2FloatFilter = itk::CastImageFilter<Itk3D, FloatType>;
		auto toFloat = Cast2FloatFilter::New();
		toFloat->SetInput(itkImage);

		// smooth and preserve edge
		using CurvFlowFilter = itk::CurvatureFlowImageFilter<FloatType, FloatType>;
		auto smoothing = CurvFlowFilter::New();
		smoothing->SetInput(toFloat->GetOutput());
		smoothing->SetTimeStep(0.0625);
		smoothing->SetNumberOfIterations(10);

		// convert back to short
		using Cast2ShortFilter = itk::CastImageFilter<FloatType, Itk3D>;
		auto toShort = Cast2ShortFilter::New();
		toShort->SetInput(smoothing->GetOutput());

		// set up connect filter
		using ConfFilter = itk::ConfidenceConnectedImageFilter<Itk3D, Itk3D>;
		auto conf = ConfFilter::New();
		conf->SetInput(toShort->GetOutput());
		conf->SetMultiplier(dlg2.m_multi);
		conf->SetNumberOfIterations(dlg2.m_epoch);
		conf->SetReplaceValue(MAXSHORT);

		// take seeds
		using IteratorType = itk::ImageRegionIterator<Itk3D>;
		IteratorType itBin(mask, mask->GetRequestedRegion());
		itBin.GoToBegin();
		while (!itBin.IsAtEnd())
		{
			if (itBin.Get() > 0)
			{
				conf->AddSeed(itBin.GetIndex());
			}
			++itBin;
		}
		m_pImageInterface->SetInput(conf->GetOutput());
		m_pImageInterface->Update();
		UpdateAllViews(NULL, MY_UPDATE_VIEWER);
	}
}


void C11317115MIPCourseDesignDoc::OnWatershed()
{
	// TODO: 在此添加命令处理程序代码
	auto itkImage = m_pImageInterface->GetInput();
	if (!itkImage)
		return;
	CDialogWatershed dlg;
	if (dlg.DoModal() == IDOK)
	{
		// convert short to float type
		using FloatType = itk::Image<float, 3>;
		using Cast2FloatFilter = itk::CastImageFilter<Itk3D, FloatType>;
		auto toFloat = Cast2FloatFilter::New();
		toFloat->SetInput(itkImage);

		// smooth and preserve edge
		using GMAnisoDiffFilter = itk::GradientAnisotropicDiffusionImageFilter<FloatType, FloatType>;
		auto smoothing = GMAnisoDiffFilter::New();
		smoothing->SetInput(toFloat->GetOutput());
		smoothing->SetConductanceParameter(dlg.m_dConduct);
		smoothing->SetNumberOfIterations(dlg.m_nIteration);
		smoothing->SetTimeStep(0.0625);

		// get gradient magnitude
		using GDmagFilter = itk::GradientMagnitudeImageFilter<FloatType, FloatType>;
		auto gd = GDmagFilter::New();
		gd->SetInput(smoothing->GetOutput());

		// set up connect filter
		using WatershedFilter = itk::WatershedImageFilter<FloatType>;
		auto watershed = WatershedFilter::New();
		watershed->SetInput(gd->GetOutput());
		watershed->SetLevel(dlg.m_dLevel);
		watershed->SetThreshold(dlg.m_dThr);
		
		// convert identifier type to short
		using IdentifierImage = itk::Image<itk::IdentifierType, 3>;
		using Cast2ShortFilter = itk::CastImageFilter<IdentifierImage, Itk3D>;
		auto toShort = Cast2ShortFilter::New();
		toShort->SetInput(watershed->GetOutput());

		m_pImageInterface->SetInput(toShort->GetOutput());
		m_pImageInterface->Update();
		UpdateAllViews(NULL, MY_UPDATE_VIEWER);
	}
}


void C11317115MIPCourseDesignDoc::OnFastMarch()
{
	// TODO: 在此添加命令处理程序代码
	auto itkImage = m_pImageInterface->GetInput();
	if (!itkImage)
		return;
	auto minMax = itk::MinimumMaximumImageCalculator<Itk3D>::New();
	minMax->SetImage(itkImage);
	minMax->Compute();
	auto low = minMax->GetMinimum();
	auto high = minMax->GetMaximum();
	CDialogFastMarch dlg(low, high);
	if (dlg.DoModal() == IDOK)
	{
		// binarize to take seeds
		using BinFilter = itk::BinaryThresholdImageFilter<Itk3D, Itk3D>;
		auto bin = BinFilter::New();
		bin->SetInput(itkImage);
		bin->SetOutsideValue(0);
		bin->SetInsideValue(1);
		bin->SetUpperThreshold(dlg.m_editBinHigh);
		bin->SetLowerThreshold(dlg.m_editBinLow);
		bin->Update();
		auto mask = bin->GetOutput();

		// convert short to float type
		using FloatType = itk::Image<float, 3>;
		using Cast2FloatFilter = itk::CastImageFilter<Itk3D, FloatType>;
		auto toFloat = Cast2FloatFilter::New();
		toFloat->SetInput(itkImage);

		// smooth 
		using CurvAnisotropicFilter = itk::CurvatureAnisotropicDiffusionImageFilter<FloatType, FloatType>;
		auto smoothing = CurvAnisotropicFilter::New();
		smoothing->SetInput(toFloat->GetOutput());
		smoothing->SetConductanceParameter(dlg.m_dConduct);
		smoothing->SetNumberOfIterations(dlg.m_dIteration);
		smoothing->SetTimeStep(0.0625);

		// get gradient magnitude of gauss
		using GDmagGaussFilter = itk::GradientMagnitudeRecursiveGaussianImageFilter<FloatType, FloatType>;
		auto gd = GDmagGaussFilter::New();
		gd->SetInput(smoothing->GetOutput());
		gd->SetSigma(dlg.m_sigma);

		// get sigmoid
		using SigmoidFilter = itk::SigmoidImageFilter<FloatType, FloatType>;
		auto sigmoid = SigmoidFilter::New();
		sigmoid->SetInput(gd->GetOutput());
		sigmoid->SetAlpha(dlg.m_alpha);
		sigmoid->SetBeta(dlg.m_beta);
		sigmoid->SetOutputMinimum(0.0);
		sigmoid->SetOutputMaximum(1.0);

		// fast marching
		using FastMarchingFilter = itk::FastMarchingImageFilter<FloatType, FloatType>;
		auto fm = FastMarchingFilter::New();
		fm->SetInput(sigmoid->GetOutput());
		fm->SetSpeedConstant(1.0);
		fm->SetOutputSize(itkImage->GetLargestPossibleRegion().GetSize());
		fm->SetStoppingValue(dlg.m_editTimeHigh);

		// take seeds
		using NodeContainer = FastMarchingFilter::NodeContainer;
		using NodeType = FastMarchingFilter::NodeType;
		auto seeds = NodeContainer::New();
		seeds->Initialize();
		NodeType node;
		using IteratorType = itk::ImageRegionIterator<Itk3D>;
		IteratorType itBin(mask, mask->GetRequestedRegion());
		itBin.GoToBegin();
		int i = 0;
		while (!itBin.IsAtEnd())
		{
			if (itBin.Get() > 0)
			{
				node.SetValue(0);
				node.SetIndex(itBin.GetIndex());
				seeds->InsertElement(i, node);
			}
			++itBin;
			++i;
		}
		fm->SetTrialPoints(seeds);

		// time threshold
		using TimeFilter = itk::BinaryThresholdImageFilter<FloatType, Itk3D>;
		auto t = TimeFilter::New();
		t->SetInput(fm->GetOutput());
		t->SetLowerThreshold(dlg.m_editTimeLow);
		t->SetUpperThreshold(dlg.m_editTimeHigh);
		t->SetOutsideValue(0);
		t->SetInsideValue(MAXSHORT);

		m_pImageInterface->SetInput(t->GetOutput());
		m_pImageInterface->Update();
		UpdateAllViews(NULL, MY_UPDATE_VIEWER);
	}
}


void C11317115MIPCourseDesignDoc::OnShapeDetect()
{
	// TODO: 在此添加命令处理程序代码
	auto itkImage = m_pImageInterface->GetInput();
	if (!itkImage)
		return;
	CDialogShapeDetect dlg;
	if (dlg.DoModal() == IDOK)
	{
		// convert short to float type
		using FloatType = itk::Image<float, 3>;
		using Cast2FloatFilter = itk::CastImageFilter<Itk3D, FloatType>;
		auto toFloat = Cast2FloatFilter::New();
		toFloat->SetInput(itkImage);

		// smooth 
		using CurvAnisotropicFilter = itk::CurvatureAnisotropicDiffusionImageFilter<FloatType, FloatType>;
		auto smoothing = CurvAnisotropicFilter::New();
		smoothing->SetInput(toFloat->GetOutput());
		smoothing->SetConductanceParameter(dlg.m_dConduct);
		smoothing->SetNumberOfIterations(dlg.m_dIteration);
		smoothing->SetTimeStep(0.0625);

		// get gradient magnitude of gauss
		using GDmagGaussFilter = itk::GradientMagnitudeRecursiveGaussianImageFilter<FloatType, FloatType>;
		auto gd = GDmagGaussFilter::New();
		gd->SetInput(smoothing->GetOutput());
		gd->SetSigma(dlg.m_sigma);

		// get sigmoid
		using SigmoidFilter = itk::SigmoidImageFilter<FloatType, FloatType>;
		auto sigmoid = SigmoidFilter::New();
		sigmoid->SetInput(gd->GetOutput());
		sigmoid->SetAlpha(dlg.m_alpha);
		sigmoid->SetBeta(dlg.m_beta);
		sigmoid->SetOutputMinimum(0.0);
		sigmoid->SetOutputMaximum(1.0);

		// get distance map
		using DistanceMapFilter = itk::DanielssonDistanceMapImageFilter<FloatType, FloatType>;
		auto dist = DistanceMapFilter::New();
		dist->SetInput(sigmoid->GetOutput());

		// shape detection
		using ShapeDetectFilter = itk::ShapeDetectionLevelSetImageFilter<FloatType, FloatType>;
		auto sd = ShapeDetectFilter::New();
		sd->SetInput(dist->GetOutput());
		sd->SetFeatureImage(sigmoid->GetOutput());
		sd->SetPropagationScaling(dlg.prop);
		sd->SetCurvatureScaling(dlg.curv);
		sd->SetMaximumRMSError(dlg.rmse);
		sd->SetNumberOfIterations(dlg.iteration);

		// threshold
		using ThresholdFilter = itk::BinaryThresholdImageFilter<FloatType, Itk3D>;
		auto tf = ThresholdFilter::New();
		tf->SetInput(sd->GetOutput());
		tf->SetLowerThreshold(-DBL_MAX);
		tf->SetUpperThreshold(0.0);
		tf->SetOutsideValue(0);
		tf->SetInsideValue(MAXSHORT);

		m_pImageInterface->SetInput(tf->GetOutput());
		m_pImageInterface->Update();
		UpdateAllViews(NULL, MY_UPDATE_VIEWER);
	}
}


void C11317115MIPCourseDesignDoc::OnGeoActCont()
{
	// TODO: 在此添加命令处理程序代码
	auto itkImage = m_pImageInterface->GetInput();
	if (!itkImage)
		return;
	CDialogGeoActCont dlg;
	if (dlg.DoModal() == IDOK)
	{
		// convert short to float type
		using FloatType = itk::Image<float, 3>;
		using Cast2FloatFilter = itk::CastImageFilter<Itk3D, FloatType>;
		auto toFloat = Cast2FloatFilter::New();
		toFloat->SetInput(itkImage);

		// smooth 
		using CurvAnisotropicFilter = itk::CurvatureAnisotropicDiffusionImageFilter<FloatType, FloatType>;
		auto smoothing = CurvAnisotropicFilter::New();
		smoothing->SetInput(toFloat->GetOutput());
		smoothing->SetConductanceParameter(dlg.m_dConduct);
		smoothing->SetNumberOfIterations(dlg.m_dIteration);
		smoothing->SetTimeStep(0.0625);

		// get gradient magnitude of gauss
		using GDmagGaussFilter = itk::GradientMagnitudeRecursiveGaussianImageFilter<FloatType, FloatType>;
		auto gd = GDmagGaussFilter::New();
		gd->SetInput(smoothing->GetOutput());
		gd->SetSigma(dlg.m_sigma);

		// get sigmoid
		using SigmoidFilter = itk::SigmoidImageFilter<FloatType, FloatType>;
		auto sigmoid = SigmoidFilter::New();
		sigmoid->SetInput(gd->GetOutput());
		sigmoid->SetAlpha(dlg.m_alpha);
		sigmoid->SetBeta(dlg.m_beta);
		sigmoid->SetOutputMinimum(0.0);
		sigmoid->SetOutputMaximum(1.0);

		// get distance map
		using DistanceMapFilter = itk::DanielssonDistanceMapImageFilter<FloatType, FloatType>;
		auto dist = DistanceMapFilter::New();
		dist->SetInput(sigmoid->GetOutput());

		// geodesic
		using GeodesicFilter = itk::GeodesicActiveContourLevelSetImageFilter<FloatType, FloatType>;
		auto gdac = GeodesicFilter::New();
		gdac->SetInput(dist->GetOutput());
		gdac->SetFeatureImage(sigmoid->GetOutput());
		gdac->SetPropagationScaling(dlg.m_prop);
		gdac->SetCurvatureScaling(dlg.m_curv);
		gdac->SetAdvectionScaling(dlg.m_adv);
		gdac->SetMaximumRMSError(dlg.rmse);
		gdac->SetNumberOfIterations(dlg.iteration);

		// threshold
		using ThresholdFilter = itk::BinaryThresholdImageFilter<FloatType, Itk3D>;
		auto tf = ThresholdFilter::New();
		tf->SetInput(gdac->GetOutput());
		tf->SetLowerThreshold(-DBL_MAX);
		tf->SetUpperThreshold(0.0);
		tf->SetOutsideValue(0);
		tf->SetInsideValue(MAXSHORT);

		m_pImageInterface->SetInput(tf->GetOutput());
		m_pImageInterface->Update();
		UpdateAllViews(NULL, MY_UPDATE_VIEWER);
	}
}
