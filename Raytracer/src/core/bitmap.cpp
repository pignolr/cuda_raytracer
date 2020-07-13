#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "core/Pixel.h"

namespace raytracer::core {
	const uint32_t BYTES_PER_PIXEL = 3;
	const uint32_t FILE_HEADER_SIZE = 14;
	const uint32_t INFO_HEADER_SIZE = 40;

	static void write_bitmap_file_header(std::fstream& image_file, uint32_t height, uint32_t width, uint32_t padding_size)
	{
		uint32_t file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + ((BYTES_PER_PIXEL * width + padding_size) * width);
		unsigned char file_header[] = {
			'B','M', /// signature
			0,0,0,0, /// image file size in bytes
			0,0,0,0, /// reserved
			0,0,0,0, /// start of pixel array
		};

		file_header[2] = static_cast<unsigned char>(file_size);
		file_header[3] = static_cast<unsigned char>(file_size >> 8);
		file_header[4] = static_cast<unsigned char>(file_size >> 16);
		file_header[5] = static_cast<unsigned char>(file_size >> 24);
		file_header[10] = static_cast<unsigned char>(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

		image_file.write((char *)(file_header), sizeof(file_header));
	}

	static void write_bitmap_info_header(std::fstream& image_file, uint32_t height, uint32_t width)
	{
		static unsigned char info_header[] = {
			0,0,0,0, /// header size
			0,0,0,0, /// image width
			0,0,0,0, /// image height
			0,0, /// number of color planes
			0,0, /// bits per pixel
			0,0,0,0, /// compression
			0,0,0,0, /// image size
			0,0,0,0, /// horizontal resolution
			0,0,0,0, /// vertical resolution
			0,0,0,0, /// colors in color table
			0,0,0,0, /// important color count
		};

		info_header[0] = static_cast<unsigned char>(INFO_HEADER_SIZE);
		info_header[4] = static_cast<unsigned char>(width);
		info_header[5] = static_cast<unsigned char>(width >> 8);
		info_header[6] = static_cast<unsigned char>(width >> 16);
		info_header[7] = static_cast<unsigned char>(width >> 24);
		info_header[8] = static_cast<unsigned char>(height);
		info_header[9] = static_cast<unsigned char>(height >> 8);
		info_header[10] = static_cast<unsigned char>(height >> 16);
		info_header[11] = static_cast<unsigned char>(height >> 24);
		info_header[12] = static_cast<unsigned char>(1);
		info_header[14] = static_cast<unsigned char>(BYTES_PER_PIXEL * 8);

		image_file.write((char*)(info_header), sizeof(info_header));
	}

	static void write_bitmap_color_header(std::fstream& image_file, const MatrixPixel& matrix, uint32_t padding_size)
	{
		char padding[] = { 0,0,0 };

		for (auto& line : matrix) {
			for (auto& pixel : line) {
				image_file << pixel.b << pixel.g << pixel.r;
			}
			image_file.write(padding, padding_size);
		}
	}

	void create_bitmap(const MatrixPixel& matrix, const std::string& filename)
	{
		auto image_file = std::fstream(filename, std::ios_base::app | std::ios_base::binary);
		uint32_t height = matrix.size();
		uint32_t width = matrix[0].size();
		uint32_t padding_size = (4 - (width * BYTES_PER_PIXEL) % 4) % 4;

		write_bitmap_file_header(image_file, height, width, padding_size);
		write_bitmap_info_header(image_file, height, width);
		write_bitmap_color_header(image_file, matrix, padding_size);

		std::cout << "The image \"" << filename << "\" has been created." << std::endl;
	}

	void create_bitmap(const MatrixPixel& matrix)
	{
		if (!std::filesystem::exists("results"))
			std::filesystem::create_directories("results");

		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);
		std::stringstream ss;

		ss << "results/raytracer_image_" << std::put_time(&tm, "%d-%m-%Y_%H-%M-%S") << ".bmp";
		create_bitmap(matrix, ss.str());
	}
}
