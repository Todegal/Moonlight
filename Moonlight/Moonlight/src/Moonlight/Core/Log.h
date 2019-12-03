#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace ML
{
	class Log
	{
	public:
		static void ML_API Init();

		inline static spdlog::logger* GetCoreLogger() { return s_CoreLogger; }
		inline static spdlog::logger* GetClientLogger() { return s_ClientLogger; }

	private:
		static ML_API spdlog::logger* s_CoreLogger;
		static ML_API spdlog::logger* s_ClientLogger;
	};
}

// Core log macros
#define ML_CORE_TRACE(...)    ::ML::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ML_CORE_INFO(...)     ::ML::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ML_CORE_WARN(...)     ::ML::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ML_CORE_ERROR(...)    ::ML::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ML_CORE_CRITICAL(...) ::ML::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ML_TRACE(...)         ::ML::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ML_INFO(...)          ::ML::Log::GetClientLogger()->info(__VA_ARGS__)
#define ML_WARN(...)          ::ML::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ML_ERROR(...)         ::ML::Log::GetClientLogger()->error(__VA_ARGS__)
#define ML_CRITICAL(...)      ::ML::Log::GetClientLogger()->critical(__VA_ARGS__)