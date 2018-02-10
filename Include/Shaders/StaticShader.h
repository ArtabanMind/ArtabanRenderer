#pragma once

#include "Default.h"
#include "ShaderProgram.h"
#include "RenderEngine/Camera.h"

namespace ArtabanRenderer { namespace Shaders {

	class StaticShader : public ShaderProgram {

	public:
		StaticShader(const char* _vertPath, const char* _fragPath);
		~StaticShader();

		void LoadTransformMatrix(const mat4& _mat);
		void LoadProjectionMatrix();
		void LoadViewMatrix(GameCamera* _cam);

		template<typename T>
		void GeneralLoadMatrix(T &_mat, GLuint param)
		{
			if (param == 0)
			{
				this->LoadMatrix(ProjectionMatLocation, _mat);
			}
			else if (param == 1)
			{
				this->LoadMatrix(ViewMatLocation, _mat);
			}
			else
			{
				this->LoadMatrix(MatrixLocation, _mat);
			}
		}

	protected:
		void BindAttributes() override;
		void GetAllUniformLocations() override;

	private:
		GLuint MatrixLocation;
		GLuint ProjectionMatLocation;
		GLuint ViewMatLocation;
	};


}}