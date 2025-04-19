#include <maroon.h>

class Sandbox : public Maroon::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Maroon::Application* Maroon::CreateApplication()
{
	return new Sandbox();
}