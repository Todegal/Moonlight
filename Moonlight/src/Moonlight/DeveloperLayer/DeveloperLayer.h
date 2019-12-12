#pragma once

#include "../Core/Layer.h"

namespace ML
{
	class DeveloperLayer : public Layer
	{
	private:
		// Booleans for storing the imgui state
		bool m_ShowAppMetrics = false;
		bool m_ShowAppStyleEditor = false;
		bool m_ShowAppAbout = false;
		bool m_ShowDemoWindow = false;
		bool m_ShowConsole = false;

	private:
		void ShowMainMenuBar();
		void ShowDeveloperConsole();

	public:
		DeveloperLayer();
		~DeveloperLayer() = default;

		void OnAttach();
		void OnDetach();
		void OnUpdate(Timestep ts);
		void OnImGuiRender();
		void OnEvent(Event& event);
	};
}