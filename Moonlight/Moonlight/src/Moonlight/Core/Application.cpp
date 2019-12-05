#include "../mlpch.h"
#include "Application.h"

namespace ML
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ML_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_Window = Window::Create();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			// Update the window
			m_Window->OnUpdate();
		}
	}
};