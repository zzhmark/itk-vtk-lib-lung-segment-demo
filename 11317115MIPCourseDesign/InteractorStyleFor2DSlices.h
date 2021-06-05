#ifndef MY_INTERACTIONSTYLE_H
#define MY_INTERACTIONSTYLE_H
#include "11317115MIPCourseDesign.h"

class StatusMessage {
public:
	static std::string Format(int slice, int maxSlice) {
		std::stringstream tmp;
		tmp << "Image Slices: " << slice + 1 << "/" << maxSlice + 1;
		return tmp.str();
	}
};

class WindowMessage {
public:
	static std::string Format(int width, int level) {
		std::stringstream tmp;
		tmp << "Window Width: " << width << "   " << "Window Level: " << level;
		return tmp.str();
	}
};

class InteractorStyleFor2DSlices :
	public vtkInteractorStyleImage
{
public:
	static InteractorStyleFor2DSlices* New();
	vtkTypeMacro(InteractorStyleFor2DSlices, vtkInteractorStyleImage);

protected:
	vtkSmartPointer<vtkImageViewer2> m_pImageViewer;
	vtkSmartPointer<vtkTextMapper> m_pStatusMapper;
	vtkSmartPointer<vtkTextMapper> m_pWindowMapper;

public:

	void ResetWindowWidthLevel()
	{
		int ww = CurrentImageProperty->GetColorWindow();
		ww = ww / 256 * m_pImageViewer->GetColorWindow();
		int wl = CurrentImageProperty->GetColorLevel();
		wl = (wl - 127) / 256 * m_pImageViewer->GetColorWindow();
		auto msg = WindowMessage::Format(ww, wl);
		m_pWindowMapper->SetInput(msg.c_str());
		m_pImageViewer->Render();
	}

	void InitWindowWidthLevel()
	{
		m_pWindowMapper->SetInput("Window Width:          Window Level:");
		m_pImageViewer->Render();
	}

	void InitSlice()
	{
		auto msg = StatusMessage::Format(m_pImageViewer->GetSlice(), m_pImageViewer->GetSliceMax());
		m_pStatusMapper->SetInput(msg.c_str());
		m_pImageViewer->Render();
	}

	void SetImageViewer(vtkImageViewer2* imageViewer) {
		m_pImageViewer = imageViewer;
	}

	void SetStatusMapper(vtkTextMapper* statusMapper) {
		m_pStatusMapper = statusMapper;
	}

	void SetWindowMapper(vtkTextMapper* windowMapper) {
		m_pWindowMapper = windowMapper;
	}

protected:
	void MoveSliceForward() {
		auto slice = m_pImageViewer->GetSlice();
		if (slice < m_pImageViewer->GetSliceMax()) {
			m_pImageViewer->SetSlice(slice + 1);
			auto msg = StatusMessage::Format(slice + 1, m_pImageViewer->GetSliceMax());
			m_pStatusMapper->SetInput(msg.c_str());
			m_pImageViewer->Render();
		}
	}

	void MoveSliceBackward() {
		auto slice = m_pImageViewer->GetSlice();
		if (slice > m_pImageViewer->GetSliceMin()) {
			m_pImageViewer->SetSlice(slice - 1);
			auto msg = StatusMessage::Format(slice - 1, m_pImageViewer->GetSliceMax());
			m_pStatusMapper->SetInput(msg.c_str());
			m_pImageViewer->Render();
		}
	}


	virtual void OnKeyDown() {
		std::string key = GetInteractor()->GetKeySym();
		if (key.compare("Up") == 0) {
			MoveSliceForward();
		}
		else if (key.compare("Down") == 0) {
			MoveSliceBackward();
		}
		vtkInteractorStyleImage::OnKeyDown();
	}

	virtual void OnMouseWheelForward() {
		MoveSliceForward();
	}


	virtual void OnMouseWheelBackward() {
		MoveSliceBackward();
	}

	virtual void WindowLevel()
	{
		vtkInteractorStyleImage::WindowLevel();
		int ww = CurrentImageProperty->GetColorWindow();
		ww = 1.0 * ww / 256 * m_pImageViewer->GetColorWindow();
		int wl = CurrentImageProperty->GetColorLevel();
		wl = 1.0 * (wl - 127) / 256 * m_pImageViewer->GetColorWindow();
		auto msg = WindowMessage::Format(ww, wl);
		m_pWindowMapper->SetInput(msg.c_str());
		m_pImageViewer->Render();
	}

};

vtkStandardNewMacro(InteractorStyleFor2DSlices);

#endif