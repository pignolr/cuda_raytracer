#include "core/Raytracer.h"

namespace raytracer::core {
	Raytracer::Raytracer(size_t width, size_t height, Point position):
		_screen_width(width),
		_screen_height(height),
		_screen_pixels(height, std::vector<core::Pixel>(width)),
		_camera_position(std::move(position))
	{}

	void Raytracer::create_image(const std::string& filename) const
	{
		create_bitmap(_screen_pixels, filename);
	}
	
	void Raytracer::create_image() const
	{
		create_bitmap(_screen_pixels);
	}

	void Raytracer::compute_raycasting()
	{

	}
}
