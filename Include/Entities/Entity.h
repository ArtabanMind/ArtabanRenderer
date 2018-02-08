#pragma once

#include "Default.h"
#include "Utils/MathUtils.h"
#include "RenderEngine/TexturedModel.h"
#include "RenderEngine/RawModel.h"

namespace ArtabanRenderer { namespace Entities {
	using glm::vec3;
	using glm::mat4;
	using RenderEngine::TexturedModel;
	using MathUtils::Math;

	class Entity {
	private:
		// Cache Variable
		GLuint modelVaoId;
		GLuint modelTextureId;
		unsigned int modelVertexNum;

		TexturedModel* model;
		vec3 position;
		vec3 rotation;
		vec3 scale;
		mat4 transformation;

		const vec3 upVec = vec3(0.f, 1.f, 0.f);
		const vec3 rightVec = vec3(1.f, 0.f, 0.f);
		const vec3 forwardVec = vec3(0.f, 0.f, 1.f);

	public:
		Entity();
		Entity(TexturedModel* _model, vec3& position, vec3& rotation, vec3& scale);

		void IncreasePosition(const vec3& delta);
		void IncreaseRotation(float dx, float dy, float dz);
		TexturedModel* GetModel();
		// Getter, Setter for position, rotation, scale

		vec3 GetPosition();
		void SetPosition(const vec3& _pos);

		vec3 GetRotation();
		void SetRotation(const vec3& _rot);

		vec3 GetScale();
		void SetScale(const vec3& _scale);

		mat4 GetTransformation();

		unsigned int GetModelVertexCount();
		GLuint GetModelTextureID();
		GLuint GetModelVAOID();

	};

}}