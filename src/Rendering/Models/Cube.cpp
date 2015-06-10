#include <Rendering/Models/Cube.h>
#include <Rendering/Camera.h>

using namespace Rendering;
using namespace Models;

Cube::Cube(){}

Cube::~Cube(){}

void Cube::Create()
{
	GLuint vao;
	GLuint vbo;
	GLuint indexBuffer;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	/*std::vector<Vertex> vertices{
		Vertex(glm::vec3(1, 1, 1), glm::vec4(1, 1, 1, 1)),
		Vertex(glm::vec3(-1, 1, 1), glm::vec4(0, 1, 1, 1)),
		Vertex(glm::vec3(-1, -1, 1), glm::vec4(0, 0, 1, 1)),
		Vertex(glm::vec3(1, -1, 1), glm::vec4(1, 0, 1, 1)),
		Vertex(glm::vec3(1, -1, -1), glm::vec4(1, 0, 0, 1)),
		Vertex(glm::vec3(-1, -1, -1), glm::vec4(0, 0, 0, 1)),
		Vertex(glm::vec3(-1, 1, -1), glm::vec4(0, 1, 0, 1)),
		Vertex(glm::vec3(1, 1, -1), glm::vec4(1, 1, 0, 1))
	};
	std::vector<GLuint> indices{
		0, 1, 2, 2, 3, 0,           // Front face
		7, 4, 5, 5, 6, 7,           // Back face
		6, 5, 2, 2, 1, 6,           // Left face
		7, 0, 3, 3, 4, 7,           // Right face
		7, 6, 1, 1, 0, 7,           // Top face
		3, 2, 5, 5, 4, 3
	};*/
	Vertex vertices[8] = {
			{ glm::vec3(1, 1, 1), glm::vec4(1, 1, 1, 1) }, // 0
			{ glm::vec3(-1, 1, 1), glm::vec4(0, 1, 1, 1) }, // 1
			{ glm::vec3(-1, -1, 1), glm::vec4(0, 0, 1, 1) }, // 2
			{ glm::vec3(1, -1, 1), glm::vec4(1, 0, 1, 1) }, // 3
			{ glm::vec3(1, -1, -1), glm::vec4(1, 0, 0, 1) }, // 4
			{ glm::vec3(-1, -1, -1), glm::vec4(0, 0, 0, 1) }, // 5
			{ glm::vec3(-1, 1, -1), glm::vec4(0, 1, 0, 1) }, // 6
			{ glm::vec3(1, 1, -1), glm::vec4(1, 1, 0, 1) }, // 7
	};
	GLuint indices[36] = {
		0, 1, 2, 2, 3, 0,           // Front face
		7, 4, 5, 5, 6, 7,           // Back face
		6, 5, 2, 2, 1, 6,           // Left face
		7, 0, 3, 3, 4, 7,           // Right face
		7, 6, 1, 1, 0, 7,           // Top face
		3, 2, 5, 5, 4, 3            // Bottom face
	};

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

void Cube::Draw()
{
	glUseProgram(program);
	glBindVertexArray(vao);
	float a[16] = {
		1.299, 0, 0, 0,
		0, 1.732, 0, 0,
		0, 0, -1.002, -1,
		0, 0, 9.82, 10
	};
	glm::mat4 mvp = glm::make_mat4(a);
	GLint uniformMvp = -1;
	uniformMvp = glGetUniformLocation(program, "MVP");
	glUniformMatrix4fv(uniformMvp, 1, GL_FALSE, glm::value_ptr(mvp));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, BUFFER_OFFSET(0));
}

void Cube::Update()
{

}