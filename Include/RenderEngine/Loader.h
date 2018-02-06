#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <vector>



namespace ArtabanRenderer { namespace RenderEngine {
	class Loader {
	public:
		Loader();
		~Loader();

		GLuint LoadVAO(float* _data, unsigned int _dataLength,
			unsigned int* _indies, unsigned int _indexLength,
			float* _texCoord, unsigned int _texCoordLength);

		GLuint LoadTexture(char const* _file);

	private:
		std::vector<GLuint> VaoDic;
		std::vector<GLuint> VboDic;
		std::vector<GLuint> textureDic;


		GLuint CreateVAO();
		void BindIndicesBuffer(unsigned int* _indies, unsigned int _length);

		void StoreDataInAttribList(unsigned int _attrib, unsigned int componentCount, unsigned int _dataLength, float* data);

		void UnbindVAO();
	};
}}