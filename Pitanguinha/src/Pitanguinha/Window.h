#pragma once
#include <pch.h>

#include <GLFW/glfw3.h>

#include "Events/EventDispatcher.h"

struct WindowData
{
	unsigned int Width = 1280, Height = 720;
	const char* App_name = "Pitanguinha";

	WindowData() {}
};

namespace Ptg {

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		~Window();

		Window* Create(unsigned int width, unsigned int height, const char* name);

		inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; };

		void Init();

		void Update();

		virtual void Shutdown();


	private:

		GLFWwindow* m_Window;

		struct WindowData
		{
			unsigned int Width = 1280, Height = 720;
			
			const char* App_name = "Pitanguinha";

			EventCallbackFn EventCallback;
		};
		
		WindowData m_Data;
	};

}