#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel {

	class HAZEL_API Log {
		
	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;

	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {
			return s_coreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& getClientLogger() {
			return s_clientLogger;
		}
	};
}

// The macros below are basically a shorthand of the log function

// Core log macros
// ... means a number of variants, __VA_ARGS__ represents the variants
#define HZ_CORE_TRACE(...)	::Hazel::Log::getCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)	::Hazel::Log::getCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)	::Hazel::Log::getCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)	::Hazel::Log::getCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)	::Hazel::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HZ_TRACE(...)	::Hazel::Log::getClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)	::Hazel::Log::getClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)	::Hazel::Log::getClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)	::Hazel::Log::getClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)	::Hazel::Log::getClientLogger()->fatal(__VA_ARGS__)

