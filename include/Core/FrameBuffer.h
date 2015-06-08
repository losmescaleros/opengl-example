#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

namespace Core
{
	struct FrameBuffer
	{
		unsigned int flags;
		bool msaa;

		FrameBuffer()
		{
			flags = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH;
			msaa = false;
		}

		FrameBuffer(bool color, bool depth, bool stencil, bool msaa)
		{
			this->flags = GLUT_DOUBLE; //this is a must
			if (color)
				this->flags |= GLUT_RGBA | GLUT_ALPHA;
			if (depth)
				this->flags |= GLUT_DEPTH;
			if (stencil)
				this->flags |= GLUT_STENCIL;
			if (msaa)
				this->flags |= GLUT_MULTISAMPLE;
			this->msaa = msaa;
		}

		FrameBuffer(const FrameBuffer& other)
		{
			this->flags = other.flags;
			this->msaa = other.msaa;
		}

		void operator=(const FrameBuffer& other)
		{
			this->flags = other.flags;
			this->msaa = other.msaa;
		}
	};
}