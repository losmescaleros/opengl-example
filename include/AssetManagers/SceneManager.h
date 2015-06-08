#pragma once
#include <AssetManagers/ShaderManager.h>
#include <AssetManagers/ModelManager.h>
#include <Core/Init/IListener.h>

namespace AssetManagers
{
	class SceneManager : public Core::IListener
	{
	public:
		SceneManager();
		~SceneManager();
		virtual void NotifyBeginFrame();
		virtual void NotifyDisplayFrame();
		virtual void NotifyEndFrame();
		virtual void NotifyReshape(int width, int height, int prevWidth, int prevHeight);

	private:
		AssetManagers::ShaderManager* shaderManager;
		AssetManagers::ModelManager* modelManager;
	};
}