#pragma once

#include "Default.h"

namespace ArtabanRenderer { namespace MathUtils {
	using glm::vec3;
	using glm::mat4;

	class Math {
	public:
		static mat4 CreateTransformMatrix(vec3 translation, vec3 rotation, vec3 scale);
	};

}}