
#include "RenderEngine/Loader.h"
#include <FreeImage.h>
#include <iostream>

namespace ArtabanRenderer { namespace RenderEngine {

	Loader::Loader()
	{

	}

	GLuint Loader::LoadVAO(float* _data, unsigned int _dataLength,
								unsigned int* _indies, unsigned int _indexLength,
								float* _texcoord, unsigned int _texCoordLength)
	{
		GLuint id = CreateVAO();
		BindIndicesBuffer(_indies, _indexLength);
		StoreDataInAttribList(0, 3, _dataLength, _data);
		StoreDataInAttribList(1, 2, _texCoordLength, _texcoord);
		UnbindVAO();
		VaoDic.push_back(id);
		return id;
	}

	GLuint Loader::LoadTexture(char const* _file)
	{
		FREE_IMAGE_FORMAT format = FreeImage_GetFileType(_file, 0);
		if (format == -1)
		{
			std::cout << "Could not find Image: " << _file << "- Aborting" << std::endl;
			exit(-1);
		}

		// unknown file format
		if (format == FIF_UNKNOWN)
		{
			format = FreeImage_GetFIFFromFilename(_file);
			if (!FreeImage_FIFSupportsReading(format))
			{
				std::cout << "Detected image format can not be read" << std::endl;
				exit(-1);
			}
		}

		FIBITMAP* bitmap = FreeImage_Load(format, _file);
		int bitsPerPixel = FreeImage_GetBPP(bitmap);
		FIBITMAP* bitmap32;
		if (bitsPerPixel == 32)
		{
			std::cout << "Source Image has " << bitsPerPixel << " bits per pixel. Skip Conversion" << std::endl;
			bitmap32 = bitmap;
		}
		else
		{
			std::cout << "Source Image has " << bitsPerPixel << "bits per pixel. Converting to 32-bit colour" << std::endl;
			bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
		}

		int width = FreeImage_GetWidth(bitmap32);
		int height = FreeImage_GetHeight(bitmap32);

		GLubyte* data = FreeImage_GetBits(bitmap32);
		GLuint textureID;
		
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		// copy texture data to GPU
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGBA,
			width,
			height,
			0,
			GL_BGRA,
			GL_UNSIGNED_BYTE,
			data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		glBindTexture(GL_TEXTURE_2D, 0);

		GLenum glError = glGetError();
		if (glError)
		{
			std::cout << "There was an error loading the texture : " << _file << std::endl;
			switch (glError)
			{
			case GL_INVALID_ENUM:
				std::cout << "Invalid enum. " << std::endl;
				break;
			case GL_INVALID_VALUE:
				std::cout << "Invalid value. " << std::endl;
				break;
			case GL_INVALID_OPERATION:
				std::cout << "Invalid operation. " << std::endl;
				break;
			}
		}

		FreeImage_Unload(bitmap32);
		if (bitsPerPixel != 32)
		{
			FreeImage_Unload(bitmap);
		}

		textureDic.push_back(textureID);

		return textureID;
	}

	Loader::~Loader()
	{
		for (int i = 0; i < VaoDic.size(); i++)
		{
			glDeleteVertexArrays(1, &VaoDic[i]);
		}

		for (int j = 0; j < VboDic.size(); j++)
		{
			glDeleteBuffers(1, &VboDic[j]);
		}

		for (int k = 0; k < textureDic.size(); k++)
		{
			glDeleteTextures(1, &textureDic[k]);
		}
	}

	GLuint Loader::CreateVAO()
	{
		GLuint id;
		glGenVertexArrays(1, &id);
		glBindVertexArray(id);
		return id;
	}

	void Loader::BindIndicesBuffer(unsigned int* _indies, unsigned int _length)
	{
		GLuint vboID;
		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, _length * sizeof(float), _indies, GL_STATIC_DRAW);
	}

	void Loader::StoreDataInAttribList(unsigned int _attrib, unsigned int _componentCount, unsigned int _dataLength, float* _data)
	{
		GLuint vboID;
		glGenBuffers(1, &vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, _dataLength * sizeof(float), _data, GL_STATIC_DRAW);
		glVertexAttribPointer(_attrib, _componentCount, GL_FLOAT, GL_FALSE, 0, (const void*)NULL);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		VboDic.push_back(vboID);
	}

	void Loader::UnbindVAO()
	{
		glBindVertexArray(0);
	}

}}