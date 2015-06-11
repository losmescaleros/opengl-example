#pragma once
#include <Rendering/Models/Model.h>

namespace Rendering
{
	namespace Models
	{
		class Cube : public Models::Model
		{
		public:
			Cube();
			~Cube();

			void Create();
			virtual void Draw(Camera* camera) override final;
			virtual void Update() override final;
		};
	}
}