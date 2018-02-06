
#include "Shaders/StaticShader.h"
#include <iostream>
namespace ArtabanRenderer { namespace Shaders {

	StaticShader::StaticShader(const char* _vert, const char* _frag)
	{
		//ShaderProgram(_vert, _frag);
		AssignShaderPath(_vert, _frag);
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
	}

	void StaticShader::LoadTransformMatrix(const mat4& _mat)
	{
		ShaderProgram::LoadMatrix(MatrixLocation, _mat);
		mat4 matrix;
		

	}
}}