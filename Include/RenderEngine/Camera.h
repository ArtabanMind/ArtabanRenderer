
#include "Default.h"

namespace ArtabanRenderer { namespace RenderEngine {
	using glm::vec3;
	class Camera {
	private:
		vec3 CamPosition;
		float pitch;
		float yaw;
		float roll;

	public:
		const float GetPitch();
		const float GetYaw();
		const float GetRoll();
		const vec3 GetCamPosition();
		void Move();
	};


}}