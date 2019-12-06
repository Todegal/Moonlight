#include <iostream>

#include <Moonlight/Moonlight.h>
#include <Moonlight/Core/EntryPoint.h>

#include <imgui/imgui.h>

class TestLayer : public ML::Layer
{
public:
	TestLayer()
		: Layer("Test Layer")
	{
	}

	~TestLayer()
	{
	}

	void OnAttach() override
	{
	}

	void OnDetach() override
	{
	}

	void OnUpdate(ML::Timestep ts) override
	{
	}

	void OnImGuiRender() override
	{
	}

	void OnEvent(ML::Event& e) override
	{
	}
};

class Sandbox : public ML::Application
{
public:

	Sandbox()
	{
		PushLayer(new TestLayer());
	}

	~Sandbox() {}
};

ML::Application* ML::CreateApplication()
{
	return new Sandbox();
}