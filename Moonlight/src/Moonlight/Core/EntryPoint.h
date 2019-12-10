#pragma once

extern ML::Application* ML::CreateApplication();

int main(int argc, char** argv)
{
	ML::Log::Init();

	auto app = ML::CreateApplication();

	app->Run();

	delete app;

	return 1;
}