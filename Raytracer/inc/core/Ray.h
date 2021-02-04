#pragma once

#include <core/Point.h>
#include <core/Vector.h>

namespace raytracer::core {
	class Ray {
		Point _origin_point;
		Vector _direction_vector;

	public:
		Ray(Point point, Vector vector) noexcept : _origin_point(point), _direction_vector(vector) {}
		virtual ~Ray() = default;

		const Point& get_origin_point() const noexcept { return _origin_point; }
		const Vector& get_direction_vector() const noexcept { return _direction_vector; }

		void set_origin_point(Point point) noexcept { _origin_point = std::move(point); }
		void set_direction_vector(Vector vector) noexcept { _direction_vector = std::move(vector); }
	};
}
