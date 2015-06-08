#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

namespace AssetManagers
{		
	/// <summary>
	/// Class for handling reading, compilation, and linking of shaders
	/// </summary>
	class ShaderManager
	{
	private:		
		std::string ReadShader(const std::string& filename);		
		GLuint CreateShader(GLenum shaderType, 
			const std::string& source, 
			const std::string& shaderName);
		static std::map<std::string, GLuint> programs;
	public:
		ShaderManager(void);
		~ShaderManager(void);	
		void CreateProgram(const std::string& shaderName, 
			const std::string& vertexShaderFilename, 
			const std::string& fragmentShaderFilename);
		static const GLuint GetShader(const std::string& shaderName);
		static void DeleteShader(const std::string& shaderName);
		// GLuint CreateProgram(char* vertexShaderFilename, char* fragmentShaderFilename);
	};
}