#include "Application.h"

#include "Log.h"

#include<GLFW/glfw3.h>


namespace Ptg {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = new Window;
		m_Window->Create(1280, 720, "Pitanguinha");
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		m_Window->Init();
	}
	

	void Application::Start()
	{
		PTG_DEBUG("Entering Application Loop");
		while (!m_ShouldTerminate)
		{
			// TODO: handle events

			m_Window->Update();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		PTG_DEBUG("WindowCloseEvent: Closed window");
	}

	Application::~Application()
	{
	}

	void Application::OnShutdown()
	{
		// clean
		
		// terminate
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_ShouldTerminate = true;
		return true;
	}

}