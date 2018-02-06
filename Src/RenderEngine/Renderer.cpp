
#include "RenderEngine/Renderer.h"



namespace ArtabanRenderer { namespace RenderEngine {
	

	Renderer::Renderer()
	{

	}

	void Renderer::Prepare(Entity* _entity, StaticShader* _shader)
	{
		CurrentModel = _entity;
		RawModel* rawModel = _entity->GetModel()->GetRawModel();
		ShaderHandle = _shader;
		
		

		glBindVertexArray(rawModel->GetVAOID());
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _entity->GetModel()->GetTextureID());
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
	}

	void Renderer::Render()
	{
		glClearColor(0.f, 0.f, 0.f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		ShaderHandle->LoadTransformMatrix(CurrentModel->GetTransformation());
		
		//glDrawArrays(GL_TRIANGLES, 0, _model->GetVertexCount());
		glDrawElements(GL_TRIANGLES, 
			CurrentModel->GetModel()->GetRawModel()->GetVertexCount(), GL_UNSIGNED_INT, (const void*)NULL);
		
		
	}

	void Renderer::Cleanup()
	{
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindVertexArray(0);
	}

}}