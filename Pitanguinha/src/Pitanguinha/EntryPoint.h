#pragma once

#ifdef PTG_PLATFORM_WINDOWS


int main()
{
	Ptg::Application Application; // TODO: Receive Application pointer of client code.
	Application.Start();
}

#endif