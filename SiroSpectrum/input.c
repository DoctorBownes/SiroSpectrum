#include <SiroSpectrum/input.h>
#include <SiroSpectrum/renderer.h>
#include <GLFW/glfw3.h>

unsigned char GetKey(enum KeyCode key) {
	return glfwGetKey(_window, key);
}

unsigned char GetKeyReleased(enum KeyCode key) {
	if (!glfwGetKey(_window, key) && _keyreles[key - 32]) {
		_keyreles[key - 32] = 0;
		return 1;
	}
	if (glfwGetKey(_window, key)) {
		_keyreles[key - 32] = 1;
	}
	return 0;
}



unsigned char GetKeyPressed(enum KeyCode key) {
	if (glfwGetKey(_window, key) && !_keypress[key - 32]) {
		_keypress[key - 32] = 1;
		return 1;
	}
	if (!glfwGetKey(_window, key)) {
		_keypress[key - 32] = 0;
	}
	return 0;
}
