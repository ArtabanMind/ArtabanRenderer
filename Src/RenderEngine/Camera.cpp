
#include "RenderEngine/Camera.h"

namespace ArtabanRenderer { namespace RenderEngine {
	
	GameCamera::GameCamera()
		: pitch(0.f), roll(0.f), yaw(0.f), CamPosition(vec3(0.f))
	{

	}

	void GameCamera::Move(float right, float forward)
	{
		CamPosition.x += right;
		CamPosition.z += forward;
	}

	const vec3 GameCamera::GetCamPosition()
	{
		return CamPosition;
	}

	const float GameCamera::GetPitch()
	{
		return pitch;
	}

	const float GameCamera::GetRoll()
	{
		return roll;
	}

	const float GameCamera::GetYaw()
	{
		return yaw;
	}

}}