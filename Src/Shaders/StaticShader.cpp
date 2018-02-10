
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
		ViewMatLocation = ShaderProgram::GetUniformLocation("ViewMatrix");
	}

	void StaticShader::LoadTransformMatrix(const mat4& _mat)
	{
		ShaderProgram::LoadMatrix(MatrixLocation, _mat);
	}

	void StaticShader::LoadProjectionMatrix()
	{
		mat4 _mat = ShaderProgram::CreateProjectionMatrix();
		ShaderProgram::LoadMatrix(ProjectionMatLocation, _mat);
	}

	void StaticShader::LoadViewMatrix(GameCamera* _cam)
	{
		mat4 _mat = ShaderProgram::CreateViewMatrix(_cam);
		ShaderProgram::LoadMatrix(ViewMatLocation, _mat);
	}

}}