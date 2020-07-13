#pragma once
#include <vector>
#include <string>

namespace raytracer::core {
	struct Pixel {
		unsigned char r;
		unsigned char g;
		unsigned char b;

		// default color of pixel (deeppink)
		Pixel() : r(255), g(20), b(147) {}
		Pixel(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}
		~Pixel() = default;
	};

	using MatrixPixel = std::vector<std::vector<core::Pixel>>;
	void create_bitmap(const MatrixPixel& matrix);
	void create_bitmap(const MatrixPixel& matrix, const std::string& filename);
}
