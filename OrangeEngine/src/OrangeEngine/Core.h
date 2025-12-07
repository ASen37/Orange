#pragma once


#ifdef SPEC_CLASS_ENABLE
	#include "spdlog/fmt/bundled/format.h"
	
	// spdlog 库中通过重载 << 进行日志输出的方式一直不可行
	// 所以只能特化每个子类进行适配 formatter 进行日志输出了
	// 或者直接调用基类的 ToString 接口（就不用特化了，可以
	// 将 oepch.h 中的 SPEC_CLASS_ENABLE 宏关掉）
	
	#define SPEC_SUBCLASS(x) \
		template<> \
		struct fmt::formatter<Orange::x> : fmt::formatter<std::string> \
		{ \
			auto format(const Orange::x& my, format_context& ctx) const -> decltype(ctx.out()) \
			{ \
				return fmt::format_to(ctx.out(), "{}", my.ToString()); \
			} \
		};
#else
	#define SPEC_SUBCLASS(x)
#endif


#ifdef ORANGE_PLATFORM_WINDOWS
	#ifdef ORANGE_BUILD_DLL
		#define ORANGE_API __declspec(dllexport)
	#else
		#define ORANGE_API __declspec(dllimport)
	#endif
#else
	#error Orange only supports Windows!
#endif


#ifdef ORANGE_ENABLE_ASSERTS
	#define ORANGE_ASSERT(x, ...) if(!(x)) { ORANGE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }
	#define ORANGE_CORE_ASSERT(x, ...) if(!(x)) { ORANGE_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); }
#else
	#define ORANGE_ASSERT(x, ...)
	#define ORANGE_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

