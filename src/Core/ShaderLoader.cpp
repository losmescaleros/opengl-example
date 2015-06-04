#include "ShaderLoader.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace Core;

ShaderLoader::ShaderLoader(){}
ShaderLoader::~ShaderLoader(){}

std::string ShaderLoader::ReadShader(char* filename)
{
	std::string shaderCode;
	std::ifstream file(filename, std::ios::in);

	if (!file.is_open())
	{
		std::cout << "Cannot read shader file: " << filename << std::endl;
		std::terminate();
	}
	// Allocate space for the shader code
	file.seekg(0, std::ios::end);
	shaderCode.resize((unsigned int)file.tellg());
	// Read the code into the buffer
	file.seekg(0, std::ios::beg);
	file.read(&shaderCode[0], shaderCode.size());
	file.close();

	return shaderCode;
}

GLuint ShaderLoader::CreateShader(GLenum shaderType, std::string source, char* shaderName)
{
	int compileResult = 0;

	GLuint shader = glCreateShader(shaderType);
	const char* shaderCode = source.c_str();
	const int shaderCodeSize = source.size();

	glShaderSource(shader, 1, &shaderCode, &shaderCodeSize);
	glCompileShader(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

	// Check for compile errors
	if (compileResult == GL_FALSE)
	{
		int infoLogLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
		std::vector<char> shaderLog(infoLogLength);
		glGetShaderInfoLog(shader, infoLogLength, NULL, &shaderLog[0]);

		std::cout << "Shader Loader: Error compiling shader: " << shaderName << std::endl << &shaderLog[0] << std::endl;
		return 0;
	}
	// No errors found, returning compiled shader
	return shader;
}

GLuint ShaderLoader::CreateProgram(char* vertexShaderFilename, char* fragmentShaderFilename)
{
	std::string vertexShaderCode = ReadShader(vertexShaderFilename);
	std::string fragmentShaderCode = ReadShader(fragmentShaderFilename);

	GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, vertexShaderCode, "vertex shader");
	GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, fragmentShaderCode, "fragment shader");

	int linkResult = 0;

	GLuint program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);
	// Check for linking errors
	glGetProgramiv(program, GL_LINK_STATUS, &linkResult);
	if (linkResult == GL_FALSE)
	{
		int logLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);
		glGetProgramInfoLog(program, logLength, NULL, &log[0]);
		std::cout << "Shader Loader: Error linking shader" << std::endl << &log[0] << std::endl;
		return 0;
	}
	// Returning the linked program
	return program;
}