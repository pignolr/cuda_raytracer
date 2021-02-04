#include "core/Raytracer.h"

namespace raytracer::core {
	Raytracer::Raytracer(size_t width, size_t height, Point position):
		_pixel_matrix_width(width),
		_pixel_matrix_height(height),
		_pixel_matrix(height, std::vector<core::Pixel>(width)),
		_camera_position(std::move(position))
	{}

	void Raytracer::create_image(const std::string& dest) const
	{
		create_bitmap(_pixel_matrix, dest);
	}

	void Raytracer::compute_raycasting()
	{

	}

	const PixelMatrix &Raytracer::get_pixel_matrix() const noexcept
	{
		return _pixel_matrix;
	}
}
