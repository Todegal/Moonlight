#pragma once

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
		static ML_API Application* s_Instance;
	};

	// Defined in CLIENT app
	extern Application* CreateApplication();
}