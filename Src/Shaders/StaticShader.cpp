
#include "Shaders/StaticShader.h"
#include <iostream>
namespace ArtabanRenderer { namespace Shaders {

	StaticShader::StaticShader(const char* _vert, const char* _frag)
		: ShaderProgram(_vert, _frag)
	{
		
	}

	StaticShader::~StaticShader()
	{
		std::cout << "StaticShader Deleted" << std::endl;
	}

	void StaticShader::BindAttributes()
	{
		ShaderProgram::BindAttributes(0, "position");
		ShaderProgram::BindAttributes(1, "textureCoords");
	}

	void StaticShader::GetAllUniformLocations()
	{
		MatrixLocation = ShaderProgram::GetUniformLocation("TransformationMatrix");
		ProjectionMatLocation = ShaderProgram::GetUniformLocation("ProjectionMatrix");
	}

	void StaticShader::LoadTransformMatrix(const mat4& _mat)
	{
		ShaderProgram::LoadMatrix(MatrixLocation, _mat);
	}

	void StaticShader::LoadProjectionMatrix(const mat4& _mat)
	{
		ShaderProgram::LoadMatrix(ProjectionMatLocation, _mat);
	}

	template<typename T>
	void StaticShader::LoadMatrix(T &_mat, GLuint param)
	{
		if (param == 0)
		{
			ShaderProgram::LoadMatrix(ProjectionMatLocation, _mat);
		}
		else
		{
			ShaderProgram::LoadMatrix(MatrixLocation, _mat);
		}
	}
}}