#include "oepch.h"
#include "OrangeEngine/Log.h"
#include "Application.h"
#include "OrangeEngine/Events/ApplicationEvent.h"

namespace Orange
{
	Application::Application() {

	}

	Application::~Application() {
	
	}

	void Application::Run() {
		WindowResizeEvent e(100, 720);
		
		if (e.IsInCategory(EventCategoryApplication)) 
		{
			ORANGE_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			ORANGE_TRACE(e);
		}

		while (true);
	}


} // namespace Orange