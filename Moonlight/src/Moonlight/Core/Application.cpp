#include "mlpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>
#include <imgui.h>

#include "Timestep.h"

namespace ML
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ML_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_Window = Window::Create();
		m_Window->SetEventCallback(ML_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

#ifdef ML_DEBUG
		m_DevLayer = new DeveloperLayer();
		PushOverlay(m_DevLayer);
#endif
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timestep);
			}

			// Run ImGui
			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();

			//ImGui::ShowDemoWindow();

			m_ImGuiLayer->End();

			// Update the window
			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::OnEvent(Event& e)
	{
		e.Dispatch<WindowCloseEvent>(ML_BIND_EVENT_FN(Application::OnWindowClose));
		e.Dispatch<WindowResizeEvent>(ML_BIND_EVENT_FN(Application::OnWindowResize));

		// Pass the event through all the layers to handle it
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;

		return false;
	}
};