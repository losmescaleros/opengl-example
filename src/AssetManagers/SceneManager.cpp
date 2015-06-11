#include <AssetManagers/SceneManager.h>

using namespace AssetManagers;

SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	shaderManager = new ShaderManager();
	shaderManager->CreateProgram("colorShader",
		"..\\src\\Shaders\\Vertex_Shader.glsl",
		"..\\src\\Shaders\\Fragment_Shader.glsl");
	shaderManager->CreateProgram("colorShaderMvp",
		"..\\src\\Shaders\\SimpleShader.vert",
		"..\\src\\Shaders\\SimpleShader.frag");
	modelManager = new ModelManager();
}

SceneManager::~SceneManager()
{
	delete shaderManager;
	delete modelManager;
	delete camera;
}

void SceneManager::SetCamera(const glm::vec3& position, int viewPortWidth, int viewPortHeight)
{
	camera = new Camera();
	camera->SetPosition(position);
	camera->SetViewport(0, 0, viewPortWidth, viewPortHeight);
	camera->SetProjectionRH(60.0f, viewPortWidth / (float)viewPortHeight, 0.1f, 100.0f);
}

Camera* SceneManager::GetActiveCamera()
{
	return camera;
}

void SceneManager::NotifyBeginFrame()
{
	modelManager->Update();
}

void SceneManager::NotifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClearDepth(1.0f);

	modelManager->Draw(camera);
}

void SceneManager::NotifyEndFrame()
{

}

void SceneManager::NotifyReshape(int width, int height, int prevWidth, int prevHeight)
{
	camera->SetViewport(0, 0, width, height); camera->SetProjectionRH(60.0f, width / (float)height, 0.1f, 100.0f);
}