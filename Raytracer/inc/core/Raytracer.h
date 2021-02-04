#pragma once

#include "core/Pixel.h"
#include "core/Point.h"
#include "core/Vector.h"
#include "core/Ray.h"

namespace raytracer::core {
	class Raytracer {
		size_t _pixel_matrix_width;
		size_t _pixel_matrix_height;
		PixelMatrix _pixel_matrix;

		Point _camera_position;

	public:
		Raytracer(size_t width, size_t height, Point position = Point());
		virtual ~Raytracer() = default;

		const Point& get_camera_position() { return _camera_position; }
		void set_camera_position(Point position) { _camera_position = std::move(position); }

		void create_image(const std::string& dest = "") const;

		void compute_raycasting();
		const PixelMatrix& Raytracer::get_pixel_matrix() const noexcept;
	};
}
