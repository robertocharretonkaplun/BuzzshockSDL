#pragma once
#include <Prerequisites.h>
#include <buWindow.h>
#include <buRenderer.h>
#include <buTexture2D.h>

namespace buSDLSDK {
	class BaseApp {
	public:
		BaseApp() = default;
		~BaseApp() = default;

		int
		run(); 

		void
		onCreate();

		void
		onUpdate();

		void
		onRender();

		void 
		onDestroy();

	private:
		// API
		int m_close = 0;
		buWindow m_window;
		buRenderer m_renderer;
		buTexture2D m_texture;
		//SDL_Texture* tex;
		SDL_Rect dest;

		// speed of box
		int speed = 300;
	};
}
