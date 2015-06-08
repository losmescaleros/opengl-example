#include <Rendering/Models/Triangle.h>

using namespace Rendering;
using namespace Models;

Triangle::Triangle(){}

Triangle::~Triangle(){}

void Triangle::Create()
{
	GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(glm::vec3(0.25, -0.25, 0.0),
		glm::vec4(1.0, 0.0, 0.0, 1.0))); // red
	vertices.push_back(Vertex(glm::vec3(-0.25, -0.25, 0.0),
		glm::vec4(0.0, 1.0, 0.0, 1.0))); // green
	vertices.push_back(Vertex(glm::vec3(0.25, 0.25, 0.0),
		glm::vec4(0.0, 0.0, 1.0, 1.0))); // blue

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 3, &vertices[0], GL_STATIC_DRAW);
	// Tell OpenGL about our position vertices, which are at the start of a Vertex (offset 0)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), MEMBER_OFFSET(Vertex, position));
	// Tell OpenGL about our color vertices, which are offset 3*sizeof(float) from start of Vertex
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), MEMBER_OFFSET(Vertex, color));
	glBindVertexArray(0);
	
	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Triangle::Update()
{

}

void Triangle::Draw()
{
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}