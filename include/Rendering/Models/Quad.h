#pragma once
#include <Rendering/Models/Model.h>

namespace Rendering
{
	namespace Models
	{
		class Quad : public Models::Model
		{
		public:
			Quad();
			~Quad();

			void Create();
			virtual void Draw(Camera* camera) override final;
			virtual void Update() override final;
		};
	}
}