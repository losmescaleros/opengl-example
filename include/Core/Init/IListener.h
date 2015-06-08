#pragma once

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
	};

	inline IListener::~IListener(){};
}