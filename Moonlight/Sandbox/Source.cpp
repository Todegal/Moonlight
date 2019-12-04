#include <iostream>

#include <Moonlight.h>
#include <Moonlight/Core/EntryPoint.h>

#define AC(type) virtual const char* GetName() const { return #type; }

class Sandbox : public ML::Application
{
public:
	AC(HI);

	Sandbox()
	{
		ML_INFO("hi there");
		ML_TRACE("I'm Alive!");
		ML_WARN("SERIOUSLY!");
		ML_ERROR("HELP ME!");
		ML_CRITICAL("PLEASE!! HELP ME!!");

		ML_CRITICAL(__TIME__);
		ML_CRITICAL(__DATE__);
		ML_CRITICAL(__FILE__);

		ML_INFO(GetName());

		std::cin.get();
	}

	~Sandbox() {}
};

ML::Application* ML::CreateApplication()
{
	return new Sandbox();
}