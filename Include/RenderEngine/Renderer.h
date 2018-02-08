#pragma once

#include "Default.h"
#include "RawModel.h"
#include "RenderEngine/TexturedModel.h"
#include "Entities/Entity.h"
#include "Utils/MathUtils.h"
#include "Shaders/StaticShader.h"
#include "Camera.h"

namespace ArtabanRenderer { namespace RenderEngine {
	using glm::mat4;
	using Entities::Entity;
	using Shaders::StaticShader;
	using MathUtils::Math;

	class Renderer {
	public:
		Renderer(StaticShader* shader);

		void Prepare();

		void Render(Entity* _entity, StaticShader* _shader);

		void Cleanup();

	private:
		
		StaticShader* ShaderHandle;

		mat4 ProjectionMatrix;
		mat4 ViewMatrix;

		const float FOV = 70.f;
		const float NEAR = 0.1f;
		const float FAR = 1000.f;
		const float ASPECT = 16.f / 9.f;

		void createProjectionMatrix();
		void createViewMatrix(Camera& cam);
	};

}}