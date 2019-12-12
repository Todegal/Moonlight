#include <imgui.h>

#include <Moonlight.h>
#include <Moonlight\Core\EntryPoint.h>

class TestLayer : public ML::Layer
{
public:
	TestLayer() :
		ML::Layer("Tets Layer")
	{
	}

	void OnImGuiRender()
	{
	}

	void OnUpdate(ML::Timestep ts)
	{
	}
};

class Sandbox : public ML::Application
{
public:
	Sandbox()
	{
		PushOverlay(new TestLayer());
	}

	~Sandbox()
	{
	}
};

ML::Application* ML::CreateApplication()
{
	return new Sandbox();
}