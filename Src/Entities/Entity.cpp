#include "Entities/Entity.h"

namespace ArtabanRenderer { namespace Entities {

	Entity::Entity()
		: model(nullptr), position(vec3(1.0f)), rotation(vec3(1.0f)), scale(vec3(1.0f))
		//, transformation(Math::CreateTransformMatrix(rotation, position, scale))
	{
		transformation = Math::CreateTransformMatrix(position, rotation, scale);
		modelTextureId = model->GetTextureID();
		modelVaoId = model->GetRawModel()->GetVAOID();
		modelVertexNum = model->GetRawModel()->GetVertexCount();
	}

	Entity::Entity(TexturedModel* _model, vec3& _position, vec3& _rotation, vec3& _scale)
		: model(_model), position(_position), rotation(_rotation), scale(_scale)
		//,transformation(Math::CreateTransformMatrix(rotation, position, scale))
	{
		transformation = Math::CreateTransformMatrix(position, rotation, scale);
		modelTextureId = model->GetTextureID();
		modelVaoId = model->GetRawModel()->GetVAOID();
		modelVertexNum = model->GetRawModel()->GetVertexCount();
	}

	void Entity::IncreasePosition(const vec3& delta)
	{
		position += delta;
		transformation = glm::translate(transformation, delta);
	}

	void Entity::IncreaseRotation(float dx, float dy, float dz)
	{
		
		if (dx != 0.f)
		{
			rotation.x += dx;
			transformation = glm::rotate(transformation, dx, rightVec);
		}
		if (dy != 0.f)
		{
			rotation.y += dy;
			transformation = glm::rotate(transformation, dy, upVec);
		}
		if (dz != 0.f)
		{
			rotation.z += dz;
			transformation = glm::rotate(transformation, dz, forwardVec);
		}
	}

	TexturedModel* Entity::GetModel()
	{
		return model;
	}

	vec3 Entity::GetPosition()
	{
		return position;
	}

	void Entity::SetPosition(const vec3& _pos)
	{
		position = _pos;
	}

	vec3 Entity::GetRotation()
	{
		return rotation;
	}

	void Entity::SetRotation(const vec3& _rot)
	{
		rotation = _rot;
	}

	vec3 Entity::GetScale()
	{
		return scale;
	}

	void Entity::SetScale(const vec3& _scale)
	{
		scale = _scale;
	}

	mat4 Entity::GetTransformation()
	{
		return transformation;
	}

	GLuint Entity::GetModelTextureID()
	{
		return modelTextureId;
	}

	GLuint Entity::GetModelVAOID()
	{
		return modelVaoId;
	}

	unsigned int Entity::GetModelVertexCount()
	{
		return modelVertexNum;
	}
}}