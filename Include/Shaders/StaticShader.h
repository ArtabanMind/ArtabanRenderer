#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "ShaderProgram.h"

namespace ArtabanRenderer { namespace Shaders {

	class StaticShader : public ShaderProgram {

	public:
		StaticShader(const char* _vertPath, const char* _fragPath);
		~StaticShader();

		void LoadTransformMatrix(const mat4& _mat);
		void LoadProjectionMatrix(const mat4& _mat);

		template<typename T>
		void LoadMatrix(T &_mat, GLuint param);

	protected:
		void BindAttributes() override;
		void GetAllUniformLocations() override;

	private:
		GLuint MatrixLocation;
		GLuint ProjectionMatLocation;
	};


}}