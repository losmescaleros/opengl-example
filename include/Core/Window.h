# pragma once

#include <string>

namespace Core
{
	struct Window
	{
		std::string name;
		int width, height;
		int pos_x, pos_y;
		bool isResizeable;

		Window()
		{
			name = "OpenGL Window";
			width = 800;
			height = 600;
			pos_x = 300;
			pos_y = 300;
			isResizeable = true;
		}

		Window(std::string name, int p_x, int p_y, int w, int h, bool isResizeable)
		{
			this->name = name;
			this->pos_x = p_x;
			this->pos_y = p_y;
			this->width = w;
			this->height = h;
			this->isResizeable = isResizeable;
		}

		Window(const Window& window)
		{
			name = window.name;
			pos_x = window.pos_x;
			pos_y = window.pos_y;
			width = window.width;
			height = window.height;
			isResizeable = window.isResizeable;
		}

		void operator=(const Window& window)
		{
			name = window.name;
			pos_x = window.pos_x;
			pos_y = window.pos_y;
			width = window.width;
			height = window.height;
			isResizeable = window.isResizeable;
		}
	};
}