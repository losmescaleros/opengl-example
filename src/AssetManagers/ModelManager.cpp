#include <AssetManagers/ModelManager.h>

using namespace AssetManagers;
using namespace Rendering;

ModelManager::ModelManager()
{
	/*Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(ShaderManager::GetShader("colorShader"));
	triangle->Create();
	modelList["triangle"] = triangle;

	Models::Quad* quad = new Models::Quad();
	quad->SetProgram(ShaderManager::GetShader("colorShader"));
	quad->Create();
	modelList["quad"] = quad;*/

	Models::Cube* cube = new Models::Cube();
	cube->SetProgram(ShaderManager::GetShader("colorShaderMvp"));
	cube->Create();
	modelList["cube"] = cube;
}

/// <summary>
/// Finalizes an instance of the <see cref="ModelManager"/> class.
/// </summary>
ModelManager::~ModelManager()
{
	for (auto model : modelList)
	{
		delete model.second;
	}
	modelList.clear();
}

/// <summary>
/// Deletes the model.
/// </summary>
/// <param name="modelName">Name of the model.</param>
void ModelManager::DeleteModel(const std::string& modelName)
{
	IGameObject* model = modelList[modelName];
	model->Destroy();
	modelList.erase(modelName);
}

/// <summary>
/// Gets the model.
/// </summary>
/// <param name="modelName">Name of the model.</param>
/// <returns></returns>
const IGameObject& ModelManager::GetModel(const std::string& modelName)
{
	return (*modelList.at(modelName));
}

/// <summary>
/// Updates this instance's models
/// </summary>
void ModelManager::Update()
{
	for (auto model : modelList)
	{
		model.second->Update();
	}
}

void ModelManager::Draw()
{
	for (auto model : modelList)
	{
		model.second->Draw();
	}
}

