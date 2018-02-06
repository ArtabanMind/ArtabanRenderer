

#include "RenderEngine/RawModel.h"

namespace ArtabanRenderer { namespace RenderEngine {

	RawModel::RawModel(GLuint _vaoID, unsigned int _vertexCount)
	{
		VAOID = _vaoID;
		VertexCount = _vertexCount;
	}

	// This brakes protection of private member variable
	GLuint RawModel::GetVAOID()
	{
		return VAOID;
	}

	unsigned int RawModel::GetVertexCount()
	{
		return VertexCount;
	}
}}