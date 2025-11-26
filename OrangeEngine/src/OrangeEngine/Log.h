#pragma once

#include "Core.h"

#pragma warning(push, 0)
#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>
#pragma warning(pop)

namespace Orange 
{
	class ORANGE_API Log
	{
	public:
		typedef std::shared_ptr<spdlog::logger> LoggerPtr;
		static void Init();

		inline static LoggerPtr& GetCoreLogger() { return s_CoreLogger; }
		inline static LoggerPtr& GetClientLogger() { return s_ClientLogger; }

	private:
		static LoggerPtr s_CoreLogger;
		static LoggerPtr s_ClientLogger;
	};
} // namespace Orange


// Core log macros
#define ORANGE_CORE_TRACE(...)		::Orange::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ORANGE_CORE_INFO(...)		::Orange::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ORANGE_CORE_WARN(...)		::Orange::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ORANGE_CORE_ERROR(...)		::Orange::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ORANGE_CORE_CRITICAL(...)	::Orange::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ORANGE_TRACE(...)			::Orange::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ORANGE_INFO(...)			::Orange::Log::GetClientLogger()->info(__VA_ARGS__)
#define ORANGE_WARN(...)			::Orange::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ORANGE_ERROR(...)			::Orange::Log::GetClientLogger()->error(__VA_ARGS__)
#define ORANGE_CRITICAL(...)		::Orange::Log::GetClientLogger()->critical(__VA_ARGS__)


