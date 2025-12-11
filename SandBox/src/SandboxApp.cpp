#include <Orange.h>

class ExampleLayer : public Orange::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override {
		//ORANGE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Orange::Event& event) override {
		ORANGE_TRACE("{0}", event.ToString());
	}
};



class Sandbox : public Orange::Application {
public:
	Sandbox() {
		
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Orange::Application* Orange::CreateApplication() {
	return new Sandbox();
}