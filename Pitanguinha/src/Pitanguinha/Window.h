#pragma once

#include <GLFW/glfw3.h>

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

		~Window();

		Window* Create(unsigned int width, unsigned int height, const char* name);

		void Init();

		void Update();

		void Shutdown();


	private:

		const char* m_Name;
		unsigned int m_Width, m_Height;
		
		GLFWwindow* m_Window;
	};

}