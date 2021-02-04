#include <iostream>
#include <sstream>
#include "gui/SDLVideoInstance.h"
#include "gui/SDLInstanceError.h"

namespace raytracer::gui {

	SDLVideoInstance::SDLVideoInstance()
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::stringstream error;
			error << "SDL_Init failed: "
				<< std::endl << SDL_GetError();
			throw SDLInstanceError(error.str());
		}
		std::cout << "SDL Init" << std::endl;
	}

	SDLVideoInstance:: ~SDLVideoInstance()
	{
		SDL_Quit();
		std::cout << "SDL Quit" << std::endl;
	}
}
