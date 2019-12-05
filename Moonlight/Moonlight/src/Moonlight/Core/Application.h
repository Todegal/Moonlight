#pragma once

#include "Window.h"

namespace ML
{
	class Application
	{
	public:
		ML_API Application();
		virtual ML_API ~Application();

		void ML_API Run();

		inline static ML_API Application& Get() { return *s_Instance; }
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
	private:
		static ML_API Application* s_Instance;
	};

	// Defined in CLIENT app
	extern Application* CreateApplication();
}