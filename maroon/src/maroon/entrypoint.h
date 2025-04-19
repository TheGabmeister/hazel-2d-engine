#pragma once

#ifdef MR_PLATFORM_WINDOWS

extern Maroon::Application* Maroon::CreateApplication();

int main(int argc, char** argv)
{
	Maroon::Log::Init();

	auto app = Maroon::CreateApplication();
	app->Run();
	delete app;
}

#endif