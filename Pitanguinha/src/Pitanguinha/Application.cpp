#include "Application.h"

#include "Log.h"

#include<GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


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
		
		GLuint VAO, VBO;
		GLuint vertShader, fragShader, program;
		const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";

		const char* fragmentShaderSource = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n\0";

		vertShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertShader);

		fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragShader);

		program = glCreateProgram();
		glAttachShader(program, vertShader);
		glAttachShader(program, fragShader);
		glLinkProgram(program);

		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);


		while (!m_ShouldTerminate)
		{
			glfwPollEvents();

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			ImGui::Begin("Test");
			ImGui::Text("Testing ImGui");
			ImGui::End();

			ImGui::Render();

			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.0f, 0.4f, 0.8f, 1.0f);


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