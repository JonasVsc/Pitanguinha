#pragma once

#ifdef PTG_PLATFORM_WINDOWS

extern Ptg::Application* Ptg::CreateApplication();

int main()
{
	try {
		auto app = Ptg::CreateApplication();
		app->Start();
		delete app;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

#endif