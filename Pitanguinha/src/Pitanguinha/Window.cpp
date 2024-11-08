#include "pch.h"
#include "Window.h"

#include "Log.h"

#include "Events/Event.h"
#include "Events/WindowEvent.h"

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
		glfwSetErrorCallback([](int error_code, const char* description)
		{
			PTG_DEBUG("Error (" << error_code << ") " << description);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData* data = static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			if (data)
			{
				PTG_DEBUG("Framebuffer size callback!");
			}
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
		{
			PTG_DEBUG("Cursor moved callback!");
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			switch (action)
			{
			case GLFW_PRESS:
				PTG_DEBUG("Key " << key << " Pressed");
				break;
			case GLFW_RELEASE:
				PTG_DEBUG("Key " << key << " Released");
				break;
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			switch (action)
			{
			case GLFW_PRESS:
				PTG_DEBUG("Mouse button " << button << " Pressed");
				break;
			case GLFW_RELEASE:
				PTG_DEBUG("Mouse button " << button << " Released");
				break;
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