#include <Moonlight.h>
#include <Moonlight\Core\EntryPoint.h>

#include <glm\vec3.hpp>

class TestLayer : public ML::Layer
{
private:
	glm::vec3
};

class Sandbox : public ML::Application
{
	:
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