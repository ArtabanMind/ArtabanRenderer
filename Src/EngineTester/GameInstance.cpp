#include "RenderEngine/DisplayManager.h"
#include "RenderEngine/RawModel.h"
#include "RenderEngine/Loader.h"
#include "RenderEngine/Renderer.h"
#include "Shaders/ShaderProgram.h"
#include "Shaders/StaticShader.h"
#include "RenderEngine/TexturedModel.h"


int
main(void)
{
	using namespace ArtabanRenderer;
	using namespace RenderEngine;
	using namespace Shaders;
	using namespace Entities;

	DisplayManager display("Emile", 1280, 720);
	if(!display.CreateDisplay())
		return -1;

	float data[] = {
		-0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
	};

	unsigned int indies[] = {
		0, 1, 2, 0, 2, 3
	};

	float texCoord[] = {
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f
	};

	unsigned int length = 12;
	unsigned int indexLength = 6;
	unsigned int texCoordLength = 8;

	Loader loader;
	Renderer renderer;
	const char* vPath = "Assets/vertexShader.txt";
	const char* fPath = "Assets/fragmentShader.txt";
	StaticShader shader(vPath, fPath);
	// TODO : resource release 
	GLuint vaoID = loader.LoadVAO(data, length, indies, indexLength,
		texCoord, texCoordLength);
	GLuint textureID = loader.LoadTexture("res/Mini.jpg");
	
	RawModel rawModel(vaoID, indexLength);
	TexturedModel textureModel(&rawModel, textureID);
	Entity entity(&textureModel, vec3(-1.0f, 0.0f, 0.f), vec3(0.f), vec3(1.0f));

	if(!shader.Init())
		return -1;
	shader.Start();

	renderer.Prepare(&entity, &shader);

	while (!display.DisplayClosed())
	{
		
		//entity.IncreasePosition(vec3(0.02f, 0.f, 0.f));
		entity.IncreaseRotation(vec3(0.0f, 0.0f, 0.01f));
		renderer.Render();

		display.UpdateDisplay();
	}

	renderer.Cleanup();

	shader.Stop();
	display.CleanupDisplay();

	return 0;
}