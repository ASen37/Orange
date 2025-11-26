#pragma once

/*
 * 为什么这么设计程序的入口点？
 * - 引擎的架构是 “核心 + 沙盒” 分层架构，这样可以让 “引擎核心” 与 “用户业务（沙盒）” 解耦
 * - 引擎接管沙盒实例的生命周期而不关心其具体实现
 * - 沙盒也不用关心其启动流程，只负责具体业务逻辑
 */
#ifdef ORANGE_PLATFORM_WINDOWS

extern Orange::Application* Orange::CreateApplication();

int main(int argc, char** argv) {
	Orange::Log::Init();
	ORANGE_WARN("Invalid value!");
	int a = 723;
	ORANGE_CORE_INFO("Value: {0}", a);

	auto app = Orange::CreateApplication();
	app->Run();
	delete app;
}


#endif

