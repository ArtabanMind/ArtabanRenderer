#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace ArtabanRenderer { namespace RenderEngine {

	class DisplayManager {

	public:
		DisplayManager();
		~DisplayManager();

		DisplayManager(const char* name, int width, int height);

		bool CreateDisplay();

		void UpdateDisplay();

		void CleanupDisplay();

		bool DisplayClosed();

	private:
		int Width;
		int Height;
		const char* Title;

		GLenum error;
		GLFWwindow* Window;

		bool Init();

		static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MouseButtonCallback(GLFWwindow* window, int key, int action, int mods);
		static void MouseCursorCallback(GLFWwindow* window, double xpos, double ypos);
		static void WindowSizeCallback(GLFWwindow* window, int width, int height);

	};

}}

