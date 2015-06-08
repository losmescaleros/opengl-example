#include <Core/Init/DebugOutput.h>

namespace Core
{
	void APIENTRY debugCallback(GLenum source, GLenum type, GLuint id,
		GLenum severity, GLsizei length, const GLchar * msg, const void * param) {
		std::cout << " Debug Output " << std::endl;
		std::cout << "debug call: " << msg << std::endl;
		std::cout << "\n************************" << std::endl;
	}

}
