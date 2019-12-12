#pragma once

#include <imgui.h>

namespace ML
{
	class DeveloperConsole
	{
	public:
		DeveloperConsole();
		~DeveloperConsole();

		void Draw(const char* title, bool* p_open);
	private:
		char m_InputBuf[512];
		std::vector<std::string> m_Items;
		std::vector<std::string>m_Commands;
		std::vector<std::string>m_History;
		int	m_HistoryPos;
		ImGuiTextFilter	m_Filter;
		bool m_AutoScroll;
		bool m_ScrollToBottom;

		inline void ClearLog() { m_Items.clear(); }

		void AddLog(const char* fmt, ...) IM_FMTARGS(2);

		int TextEditCallback(ImGuiInputTextCallbackData* data);
	};
}