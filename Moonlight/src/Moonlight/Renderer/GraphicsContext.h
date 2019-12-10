#pragma once

struct GLFWwindow;

namespace ML
{
	/// <summary> Maintains data on the current state of the rendering API </summary>
	class ML_API GraphicsContext
	{
	public:
		GraphicsContext(GLFWwindow* windowHandle);

		void Init();
		void SwapBuffers();

		static std::unique_ptr<GraphicsContext> Create(GLFWwindow* window);

	private:
		GLFWwindow* m_WindowHandle;
	};
}