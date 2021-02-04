#pragma once

#include <core/Vector.h>

namespace raytracer::core {
	struct Point {
		double x;
		double y;
		double z;

		Point() : x(0), y(0), z(0) {}
		Point(double x, double y, double z) : x(x), y(y), z(z) {}

		virtual ~Point() = default;

		Point operator+(const Point& other) const noexcept;
		Point operator-(const Point& other) const noexcept;
		Point operator*(double factor) const noexcept;
		Point operator/(double denominator) const;

		Vector compute_vector(const Point& other) const noexcept;
	};
}
