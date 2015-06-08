#include <Main.h>
#include <AssetManagers/ShaderManager.h>
#include <AssetManagers/ModelManager.h>
#include <Core/Init/InitGlut.h>
#include <AssetManagers/SceneManager.h>

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
	InitGlut::SetListener(scene);

	InitGlut::Run();
	
	delete scene;
	return 0;
}