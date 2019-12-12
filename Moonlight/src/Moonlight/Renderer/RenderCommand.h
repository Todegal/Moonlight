#pragma once

#include <stdint.h>
#include <glm/vec4.hpp>

namespace ML
{
	class RenderCommand
	{
	public:
		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

		static void SetClearColor(const glm::vec4& color);

		static void Clear();
	};
}