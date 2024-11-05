#pragma once

#include "Core.h"
#include "Window.h"

namespace Ptg {


	class PTG_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Start();

		void OnShutdown();
	
	private:
		bool m_ShouldTerminate = false;

		Window* m_Window;
	};

}