#pragma once

#include "Default.h"
#include "RawModel.h"
#include "RenderEngine/TexturedModel.h"
#include "Entities/Entity.h"
#include "Utils/MathUtils.h"
#include "Shaders/StaticShader.h"

namespace ArtabanRenderer { namespace RenderEngine {
	using glm::mat4;
	using Entities::Entity;
	using Shaders::StaticShader;
	using MathUtils::Math;

	class Renderer {
	public:
		Renderer();

		void Prepare(Entity* _entity, StaticShader* _shader);

		void Render();

		void Cleanup();

	private:
		Entity* CurrentModel;
		StaticShader* ShaderHandle;
		
	};

}}