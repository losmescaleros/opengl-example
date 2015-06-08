#include <Rendering/Models/Quad.h>

using namespace Rendering;
using namespace Models;

Quad::Quad(){}

Quad::~Quad(){}

void Quad::Create()
{
	GLuint vao;
	GLuint vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(glm::vec3(-0.25, 0.5, 0.0),//pos
		glm::vec4(1, 0, 0, 1)));   //color
	vertices.push_back(Vertex(glm::vec3(-0.25, 0.75, 0.0),//pos
		glm::vec4(0, 0, 0, 1)));   //color
	vertices.push_back(Vertex(glm::vec3(0.25, 0.5, 0.0),  //pos
		glm::vec4(0, 1, 0, 1)));   //color
	//4th vertex
	vertices.push_back(Vertex(glm::vec3(0.25, 0.75, 0.0),//pos
		glm::vec4(0, 0, 1, 1)));   //color
	//nothing different from Triangle model
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);            //here we have 4
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), MEMBER_OFFSET(Vertex, position));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
		sizeof(Vertex),
		MEMBER_OFFSET(Vertex, color));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
}

void Quad::Update(){}

void Quad::Draw()
{
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}