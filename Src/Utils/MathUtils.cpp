

#include "Utils/MathUtils.h"


namespace ArtabanRenderer { namespace MathUtils {

	mat4 Math::CreateTransformMatrix(vec3 translate, vec3 rotation, vec3 scale)
	{
		mat4 retMatrix(1.0f);
		retMatrix = glm::translate(retMatrix, translate);
		retMatrix = glm::rotate(retMatrix, rotation.x, vec3(1.f, 0.f, 0.f));
		retMatrix = glm::rotate(retMatrix, rotation.y, vec3(0.f, 1.f, 0.f));
		retMatrix = glm::rotate(retMatrix, rotation.z, vec3(0.f, 0.f, 1.f));
		glm::mat4 scaleMat4 = glm::scale(mat4(1.0f), scale);
		//retMatrix = glm::scale(retMatrix, scale);
		return retMatrix * scaleMat4;
		//return retMatrix;
	}

}}