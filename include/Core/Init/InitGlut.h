#pragma once
#include <Core/Context.h>
#include <Core/FrameBuffer.h>
#include <Core/Window.h>
#include <Core/Init/InitGlew.h>
#include <Core/Init/IListener.h>
#include <Core/Init/DebugOutput.h>

#include <iostream>

namespace Core
{
	namespace Init
	{
		class InitGlut
		{
		public:
			static void Init(const Core::Window& window, 
				const Core::Context& context, 
				const Core::FrameBuffer& frameBuffer);
			static void Run();
			static void Close();
			static void PrintOpenGlInfo(const Core::Window &window, const Core::Context &context);
			static void SetListener(Core::IListener*& listener);
			void EnterFullscreen();
			void ExitFullScreen();

		private:
			static void IdleCallback();
			static void DisplayCallback();
			static void ReshapeCallback(int width, int height);
			static void CloseCallback();
			static Core::IListener* listener;
			static Core::Window window;
		};
	}
}