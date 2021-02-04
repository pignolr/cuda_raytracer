#include <stdexcept>
#include <cmath>
#include "core/Vector.h"

namespace raytracer::core {
	Vector Vector::operator+(const Vector& other) const noexcept
	{
		return Vector(x + other.x, y + other.y, z + other.z);
	}

	Vector Vector::operator-(const Vector& other) const noexcept
	{
		return Vector(x - other.x, y - other.y, z - other.z);
	}

	Vector Vector::operator*(double factor) const noexcept
	{
		return Vector(x * factor, y * factor, z * factor);
	}

	Vector Vector::operator/(double denominator) const
	{
		if (denominator == 0)
			throw std::overflow_error("Divide by zero exception");
		return Vector(x / denominator, y / denominator, z / denominator);
	}

	bool Vector::is_null() const noexcept
	{
		return x == 0 && y == 0 && z == 0;
	}

	double Vector::compute_norm() const noexcept
	{
		return std::sqrt((x * x) + (y * y) + (z * z));
	}

	double Vector::compute_scalar_product(const Vector& other) const noexcept
	{
		return (x * other.x) + (y * other.y) + (z * other.z);
	}

	double Vector::compute_cos_angle(const Vector& other) const
	{
		if (is_null() || other.is_null())
			throw std::overflow_error("Divide by zero exception");
		return compute_scalar_product(other) / (compute_norm() * other.compute_norm());
	}
}
