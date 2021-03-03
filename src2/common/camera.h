#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::lookAt()

class Camera
{
public:
	Camera();
	virtual ~Camera();

	void computeViewMatrixFromInput(GLFWwindow* window, float deltaTime);
	glm::mat4 getViewMatrix() { return _viewMatrix; };
	glm::mat4 getProjectionMatrix() { return _projectionMatrix; };
	glm::vec3 getCursor() { return _cursor; };

private:
	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;
	glm::vec3 _cursor;
};

#endif
