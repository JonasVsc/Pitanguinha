#pragma once

#include "Core.h"
#include "Window.h"

#include "Events/Event.h"
#include "Events/WindowEvent.h"


namespace Ptg {


	class PTG_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Start();

		void OnEvent(Event& e);

		void OnShutdown();
	
	private:

		bool OnWindowClose(WindowCloseEvent& e);

		bool m_ShouldTerminate = false;

		Window* m_Window;
	};

	Application* CreateApplication();

}