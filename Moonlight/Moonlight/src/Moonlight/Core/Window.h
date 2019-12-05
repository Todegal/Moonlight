#pragma once

#include "../Renderer/GraphicsContext.h"

namespace ML {
	// <summary> A struct which stores all the basic information about the window for easy window creation</summary>
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Moonlight Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	/// <summary> Creates a window </summary>
	class ML_API Window
	{
	public:
		Window(const WindowProps& props);
		~Window();

		static std::unique_ptr<Window> Create(const WindowProps & = WindowProps());

		/// <summary> Called every frame updates the window and refreshes the graphics context </summary>
		void OnUpdate();

		void SetVSync(bool enabled);
		bool GetVSync() const { return m_Data.VSync; }

		int GetWidth() const { return m_Data.Width; }
		int GetHeight() const { return m_Data.Height; }

		/// <summary> Returns the native GLFWwidow* </summary>
		GLFWwindow* GetWindowPointer() const { return m_Window; }

	private:
		void Init(const WindowProps& props);
		void Shutdown();

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
		} m_Data;

		GLFWwindow* m_Window;
		std::unique_ptr<GraphicsContext> m_Context;
	};
}