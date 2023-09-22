#include <SiroSpectrum/input.h>
#include <SiroSpectrum/renderer.h>
#include <GLFW/glfw3.h>

unsigned char GetKey(enum KeyCode key) {
	return glfwGetKey(_window, key);
}

unsigned char GetKeyReleased(enum KeyCode key) {
	unsigned char keystatus = glfwGetKey(_window, key);
	if (!keystatus && _relescalled) {
		return 1;
	}
	if (!keystatus && _keyreles[key - 32]) {
		_keyreles[key - 32] = 0;
		_relescalled = 1;
		return 1;
	}
	if (keystatus) {
		_keyreles[key - 32] = 1;
	}
	return 0;
}



unsigned char GetKeyPressed(enum KeyCode key) {
	unsigned char keystatus = glfwGetKey(_window, key);
	if (keystatus && _presscalled) {
		return 1;
	}
	if (keystatus && !_keypress[key - 32]) {
		_keypress[key - 32] = 1;
		_presscalled = 1;
		return 1;
	}
	else if (!keystatus) {
		_keypress[key - 32] = 0;
	}
	return 0;
}
