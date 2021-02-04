#include <stdexcept>
#include "core/Point.h"

namespace raytracer::core {
	Point Point::operator+(const Point& other) const noexcept
	{
		return Point(x + other.x, y + other.y, z + other.z);
	}

	Point Point::operator-(const Point& other) const noexcept
	{
		return Point(x - other.x, y - other.y, z - other.z);
	}

	Point Point::operator*(double factor) const noexcept
	{
		return Point(x * factor, y * factor, z * factor);
	}

	Point Point::operator/(double denominator) const
	{
		if (denominator == 0)
			throw std::overflow_error("Divide by zero exception");
		return Point(x / denominator, y / denominator, z / denominator);
	}

	Vector Point::compute_vector(const Point& other) const noexcept
	{
		return Vector(other.x - x, other.y - y, other.z - z);
	}
}
