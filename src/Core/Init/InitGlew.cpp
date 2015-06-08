#include <Core/Init/InitGlew.h>

using namespace Core;
using namespace Core::Init;

void InitGlew::Init()
{
	glewExperimental = true;
	GLint initResult = glewInit();
	if (initResult == GLEW_OK)
	{
		std::cout << "GLEW:\tInitialized\n";
	}
	else
	{
		std::cout << "GLEW ERROR:\t" << glewGetErrorString(initResult) << std::endl;
	}
}