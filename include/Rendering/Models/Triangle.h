#pragma once
#include <Rendering/Models/Model.h>

namespace Rendering
{
	namespace Models
	{
		class Triangle : public Model
		{
		public:
			Triangle();
			~Triangle();

			void Create();
			virtual void Update() override final;
			virtual void Draw(Camera* camera) override final;
		};
	}
}