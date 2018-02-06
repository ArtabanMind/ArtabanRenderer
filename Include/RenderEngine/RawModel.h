#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace ArtabanRenderer { namespace RenderEngine {

	class RawModel {
	public:
		RawModel(GLuint _vaoID, unsigned int _vertexCount);

		GLuint GetVAOID();

		unsigned int GetVertexCount();
	private:
		GLuint VAOID;
		unsigned int VertexCount;
	};
}}