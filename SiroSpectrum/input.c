#include <SiroSpectrum/input.h>
#include <SiroSpectrum/core.h>
#include <GLFW/glfw3.h>

unsigned char GetKey(enum KeyCode key) {
	return glfwGetKey(_window, key);
}
