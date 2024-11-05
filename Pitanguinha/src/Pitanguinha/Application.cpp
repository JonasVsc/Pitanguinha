#include "Application.h"

#include "Log.h"

namespace Ptg {

	Application::Application()
	{
		PTG_DEBUG("Init successfully");
	}

	Application::~Application()
	{
	}

	void Application::Start()
	{
		PTG_DEBUG("Entering Application Loop");
		while (!m_ShouldTerminate)
		{
			// update events

			// draw stuff

			// update window
		}
	}


	

	void Application::OnShutdown()
	{
		// clean
		
		// terminate
	}

}