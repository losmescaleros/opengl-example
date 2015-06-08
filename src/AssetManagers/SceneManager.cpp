#include <AssetManagers/SceneManager.h>

using namespace AssetManagers;

SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);
	shaderManager = new ShaderManager();
	shaderManager->CreateProgram("colorShader",
		"..\\src\\Shaders\\Vertex_Shader.glsl",
		"..\\src\\Shaders\\Fragment_Shader.glsl");
	modelManager = new ModelManager();
}

SceneManager::~SceneManager()
{
	delete shaderManager;
	delete modelManager;
}

void SceneManager::NotifyBeginFrame()
{
	modelManager->Update();
}

void SceneManager::NotifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	modelManager->Draw();
}

void SceneManager::NotifyEndFrame()
{

}

void SceneManager::NotifyReshape(int width, int height, int prevWidth, int prevHeight)
{

}