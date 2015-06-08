#include <AssetManagers/ShaderManager.h>

using namespace AssetManagers;

std::map<std::string, GLuint> ShaderManager::programs;

ShaderManager::ShaderManager(){}
ShaderManager::~ShaderManager()
{
	std::map<std::string, GLuint>::iterator it;
	for (it = programs.begin(); it != programs.end(); it++)
	{
		GLuint ptr = it->second;
		glDeleteProgram(ptr);
	}
	programs.clear();
}

/// <summary>
/// Reads the shader.
/// </summary>
/// <param name="filename">The filename.</param>
/// <returns></returns>
std::string ShaderManager::ReadShader(const std::string& filename)
{
	std::string shaderCode;
	std::ifstream file(filename, std::ios::in);

	if (!file.is_open())
	{
		std::cout << "Cannot read shader file: " << filename.c_str() << std::endl;
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

/// <summary>
/// Creates the shader.
/// </summary>
/// <param name="shaderType">Type of the shader.</param>
/// <param name="source">The source.</param>
/// <param name="shaderName">Name of the shader.</param>
/// <returns></returns>
GLuint ShaderManager::CreateShader(GLenum shaderType, const std::string& source, const std::string& shaderName)
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

		std::cout << "Shader Manager:\tError compiling shader: " << shaderName.c_str() << std::endl << &shaderLog[0] << std::endl;
		return 0;
	}
	// No errors found, returning compiled shader
	return shader;
}

/// <summary>
/// Creates the program.
/// </summary>
/// <param name="shaderName">Name of the shader.</param>
/// <param name="vertexShaderFilename">The vertex shader filename.</param>
/// <param name="fragmentShaderFilename">The fragment shader filename.</param>
void ShaderManager::CreateProgram(const std::string &shaderName, 
	const std::string &vertexShaderFilename, 
	const std::string &fragmentShaderFilename)
{
	// Does the map already contain a shader by this name?
	if (programs.count(shaderName) != 0)
	{
		std::cout << "Shader Manager:\tA shader called " << shaderName.c_str() << "already exists!\n";
	}
	else
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
		}

		programs[shaderName] = program;
	}	
}

/// <summary>
/// Gets the shader.
/// </summary>
/// <param name="shaderName">Name of the shader.</param>
/// <returns></returns>
const GLuint ShaderManager::GetShader(const std::string& shaderName)
{
	// Does a shader by this name exist? If so, return it. Otherwise, return 0.
	if (programs.count(shaderName) == 1)
	{
		return programs.at(shaderName);
	}

	return 0;
}

/// <summary>
/// Deletes the shader.
/// </summary>
/// <param name="shaderName">Name of the shader.</param>
void ShaderManager::DeleteShader(const std::string& shaderName)
{
	if (programs.count(shaderName) == 1)
	{
		GLuint ptr = programs.at(shaderName);
		glDeleteProgram(ptr);
		programs.erase(shaderName);
	}
	else
	{
		std::cout << "Shader Manager:\t Shader with name " << shaderName.c_str() << " doesn't exist\n";
	}
}