#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Maroon {
	class Log
	{
		public:	
			static void MAROON_API Init();
			inline static MAROON_API std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static MAROON_API std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

#define MR_CORE_ERROR(...) ::Maroon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MR_CORE_WARN(...) ::Maroon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MR_CORE_INFO(...) ::Maroon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MR_CORE_TRACE(...) ::Maroon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MR_CORE_FATAL(...) ::Maroon::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define MR_ERROR(...) ::Maroon::Log::GetClientLogger()->error(__VA_ARGS__)
#define MR_WARN(...) ::Maroon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MR_INFO(...) ::Maroon::Log::GetClientLogger()->info(__VA_ARGS__)
#define MR_TRACE(...) ::Maroon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MR_FATAL(...) ::Maroon::Log::GetClientLogger()->fatal(__VA_ARGS__)