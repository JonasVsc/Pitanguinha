#include "Pitanguinha.h"

class Sandbox : public Ptg::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Ptg::Application* Ptg::CreateApplication()
{
	return new Sandbox();
}