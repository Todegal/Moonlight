#include "mlpch.h"
#include "GraphicsContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>

namespace ML
{
	GraphicsContext::GraphicsContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ML_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void GraphicsContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ML_CORE_ASSERT(status, "Failed to initialize Glad!");

		ML_CORE_INFO("OpenGL Info:");
		ML_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		ML_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ML_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		// Ensure that the requested OPENGL version is at least 4.5
		ML_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Moonlight requires at least OpenGL version 4.5!");
	}

	void GraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

	std::unique_ptr<GraphicsContext> GraphicsContext::Create(GLFWwindow* window)
	{
		return std::make_unique<GraphicsContext>(window);
	}
}