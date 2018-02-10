#pragma once

#include "Default.h"
#include "RenderEngine/Camera.h"

namespace ArtabanRenderer { namespace Shaders {
	using glm::vec3;
	using glm::mat4;
	using namespace RenderEngine;

	class ShaderProgram {

	public:
		ShaderProgram();
		ShaderProgram(const char* _vertexPath, const char* _fragmentPath);
		virtual ~ShaderProgram();

		bool Init();
		void Start();
		void Stop();

	protected:
		virtual void BindAttributes() = 0;
		virtual void GetAllUniformLocations() = 0;

		
		void BindAttributes(GLuint _idx, GLchar* _name);

		void LoadFloat(int location, float value);

		void LoadVector(int location, vec3 vector);

		void LoadBoolean(int location, bool value);

		void LoadMatrix(int locatiton, const mat4& matrix);

		GLuint GetUniformLocation(GLchar* _uniformName);
	
		glm::mat4 CreateProjectionMatrix();

		glm::mat4 CreateViewMatrix(GameCamera* cam);

	private:
		const char* VertPath;
		const char* FragPath;

		GLuint ShaderProg;
		GLuint VertexHandle;
		GLuint FragmentHandle;

		const float FOV = 70.f;
		const float NEAR = 0.1f;
		const float FAR = 1000.f;
		const float ASPECT = 16.f / 9.f;
		

		bool LoadShader(const char* _path, int _type, GLuint& handle);
	};

}}