#pragma once
#include <AssetManagers/ShaderManager.h>
#include <AssetManagers/ModelManager.h>
#include <Core/Init/IListener.h>
#include <Rendering/Camera.h>

namespace AssetManagers
{
	class SceneManager : public Core::IListener
	{
	public:
		SceneManager();
		~SceneManager();
		virtual void SetCamera(const glm::vec3& position, int viewPortWidth, int viewPortHeight);
		virtual Camera* GetActiveCamera();
		virtual void NotifyBeginFrame();
		virtual void NotifyDisplayFrame();
		virtual void NotifyEndFrame();
		virtual void NotifyReshape(int width, int height, int prevWidth, int prevHeight);

	private:
		AssetManagers::ShaderManager* shaderManager;
		AssetManagers::ModelManager* modelManager;
		Camera* camera;
	};
}