#include <Rendering/Models/Triangle.h>

using namespace Rendering;
using namespace Models;

Triangle::Triangle(){}

Triangle::~Triangle(){}

void Triangle::Create()
{
	GLuint vao;
	GLuint vbo;
	GLuint indexBuffer;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	vertices.push_back(Vertex(glm::vec3(1, -1, 1),
		glm::vec4(1.0, 0.0, 0.0, 1.0))); // red
	vertices.push_back(Vertex(glm::vec3(-1, -1, 1),
		glm::vec4(0.0, 1.0, 0.0, 1.0))); // green
	vertices.push_back(Vertex(glm::vec3(1, 1, 1),
		glm::vec4(0.0, 0.0, 1.0, 1.0))); // blue
	// Front-facing triangles must be in counter-clockwise order
	GLuint indices[3] = { 2, 1, 0 };

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 3, &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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

void Triangle::Draw(Camera* camera)
{
	glUseProgram(program);
	glBindVertexArray(vao);
	GLint uniformMvp = -1;
	uniformMvp = glGetUniformLocation(program, "MVP");
	glm::mat4 mvp = camera->GetProjectionMatrix() * camera->GetViewMatrix() * glm::toMat4(camera->GetRotation());
	glUniformMatrix4fv(uniformMvp, 1, GL_FALSE, glm::value_ptr(mvp));
	// glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
}