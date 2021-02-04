#pragma once
#include <SDL.h>
#include "common/Singleton.h"

namespace raytracer::gui {
	// Singleton instance of SDL
	class SDLVideoInstance: public common::Singleton<SDLVideoInstance> {
		friend class common::Singleton<SDLVideoInstance>;
	public:
		SDLVideoInstance();
		~SDLVideoInstance();
	};
}
