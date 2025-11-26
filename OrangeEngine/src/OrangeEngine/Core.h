#pragma once

#ifndef SPEC_SUBCLASS
#include "spdlog/fmt/bundled/format.h"

// spdlog 库中通过重载 << 进行日志输出的方式一直不可行
// 所以只能特化每个子类进行适配 formatter 进行日志输出了

#define SPEC_SUBCLASS(x) \
	template<> \
	struct fmt::formatter<Orange::x> : fmt::formatter<std::string> \
	{ \
		auto format(const Orange::x& my, format_context& ctx) const -> decltype(ctx.out()) \
		{ \
			return fmt::format_to(ctx.out(), "{}", my.ToString()); \
		} \
	};
#endif // !SPEC_SUBCLASS


#ifdef ORANGE_PLATFORM_WINDOWS
	#ifdef ORANGE_BUILD_DLL
		#define ORANGE_API __declspec(dllexport)
	#else
		#define ORANGE_API __declspec(dllimport)
	#endif
#else
	#error Orange only supports Windows!
#endif

#define BIT(x) (1 << x)



