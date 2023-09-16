#include <SiroSpectrum/input.h>
#include <SiroSpectrum/core.h>
#include <GLFW/glfw3.h>

unsigned char GetKey(enum KeyCode key) {
	return glfwGetKey(_window, key);
}

unsigned char GetKeyReleased(enum KeyCode key) {
	if (!glfwGetKey(_window, key) && keyreles[key - 32]) {
		keyreles[key - 32] = 0;
		return 1;
	}
	if (glfwGetKey(_window, key)) {
		keyreles[key - 32] = 1;
	}
	return 0;
}



unsigned char GetKeyPressed(enum KeyCode key) {
	if (glfwGetKey(_window, key) && !keypress[key - 32]) {
		keypress[key - 32] = 1;
		return 1;
	}
	if (!glfwGetKey(_window, key)) {
		keypress[key - 32] = 0;
	}
	return 0;
}
