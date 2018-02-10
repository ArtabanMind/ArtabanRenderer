
#include "RenderEngine/DisplayManager.h"


namespace ArtabanRenderer { namespace RenderEngine {

	GameCamera* DisplayManager::DisplayCam = nullptr;

	DisplayManager::DisplayManager()
	{

	}

	DisplayManager::DisplayManager(const char* name, int width, int height)
		: Title(name), Width(width), Height(height)
	{
		
	}

	DisplayManager::~DisplayManager()
	{

	}

	bool DisplayManager::CreateDisplay()
	{
		return Init();
	}

	void DisplayManager::UpdateDisplay()
	{
		glfwSwapBuffers(Window);
		glfwGetFramebufferSize(Window, &Width, &Height);
		glfwPollEvents();

		error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cout << error << std::endl;
		}
	}

	void DisplayManager::CleanupDisplay()
	{
		glfwTerminate();
	}

	bool DisplayManager::Init()
	{
		if (!glfwInit())
		{
			return false;
		}

		Window = glfwCreateWindow(Width, Height, Title, NULL, NULL);
		if (Window == nullptr)
		{
			return false;
		}


		glfwMakeContextCurrent(Window);
		glfwSetWindowUserPointer(Window, this);

		// glewInit should be placed after glfwMakeContextCurrent
		GLenum ret = glewInit();
		if (ret != GLEW_OK)
		{
			return false;
		}


		glfwSetWindowSizeCallback(Window, WindowSizeCallback);
		glfwSetKeyCallback(Window, KeyCallback);
		glfwSetCursorPosCallback(Window, MouseCursorCallback);
		glfwSetMouseButtonCallback(Window, MouseButtonCallback);


		return true;
	}

	bool DisplayManager::DisplayClosed()
	{
		return glfwWindowShouldClose(Window) == 1;
	}

	void DisplayManager::AssignCam(GameCamera* _cam)
	{
		DisplayCam = _cam;
	}

	void DisplayManager::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		// TODO
		if (DisplayCam != nullptr)
		{
			float delta = 0.02f;
			switch (key)
			{
			case GLFW_KEY_W:
				DisplayCam->Move(0.f, -delta);
				break;
			case GLFW_KEY_S:
				DisplayCam->Move(0.f, delta);
				break;
			case GLFW_KEY_A:
				DisplayCam->Move(-delta, 0.f);
				break;
			case GLFW_KEY_D:
				DisplayCam->Move(delta, 0.f);
				break;
			}

		}

	}

	void DisplayManager::MouseButtonCallback(GLFWwindow* window, int key, int action, int mods)
	{
		// TODO
	}

	void DisplayManager::MouseCursorCallback(GLFWwindow* window, double xpos, double ypos)
	{
		// TODO
	}

	void DisplayManager::WindowSizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}}