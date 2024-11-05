#pragma once

#ifdef PTG_PLATFORM_WINDOWS


int main()
{
	try {
		Ptg::Application Application; // TODO: Receive Application pointer of client code.
		Application.Start();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

#endif