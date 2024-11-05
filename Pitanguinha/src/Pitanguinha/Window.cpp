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
		m_Width = width;
		m_Height = height;
		m_Name = name;

		Init();

		return new Window();
	}

	void Window::Init()
	{
		if (!glfwInit())
			PTG_DEBUG("Error: glfwInit()");

		m_Window = glfwCreateWindow((int)m_Width, (int)m_Height, m_Name, nullptr, nullptr);
		if(m_Window == nullptr)
			PTG_DEBUG("Error: glfwCreateWindow()");

		glfwMakeContextCurrent(m_Window);

		// TODO: set callbacks

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