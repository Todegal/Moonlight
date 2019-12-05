#pragma once

#include "Window.h"
#include "LayerStack.h"
#include "../Events/ApplicationEvent.h"
#include "../Events/KeyEvent.h"

namespace ML
{
	class ML_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	// Defined in CLIENT app
	extern Application* CreateApplication();
}