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
	using namespace Shaders;
	using MathUtils::Math;

	class Renderer {
	public:
		Renderer(StaticShader* shader, GameCamera* cam, Entity* _entity);

		void Prepare();

		void Render(Entity* _entity, StaticShader* _shader, GameCamera* _cam);

		void Cleanup();
		
	};

}}