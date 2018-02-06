#pragma once

#include <gl/glew.h>
#include "RawModel.h"


namespace ArtabanRenderer { namespace RenderEngine {

	class TexturedModel {
	public:
		TexturedModel(RawModel* _rawModel, GLuint _id);

		GLuint GetTextureID();

		RawModel* GetRawModel();

	private:
		GLuint textureID;
		RawModel* rawModel;
	};

}}
