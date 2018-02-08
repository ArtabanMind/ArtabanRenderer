
#include "RenderEngine/Camera.h"

namespace ArtabanRenderer { namespace RenderEngine {
	
	void Camera::Move()
	{

	}

	const vec3 Camera::GetCamPosition()
	{
		return CamPosition;
	}

	const float Camera::GetPitch()
	{
		return pitch;
	}

	const float Camera::GetRoll()
	{
		return roll;
	}

	const float Camera::GetYaw()
	{
		return yaw;
	}

}}