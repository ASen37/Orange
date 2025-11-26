#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Orange
{
	class ORANGE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();

} // namespace Orange


//template<>
//struct fmt::formatter<Orange::MyType> : fmt::formatter<std::string> {
//	// 解析格式说明符（可选）
//	constexpr auto parse(format_parse_context& ctx) {
//		return ctx.begin();
//	}
//
//	// 格式化逻辑
//	template<typename FormatContext>
//	auto format(const Orange::MyType& p, FormatContext& ctx) const {
//		return fmt::format_to(ctx.out(), "{}", p.ToString());
//	}
//};
