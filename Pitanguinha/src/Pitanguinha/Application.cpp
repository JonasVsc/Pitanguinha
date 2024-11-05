#include "Application.h"

#include "Log.h"

#include<GLFW/glfw3.h>

namespace Ptg {

	Application::Application()
	{
		m_Window = new Window;
		m_Window->Create(1280, 720, "Pitanguinha");
	}

	Application::~Application()
	{
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


	

	void Application::OnShutdown()
	{
		// clean
		
		// terminate
	}

}