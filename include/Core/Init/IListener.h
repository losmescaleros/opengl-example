#pragma once
#include <glm/glm.hpp>
#include <Rendering/Camera.h>

namespace Core
{
	class IListener
	{
	public:
		virtual ~IListener() = 0;

		virtual void NotifyBeginFrame() = 0;
		virtual void NotifyDisplayFrame() = 0;
		virtual void NotifyEndFrame() = 0;
		virtual void NotifyReshape(int width, int height, int prevWidth, int prevHeight) = 0;
		virtual void SetCamera(const glm::vec3& position, int viewPortWidth, int viewPortHeight) = 0;
		virtual Camera* GetActiveCamera() = 0;
	};

	inline IListener::~IListener(){};
}