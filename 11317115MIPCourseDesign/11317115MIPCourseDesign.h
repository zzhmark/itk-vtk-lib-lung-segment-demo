
// 11317115MIPCourseDesign.h: 11317115MIPCourseDesign 应用程序的主头文件
//
#pragma once

// vtk include
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType)
#include <vtkRenderWindowInteractor.h>
#include <vtkImageViewer2.h>
#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkActor2D.h>
#include <vtkInteractorStyleImage.h>
#include <vtkTextMapper.h>
#include <sstream>
#include <vtkObjectFactory.h>
#include <vtkSetGet.h>
#include <vtkRenderer.h>
#include <vtkTextProperty.h>
#include <vtkCallbackCommand.h>
#include <vtkImageProperty.h>

// itk include
#include <itkGDCMImageIO.h>
#include <itkImageToVTKImageFilter.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkImageSeriesReader.h>
#include <itkImageSeriesWriter.h>
#include <itkGDCMSeriesFileNames.h>
#include <itkGDCMImageIOFactory.h>
#include <itkExtractImageFilter.h>
#include <itkVTKImageToImageFilter.h>
#include <itkBinaryThresholdImageFilter.h>
#include <itkImageToImageFilter.h>
#include <itkMinimumMaximumImageCalculator.h>
#include <itkConnectedThresholdImageFilter.h>
#include <itkCurvatureFlowImageFilter.h>
#include <itkCastImageFilter.h>
#include <itkNeighborhoodConnectedImageFilter.h>
#include <itkConfidenceConnectedImageFilter.h>
#include <itkWatershedImageFilter.h>
#include <itkGradientAnisotropicDiffusionImageFilter.h>
#include <itkGradientMagnitudeImageFilter.h>
#include <itkCurvatureAnisotropicDiffusionImageFilter.h>
#include <itkGradientMagnitudeRecursiveGaussianImageFilter.h>
#include <itkSigmoidImageFilter.h>
#include <itkFastMarchingImageFilter.h>
#include <itkShapeDetectionLevelSetImageFilter.h>
#include <itkDanielssonDistanceMapImageFilter.h>
#include <itkGeodesicActiveContourLevelSetImageFilter.h>


// define my types
typedef itk::Image<short, 3> Itk3D;
typedef itk::ImageSeriesReader<Itk3D> DicomReader;
typedef itk::ImageToVTKImageFilter<Itk3D> Itk2VtkFilter;

// macro
#define MY_INIT_VIEWER (1)
#define MY_UPDATE_VIEWER (2)

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号

// C11317115MIPCourseDesignApp:
// 有关此类的实现，请参阅 11317115MIPCourseDesign.cpp
//

class C11317115MIPCourseDesignApp : public CWinApp
{
public:
	C11317115MIPCourseDesignApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C11317115MIPCourseDesignApp theApp;
