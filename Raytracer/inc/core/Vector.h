#pragma once

namespace raytracer::core {
	struct Vector {
		double x;
		double y;
		double z;

		Vector() : x(0), y(0), z(0) {}
		Vector(double x, double y, double z) : x(x), y(y), z(z) {}

		virtual ~Vector() = default;

		Vector operator+(const Vector& other) const noexcept;
		Vector operator-(const Vector& other) const noexcept;
		Vector operator*(double factor) const noexcept;
		Vector operator/(double denominator) const;

		bool is_null() const noexcept;

		double compute_norm() const noexcept;
		double compute_scalar_product(const Vector& other) const noexcept;
		double compute_cos_angle(const Vector& other) const;
	};
}
