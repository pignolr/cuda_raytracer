#pragma once

#include <SDL.h>
#include <core/Pixel.h>

namespace raytracer::gui {
	class Window {
		SDL_Window* _window;
		SDL_Renderer* _renderer;
		const std::string& _title;
		int _width;
		int _height;

	public:
		Window(const std::string& title, int width, int height);
		~Window();

		// wait for n ms
		void wait(int time) const noexcept;
		// wait until the window is closed
		void wait_quit() const noexcept;

		void display(const raytracer::core::PixelMatrix &);
	};
}
