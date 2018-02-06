
#include "Shaders/ShaderProgram.h"
#include "Utils/FileUtils.h"
#include <iostream>
#include <vector>


namespace ArtabanRenderer { namespace Shaders {
	
	ShaderProgram::ShaderProgram()
	{
		std::cout << "ShaderProgaram Costructor" << std::endl;
	}

	ShaderProgram::ShaderProgram(const char* _vertPath, const char* _fragPath)
		: VertPath(_vertPath), FragPath(_fragPath)
	{
		std::cout << "ShaderProgaram Param Constructor" << std::endl;
	}

	ShaderProgram::~ShaderProgram()
	{
		glDetachShader(ShaderProg, VertexHandle);
		glDetachShader(ShaderProg, FragmentHandle);
		glDeleteShader(VertexHandle);
		glDeleteShader(FragmentHandle);
		glDeleteProgram(ShaderProg);
	}

	bool ShaderProgram::Init()
	{

		// LoadShader * 2
		if (!LoadShader(VertPath, GL_VERTEX_SHADER, VertexHandle))
			return false;
		if (!LoadShader(FragPath, GL_FRAGMENT_SHADER, FragmentHandle))
			return false;
		// glCreateProgram
		ShaderProg = glCreateProgram();
		// glAttachShader
		glAttachShader(ShaderProg, VertexHandle);
		glAttachShader(ShaderProg, FragmentHandle);
		BindAttributes();
		// glLinkProgram
		glLinkProgram(ShaderProg);
		glValidateProgram(ShaderProg);
		GetAllUniformLocations();

		// glGetProgramiv
		GLint status;
		glGetProgramiv(ShaderProg, GL_LINK_STATUS, &status);
		if (status == GL_FALSE)
		{
			fprintf(stderr, "Failed to link shader program");
			GLint logLen;
			glGetProgramiv(ShaderProg, GL_INFO_LOG_LENGTH, &logLen);
			if (logLen > 0)
			{
				char* log = (char*)malloc(logLen);
				GLsizei written;
				glGetProgramInfoLog(ShaderProg, logLen, &written, log);
				fprintf(stderr, "Program log: \n%s", log);
				free(log);
			}

			return GL_FALSE;
		}

		return GL_TRUE;
	}

	void ShaderProgram::Start()
	{
		glUseProgram(ShaderProg);
	}

	void ShaderProgram::Stop()
	{
		glUseProgram(0);
	}

	bool ShaderProgram::LoadShader(const char* _path, int _type, GLuint& handle)
	{
		// glCreateShader
		handle = glCreateShader(_type);
		// read file source
		std::string source = read_file_stream(_path);
		// glShaderSource
		const GLchar* codeArray[] = { source.c_str() };
		glShaderSource(handle, 1, codeArray, NULL);
		// glCompileShader
		glCompileShader(handle);
		// glGetShaderiv
		GLint result;
		glGetShaderiv(handle, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			GLsizei written;
			glGetShaderInfoLog(handle, length, &written, &error[0]);
			
			glDeleteShader(handle);
			return false;
		}

		return true;
	}

	void ShaderProgram::AssignShaderPath(const char* _vPath, const char* _fPath)
	{
		VertPath = _vPath;
		FragPath = _fPath;
	}

	/*void ShaderProgram::BindAttributes()
	{

	}*/

	void ShaderProgram::BindAttributes(GLuint _idx, GLchar* _name)
	{
		glBindAttribLocation(ShaderProg, _idx, _name);
	}

	void ShaderProgram::LoadFloat(int location, float value)
	{
		glUniform1f(location, value);
	}

	void ShaderProgram::LoadBoolean(int location, bool value)
	{
		float saveVal = 0.f;
		if (value)
		{
			saveVal = 1.0f;
		}

		glUniform1f(location, saveVal);
	}

	void ShaderProgram::LoadVector(int location, vec3 vector)
	{
		glUniform3f(location, vector.x, vector.y, vector.z);
	}

	void ShaderProgram::LoadMatrix(int location, const mat4& matrix)
	{
		ShaderMatrix = matrix;
		
		glUniformMatrix4fv(location, 1, false, &matrix[0][0]);
		
	}

	GLuint ShaderProgram::GetUniformLocation(GLchar* _uniformName)
	{
		return glGetUniformLocation(ShaderProg, _uniformName);
	}

}}