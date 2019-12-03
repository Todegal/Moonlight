#include <iostream>

#include <Moonlight.h>
#include <Moonlight/Core/EntryPoint.h>

class Sandbox : public ML::Application
{
public:
	Sandbox()
	{
		ML_INFO("hi there");
		ML_TRACE("I'm Alive!");
		ML_WARN("SERIOUSLY!");
		ML_ERROR("HELP ME!");
		ML_CRITICAL("PLEASE!! HELP ME!!");

		ML_CRITICAL("ARGH!!!");

		std::cin.get();
	}

	~Sandbox() {}
};

ML::Application* ML::CreateApplication()
{
	return new Sandbox();
}