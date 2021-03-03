// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <common/config.h>
#include <common/renderer.h>
#include <common/camera.h>
#include <common/scene.h>
#include <common/sprite.h>

int main( void )
{
	Renderer renderer;

	Scene* scene = new Scene();

	Sprite* kingkong = new Sprite("assets/kingkong.tga");
	kingkong->position = glm::vec3(400.0f, 300.0f, 0.0f);
	Sprite* pencils = new Sprite("assets/pencils.tga");
	pencils->position = glm::vec3(900.0f, 300.0f, 0.0f);
	Sprite* rgba = new Sprite("assets/rgba.tga");
	rgba->position = glm::vec3(WIDTH/2, HEIGHT/2, 0.0f);
	rgba->scale = glm::vec3(3.0f, 3.0f, 1.0f);

	scene->addSprite(kingkong);
	scene->addSprite(pencils);
	scene->addSprite(rgba);

	do {
		// get deltaTime and update camera
		float dt = renderer.updateDeltaTime();
		scene->camera()->computeViewMatrixFromInput(renderer.window(), dt);

		// Update the scene
		scene->update(dt); // TODO make subclass for Scene (and make Scene abstract?)
		rgba->rotation += dt; // for now, do it here

		// Render the scene
		renderer.renderScene(scene);
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	delete scene;

	return 0;
}
