#pragma once

#include "Window.h"
#include "../Events/ApplicationEvent.h"

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

	private:
		static Application* s_Instance;
	};

	// Defined in CLIENT app
	extern Application* CreateApplication();
}