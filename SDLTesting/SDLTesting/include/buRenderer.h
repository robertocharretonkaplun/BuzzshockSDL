#pragma once
#include <Prerequisites.h>
namespace buSDLSDK {
	class buWindow;
	class buRenderer {
	public:
		buRenderer() = default;
		~buRenderer() = default;

		void
    init(buWindow& _window);

    void
    update();

    void
    render();

    void
    destroy();

	public:
		SDL_Renderer* m_renderer;
	};
}
