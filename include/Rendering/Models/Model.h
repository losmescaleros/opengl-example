#pragma once
#include <vector>
#include <Rendering/IGameObject.h>
#include <Rendering/Camera.h>
#define MEMBER_OFFSET(s,m) ((char*)NULL + (offsetof(s,m)))
#define BUFFER_OFFSET(offset) ((void*)(offset))

namespace Rendering
{
	namespace Models
	{
		class Model : public IGameObject
		{
		public:
			Model();
			virtual ~Model();
			virtual void Draw(Camera* camera) override;
			virtual void Update() override;
			virtual void SetProgram(GLuint shaderName) override;
			virtual void Destroy() override;
			virtual GLuint GetVao() const override;
			virtual const std::vector<GLuint>& GetVbos() const override;

		protected:
			GLuint vao;
			GLuint program;
			std::vector<GLuint> vbos;
			std::vector<Vertex> vertices;
		};
	}
}