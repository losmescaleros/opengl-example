#pragma once

#include <glm\glm.hpp>

namespace Rendering
{
	/// <summary>
	/// Vertex in 3-dimensional space
	/// </summary>
	struct Vertex
	{
		glm::vec3 position;
		glm::vec4 color;

		Vertex(const glm::vec3 &pos, const glm::vec4 &col)
		{
			position = pos;
			color = col;
		}

		Vertex(){}
	};
}
