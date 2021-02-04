#pragma once
#include <string>
#include <exception>

namespace raytracer::gui {
	class SDLInstanceError : public std::exception {
		std::string _error;
	public:
		SDLInstanceError(const std::string& error) : _error(error) {}
		virtual ~SDLInstanceError() = default;

		const char* what() const throw ()
		{
			return _error.c_str();
		}
	};
}
