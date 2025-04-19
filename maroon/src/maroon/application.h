#pragma once

#include "core.h"

namespace Maroon 
{
	class MAROON_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}
