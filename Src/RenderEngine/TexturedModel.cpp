
#include "RenderEngine/TexturedModel.h"

namespace ArtabanRenderer { namespace RenderEngine {

	TexturedModel::TexturedModel(RawModel* _model, GLuint _id)
		: rawModel(_model), textureID(_id)
	{

	}

	RawModel* TexturedModel::GetRawModel()
	{
		return rawModel;
	}

	GLuint TexturedModel::GetTextureID()
	{
		return textureID;
	}
	
}}