#include <iostream>
#include <exception>
#include "core/Raytracer.h"

constexpr size_t WIDTH = 720; 
constexpr size_t HEIGHT = 480;

int main(int ac, char** av)
{
	auto raytracer = raytracer::core::Raytracer(WIDTH, HEIGHT);

	try {
		raytracer.create_image();
	}
	catch (const std::exception& e) {
		std::cout << "Creation of image has failed: " << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
