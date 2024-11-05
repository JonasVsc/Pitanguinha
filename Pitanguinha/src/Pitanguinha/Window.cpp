#include "pch.h"
#include "Window.h"

#include "Log.h"

namespace Ptg {

	

	Window::~Window()
	{
		Shutdown(); 
	}

	Window* Window::Create(unsigned int width, unsigned int height, const char* name)
	{
		m_Data.Width = width;
		m_Data.Height = height;
		m_Data.App_name = name;

		return new Window();
	}

	void Window::Init()
	{
		if (!glfwInit())
			PTG_DEBUG("Error: glfwInit()");

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.App_name, nullptr, nullptr);
		if(m_Window == nullptr)
			PTG_DEBUG("Error: glfwCreateWindow()");

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);

		PTG_DEBUG("Listening callbacks...");

		// TODO: set callbacks
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			if (data) 
			{
				PTG_DEBUG("Window close callback!");
				glfwSetWindowShouldClose(window, true);
			}
		});

		glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			if (data)
			{
				PTG_DEBUG("Framebuffer size callback!");
			}
		});

	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

}