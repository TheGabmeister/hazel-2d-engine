#include "application.h"

#include "events/application_event.h"
#include "log.h"

namespace Maroon {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			MR_TRACE(e.ToString());
		}
		
		while (true)
		{
			// Do something here
		}
	}
}
