#include <Main.h>
#include <AssetManagers/ShaderManager.h>
#include <AssetManagers/ModelManager.h>
#include <Core/Init/InitGlut.h>
#include <AssetManagers/SceneManager.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

using namespace Core;
using namespace Core::Init;

AssetManagers::ModelManager* modelManager;
AssetManagers::ShaderManager* shaderManager;
GLuint program;

/// <summary>
/// Entry point into the program
/// </summary>
/// <param name="argc">The argc.</param>
/// <param name="argv">The argv.</param>
/// <returns></returns>
int main(int argc, char* argv[])
{
	Window window(std::string("OpenGL Window"),
		400, 200, 
		800, 600, 
		true);
	Context context(4, 3, true);
	FrameBuffer frameBuffer(true, true, true, true);
	InitGlut::Init(window, context, frameBuffer);
	IListener* scene = new AssetManagers::SceneManager();
	scene->SetCamera(glm::vec3(0, 0, 10), 800, 600);
	InitGlut::SetListener(scene);
	Assimp::Importer importer;
	InitGlut::Run();
	
	delete scene;
	return 0;
}