#include <Moonlight.h>
#include <Moonlight\Core\EntryPoint.h>

class Sandbox : public ML::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

ML::Application* ML::CreateApplication()
{
	return new Sandbox();
}