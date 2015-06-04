#include <GL/glew.h>
#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include <iostream>

namespace Core
{
	class ShaderLoader
	{
	private:
		std::string ReadShader(char *filename);
		GLuint CreateShader(GLenum shaderType, std::string source, char* shaderName);
	public:
		ShaderLoader(void);
		~ShaderLoader(void);
		GLuint CreateProgram(char* vertexShaderFilename, char* fragmentShaderFilename);
	};
}