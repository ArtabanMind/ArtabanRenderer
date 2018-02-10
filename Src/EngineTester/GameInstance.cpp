#include "RenderEngine/DisplayManager.h"
#include "RenderEngine/RawModel.h"
#include "RenderEngine/Loader.h"
#include "RenderEngine/Renderer.h"
#include "Shaders/ShaderProgram.h"
#include "Shaders/StaticShader.h"
#include "RenderEngine/TexturedModel.h"
#include "RenderEngine/Camera.h"


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


	//float data[] = {
	//	-0.5f, 0.5f, 0.0f,
	//	-0.5f, -0.5f, 0.0f,
	//	0.5f, -0.5f, 0.0f,
	//	0.5f, 0.5f, 0.0f
	//};

	//unsigned int indies[] = {
	//	0, 1, 2, 0, 2, 3
	//};

	//float texCoord[] = {
	//	0.0f, 0.0f,
	//	0.0f, 1.0f,
	//	1.0f, 1.0f,
	//	1.0f, 0.0f
	//};

	//unsigned int length = 12;
	//unsigned int indexLength = 6;
	//unsigned int texCoordLength = 8;

	float data[] = {
		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,0.5f,-0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		0.5f,0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,0.5f,0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f

	};

	float texCoord[] = {

		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0


	};

	unsigned int indies[] = {
		0,1,3,
		3,1,2,
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22

	};
	unsigned int length = 72;
	unsigned int indexLength = 36;
	unsigned int texCoordLength = 48;


	Loader loader;
	
	const char* vPath = "Assets/vertexShader.txt";
	const char* fPath = "Assets/fragmentShader.txt";
	StaticShader shader(vPath, fPath);
	

	// TODO : resource release 
	GLuint vaoID = loader.LoadVAO(data, length, indies, indexLength,
		texCoord, texCoordLength);
	GLuint textureID = loader.LoadTexture("res/Mini.jpg");
	
	RawModel rawModel(vaoID, indexLength);
	TexturedModel textureModel(&rawModel, textureID);
	Entity entity(&textureModel, vec3(0.0f, 0.0f, -5.f), vec3(0.f), vec3(1.f));

	GameCamera cam;

	display.AssignCam(&cam);

	if(!shader.Init())
		return -1;
	Renderer renderer(&shader, &cam, &entity);

	shader.Start();
	
	//renderer.Prepare(&entity, &shader);
	

	while (!display.DisplayClosed())
	{
		renderer.Prepare();

		//entity.IncreasePosition(vec3(0.0f, 0.f, -0.02f));
		entity.IncreaseRotation(0.02f, 0.02f, 0.02f);
		//renderer.Render();
		renderer.Render(&entity, &shader, &cam);

		display.UpdateDisplay();
	}

	renderer.Cleanup();

	shader.Stop();
	display.CleanupDisplay();

	return 0;
}