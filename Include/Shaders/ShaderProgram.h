#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace ArtabanRenderer { namespace Shaders {
	using glm::vec3;
	using glm::mat4;

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

		void AssignShaderPath(const char* _vPath, const char* _fPath);
		void BindAttributes(GLuint _idx, GLchar* _name);

		void LoadFloat(int location, float value);

		void LoadVector(int location, vec3 vector);

		void LoadBoolean(int location, bool value);

		void LoadMatrix(int locatiton, const mat4& matrix);

		GLuint GetUniformLocation(GLchar* _uniformName);
	
	private:
		const char* VertPath;
		const char* FragPath;

		GLuint ShaderProg;
		GLuint VertexHandle;
		GLuint FragmentHandle;

		mat4 ShaderMatrix;

		bool LoadShader(const char* _path, int _type, GLuint& handle);
	};

}}