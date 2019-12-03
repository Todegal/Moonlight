#include "../../mlpch.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace ML {
	spdlog::logger* Log::s_CoreLogger;
	spdlog::logger* Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("MOONLIGHT").get();
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP").get();
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}