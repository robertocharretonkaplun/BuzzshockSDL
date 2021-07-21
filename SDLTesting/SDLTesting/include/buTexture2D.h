#pragma once
#include <Prerequisites.h>

namespace buSDLSDK {
	class buRenderer;
	class buTexture2D {
	public:
		buTexture2D() = default;
		~buTexture2D() = default;

		void
    init(string _filepath, buRenderer& _renderer);

    void
    update();

    void
    render();

    void
    destroy();

	public:
		SDL_Texture* m_texture;
	private:
		SDL_Surface* m_surface;
	};
}
