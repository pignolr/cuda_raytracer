#include <iostream>
#include <sstream>
#include <algorithm>
#include "gui/Window.h"
#include "gui/WindowError.h"

namespace raytracer::gui {

	Window::Window(const std::string& title, int width, int height) :
		_title(title), _width(width), _height(height)
	{
		_window = SDL_CreateWindow(
			_title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_SHOWN);
		if (_window == nullptr) {
			std::stringstream error;
			error << "SDL_CreateWindow failed: "
				<< std::endl << SDL_GetError();
			throw WindowError(error.str());
		}

		_renderer = SDL_CreateRenderer(_window, -1, 0);
		if (_renderer == nullptr) {
			std::stringstream error;
			error << "SDL_CreateRenderer failed: "
				<< std::endl << SDL_GetError();
			throw WindowError(error.str());
		}

		std::cout << "SDL Window start" << std::endl;
	}

	Window::~Window()
	{
		SDL_DestroyRenderer(_renderer);
		SDL_DestroyWindow(_window);
		std::cout << "SDL Window end" << std::endl;
	}

	void Window::wait(int time) const noexcept
	{
		SDL_Delay(time);
	}

	void Window::wait_quit() const noexcept
	{
		SDL_Event event;
		while (1) {
			if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
				break;
		}
	}

	void Window::display(const raytracer::core::PixelMatrix& pixel_matrix)
	{
		// clear window with deep pink
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(_renderer);

		int height = std::min(static_cast<int>(pixel_matrix.size()), _height);
		int width = std::min(static_cast<int>(pixel_matrix[0].size()), _width);

		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				unsigned char r = pixel_matrix[y][x].r;
				unsigned char g = pixel_matrix[y][x].g;
				unsigned char b = pixel_matrix[y][x].b;
				SDL_SetRenderDrawColor(_renderer, r, g, b, SDL_ALPHA_OPAQUE);
				SDL_RenderDrawPoint(_renderer, x, y);
			}
		}
		SDL_RenderPresent(_renderer);
	}
}
