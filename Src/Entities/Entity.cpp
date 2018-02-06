#include "Entities/Entity.h"

namespace ArtabanRenderer { namespace Entities {

	Entity::Entity()
		: model(nullptr), position(vec3(1.0f)), rotation(vec3(1.0f)), scale(vec3(1.0f))
	{
		transformation = Math::CreateTransformMatrix(rotation, position, scale);
	}

	Entity::Entity(TexturedModel* _model, vec3& _position, vec3& _rotation, vec3& _scale)
		: model(_model), position(_position), rotation(_rotation), scale(_scale)
	{
		transformation = Math::CreateTransformMatrix(rotation, position, scale);
	}

	void Entity::IncreasePosition(const vec3& delta)
	{
		position += delta;
		transformation = glm::translate(transformation, delta);
	}

	void Entity::IncreaseRotation(const vec3& delta)
	{
		rotation += delta;
		transformation = glm::rotate(transformation, delta.x, vec3(1.f, 0.f, 0.f));
		transformation = glm::rotate(transformation, delta.y, vec3(0.f, 1.f, 0.f));
		transformation = glm::rotate(transformation, delta.z, vec3(0.f, 0.f, 1.f));
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
}}