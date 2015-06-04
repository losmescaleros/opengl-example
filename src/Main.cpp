#include <Main.h>
#include "Core\ShaderLoader.h"

GLuint program;

void RenderScene();
void Init();

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL: Making a Triangle");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_3"))
	{
		std::cout << "GLEW Version is 3.3\n";
	}
	else
	{
		std::cout << "GLEW Version 3.3 not supported\n";
	}

	Init();

	glutDisplayFunc(RenderScene);
	glutMainLoop();
	glDeleteProgram(program);
	return 0;
}

void Init()
{
	glEnable(GL_DEPTH_TEST);

	Core::ShaderLoader shaderLoader;
	program = shaderLoader.CreateProgram("..\\src\\Shaders\\Vertex_Shader.glsl", "..\\src\\Shaders\\Fragment_Shader.glsl");

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 1.0, 1.0);

	glUseProgram(program);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glutSwapBuffers();
}