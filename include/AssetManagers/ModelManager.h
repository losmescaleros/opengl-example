#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <AssetManagers/ShaderManager.h>
#include <Rendering/IGameObject.h>
#include <Rendering/Models/Triangle.h>
#include <Rendering/Models/Quad.h>
#include <Rendering/Models/Cube.h>
#include <map>

using namespace Rendering;

namespace AssetManagers
{		
	/// <summary>
	/// Manages models
	/// </summary>
	class ModelManager
	{
	public:
		ModelManager();
		~ModelManager();

		void Draw();
		void Update();
		void DeleteModel(const std::string &modelName);
		const IGameObject& GetModel(const std::string &modelName);
	private:		
		/// <summary>
		/// List of models managed
		/// </summary>
		std::map<std::string, IGameObject*> modelList;
	};
}
