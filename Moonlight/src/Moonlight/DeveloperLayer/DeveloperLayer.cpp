#include "mlpch.h"
#include "DeveloperLayer.h"

#include <imgui.h>

#include "DeveloperConsole.h"

namespace ML
{
	DeveloperLayer::DeveloperLayer()
		: Layer("DevLayer") {}

	void DeveloperLayer::OnAttach()
	{
	}

	void DeveloperLayer::OnDetach()
	{
	}

	void DeveloperLayer::OnUpdate(Timestep ts)
	{
	}

	void DeveloperLayer::ShowMainMenuBar()
	{
		//ImGui::ShowDemoWindow();

		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("Tools"))
			{
				ImGui::MenuItem("Console", "", &m_ShowConsole);

				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("ImGui"))
			{
				ImGui::MenuItem("Metrics", "", &m_ShowAppMetrics);
				ImGui::MenuItem("Style Editor", "", &m_ShowAppStyleEditor);
				ImGui::MenuItem("Demo Window", "", &m_ShowDemoWindow);
				ImGui::Separator();
				ImGui::MenuItem("About ImGui", "", &m_ShowAppAbout);

				ImGui::EndMenu();
			}

			ImGui::EndMainMenuBar();
		}
	}

	void DeveloperLayer::ShowDeveloperConsole()
	{
		static DeveloperConsole console;
		console.Draw("DevConsole", &m_ShowConsole);
	}

	void DeveloperLayer::OnImGuiRender()
	{
		ShowMainMenuBar();

		if (m_ShowAppMetrics) { ImGui::ShowMetricsWindow(&m_ShowAppMetrics); }
		if (m_ShowAppStyleEditor) { ImGui::Begin("Style Editor", &m_ShowAppStyleEditor); ImGui::ShowStyleEditor(); ImGui::End(); }
		if (m_ShowAppAbout) { ImGui::ShowAboutWindow(&m_ShowAppAbout); }
		if (m_ShowDemoWindow) { ImGui::ShowDemoWindow(&m_ShowDemoWindow); }
		if (m_ShowConsole) { ShowDeveloperConsole(); }
	}

	void DeveloperLayer::OnEvent(Event& event)
	{
	}
}