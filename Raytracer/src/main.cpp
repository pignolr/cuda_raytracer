#include <iostream>
#include <exception>
#include "core/Raytracer.h"
#include "gui/SDLVideoInstance.h"
#include "gui/Window.h"

constexpr size_t WIDTH = 720; 
constexpr size_t HEIGHT = 480;

int main(int ac, char** av)
{
	auto &sdl_instance = raytracer::gui::SDLVideoInstance::get_instance();
	raytracer::gui::Window window("raytracer", WIDTH, HEIGHT);

	auto raytracer = raytracer::core::Raytracer(WIDTH, HEIGHT);

	try {
		const auto &pixel_matrix = raytracer.get_pixel_matrix();
		window.display(pixel_matrix);
		window.wait_quit();
	}
	catch (const std::exception& e) {
		std::cout << "Creation of image has failed: " << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
