
#include "RenderEngine/Renderer.h"



namespace ArtabanRenderer { namespace RenderEngine {
	


	Renderer::Renderer(StaticShader* shader, GameCamera* cam, Entity* _entity)
	{

		shader->Start();
		shader->LoadProjectionMatrix();
		shader->LoadViewMatrix(cam);
		shader->LoadTransformMatrix(_entity->GetTransformation());
		shader->Stop();
	}

	void Renderer::Prepare()
	{
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.f, 0.f, 0.f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	}

	void Renderer::Render(Entity* _entity, StaticShader* shader, 
		GameCamera* _cam)
	{

		// Command Parameter Setup for Draw call ++++
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(_entity->GetModelVAOID());
		glBindTexture(GL_TEXTURE_2D, _entity->GetModelTextureID());

		shader->LoadTransformMatrix(_entity->GetTransformation());
		shader->LoadViewMatrix(_cam);
		shader->LoadProjectionMatrix();
		//shader->GeneralLoadMatrix<mat4>(_entity->GetTransformation(), 1);
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

	

}}