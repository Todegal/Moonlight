#include "../../mlpch.h"
#include "Application.h"

namespace ML
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ML_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
	}

	Application::~Application()
	{
	}

	void Application::Run() {}
};