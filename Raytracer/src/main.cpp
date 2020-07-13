#include <iostream>
#include <vector>
#include <core/Pixel.h>

constexpr size_t WIDTH = 720; 
constexpr size_t HEIGHT = 480;


int main(int ac, char** av)
{
	using namespace raytracer;

	auto pixels = core::MatrixPixel(HEIGHT, std::vector<core::Pixel>(WIDTH));
	core::create_bitmap(pixels);

	return EXIT_SUCCESS;
}
