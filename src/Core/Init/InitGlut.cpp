#include <Core/Init/InitGlut.h>

using namespace Core::Init;

Core::IListener* InitGlut::listener = NULL;
Core::Window InitGlut::window;

void InitGlut::Init(const Core::Window& window,
	const Core::Context& context,
	const Core::FrameBuffer& frameBuffer)
{
	int fakeArgc = 1;
	char* fakeArgv[] = { "fake", NULL };
	glutInit(&fakeArgc, fakeArgv);

	if (context.isCore)
	{
		glutInitContextVersion(context.majorVersion, context.minorVersion);
		glutInitContextProfile(GLUT_CORE_PROFILE);
		glutInitContextFlags(GLUT_FORWARD_COMPATIBLE
#if _DEBUG
			| GLUT_DEBUG
#endif
			);
	}
	else
	{
		glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
		glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
	}

	

	InitGlut::window = window;
	glutInitDisplayMode(frameBuffer.flags);
	glutInitWindowPosition(window.pos_x, window.pos_y);
	glutInitWindowSize(window.width, window.height);

	
	glutCreateWindow(window.name.c_str());

	std::cout << "GLUT:\tInitialized\n";
	
	glutIdleFunc(IdleCallback);
	glutCloseFunc(CloseCallback);
	glutDisplayFunc(DisplayCallback);
	glutReshapeFunc(ReshapeCallback);

	Init::InitGlew::Init();
#if _DEBUG
	glEnable(GL_DEBUG_OUTPUT);

	glDebugMessageCallback(Core::debugCallback, NULL);
	// glDebugMessageCallback(ErrorCallback, (void*)NULL);
	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE,
		GL_DONT_CARE, 0, NULL, GL_TRUE);
#endif

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, 
		GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	PrintOpenGlInfo(window, context);
}

void InitGlut::Run()
{
	std::cout << "GLUT:\tRunning...\n";
	glutMainLoop();
}

void InitGlut::Close()
{
	std::cout << "GLUT:\tClosing.\n";
	glutLeaveMainLoop();
}

void InitGlut::IdleCallback()
{
	glutPostRedisplay();
}

void InitGlut::DisplayCallback()
{
	if (listener)
	{
		listener->NotifyBeginFrame();
		listener->NotifyDisplayFrame();
		glutSwapBuffers();
		listener->NotifyEndFrame();
	}
}

void InitGlut::ReshapeCallback(int width, int height)
{
	if (window.isResizeable)
	{
		if (listener)
		{
			listener->NotifyReshape(width, height, window.width, window.height);
		}
		window.width = width;
		window.height = height;
	}
}

void InitGlut::CloseCallback()
{
	Close();
}

void InitGlut::EnterFullscreen()
{
	glutFullScreen();
}

void InitGlut::ExitFullScreen()
{
	glutLeaveFullScreen();
}

void InitGlut::PrintOpenGlInfo(const Core::Window &window, const Core::Context &context)
{
	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* vendor = glGetString(GL_VENDOR);
	const unsigned char* version = glGetString(GL_VERSION);

	std::cout << "\t" << std::string(20, '*') << std::endl;
	std::cout << "GLUT:\tVendor: " << vendor << std::endl;
	std::cout << "GLUT:\tRenderer: " << renderer << std::endl;
	std::cout << "GLUT:\tVersion: " << version << std::endl;
}

void InitGlut::SetListener(Core::IListener*& iListener)
{
	listener = iListener;
}