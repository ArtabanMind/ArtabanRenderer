#pragma once
#include "Default.h"

namespace ArtabanRenderer { namespace RenderEngine {
	using glm::vec3;
	
	class GameCamera {

	public:
		GameCamera();
		const float GetPitch();
		const float GetYaw();
		const float GetRoll();
		const vec3 GetCamPosition();
		void Move(float right, float forward);

	private:
		vec3 CamPosition;
		float pitch;
		float yaw;
		float roll;

	
	};


}}