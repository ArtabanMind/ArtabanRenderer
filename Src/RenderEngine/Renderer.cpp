
#include "RenderEngine/Renderer.h"



namespace ArtabanRenderer { namespace RenderEngine {
	


	Renderer::Renderer(StaticShader* shader, Camera& cam)
	{
		createProjectionMatrix();
		createViewMatrix(cam);
		shader->Start();
		shader->LoadProjectionMatrix(ProjectionMatrix);
		shader->Stop();
	}

	void Renderer::Prepare()
	{
		glClearColor(0.f, 0.f, 0.f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	
	}

	void Renderer::Render(Entity* _entity, StaticShader* shader)
	{

		// Command Parameter Setup for Draw call ++++
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(_entity->GetModelVAOID());
		glBindTexture(GL_TEXTURE_2D, _entity->GetModelTextureID());

		shader->LoadTransformMatrix(_entity->GetTransformation());
		//shader->LoadMatrix<mat4>(_entity->GetTransformation(), 1);
		// Finish Setup Parameters
		glDrawElements(GL_TRIANGLES, 
			_entity->GetModelVertexCount(), 
			GL_UNSIGNED_INT, 
			(const void*)NULL);	// --> it seems clearing command
		
	}

	void Renderer::Cleanup()
	{
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindVertexArray(0);
	}

	void Renderer::createProjectionMatrix()
	{
		ProjectionMatrix = glm::perspective<float>(FOV, ASPECT, NEAR, FAR);
	}

	void Renderer::createViewMatrix(Camera &cam)
	{
		glm::mat4 view(1.0f);
		view = glm::rotate(view, cam.GetPitch(), vec3(1.f, 0.f, 0.f));
		view = glm::rotate(view, cam.GetYaw(), vec3(0.f, 1.f, 0.f));
		vec3 pos = cam.GetCamPosition();
		pos *= -1.f;
		view = glm::translate(view, pos);

		return view;
	}

}}