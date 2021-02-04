#pragma once
#include <string>
#include <exception>

namespace raytracer::gui {
	class WindowError : public std::exception {
		std::string _error;
	public:
		WindowError(const std::string& error) : _error(error) {}
		virtual ~WindowError() = default;

		const char* what() const throw ()
		{
			return _error.c_str();
		}
	};
}
