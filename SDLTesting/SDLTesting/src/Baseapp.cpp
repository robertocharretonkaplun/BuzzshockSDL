#include "Baseapp.h"

namespace buSDLSDK {
  int 
  BaseApp::run() {
    // Initi all 
    onCreate();

    while (!m_close) {
      onUpdate();
      onRender();
    }

    onDestroy();
    return 0;
  }

  void
  BaseApp::onCreate() {
    // Creat window
    SDL_Init(SDL_INIT_EVERYTHING);

    // Init Window
    m_window.init("Basic Demo", 600, 400);

    // Init Renderer
    m_renderer.init(m_window);

    m_texture.init("Data/Textures/01.png", m_renderer);
    
    // connects our texture with dest to control position
    SDL_QueryTexture(m_texture.m_texture, NULL, NULL, &dest.w, &dest.h);

    //// adjust height and width of our image box.
    //dest.w /= 6;
    //dest.h /= 6;

    // sets initial x-position of object
    dest.x = (50 - dest.w) / 2;

    // sets initial y-position of object
    dest.y = (50 - dest.h) / 2;
  }
  
  void 
    BaseApp::onUpdate() {
    SDL_Event event;

    // Events management
    while (SDL_PollEvent(&event)) {
      switch (event.type) {

      case SDL_QUIT:
        // handling of close button
        m_close = 1;
        break;

      case SDL_KEYDOWN:
        // keyboard API for key pressed
        switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_W:
        case SDL_SCANCODE_UP:
          dest.y -= speed / 30;
          break;
        case SDL_SCANCODE_A:
        case SDL_SCANCODE_LEFT:
          dest.x -= speed / 30;
          break;
        case SDL_SCANCODE_S:
        case SDL_SCANCODE_DOWN:
          dest.y += speed / 30;
          break;
        case SDL_SCANCODE_D:
        case SDL_SCANCODE_RIGHT:
          dest.x += speed / 30;
          break;
        default:
          break;
        }
      }

    }
      // right boundary
      if (dest.x + dest.w > 1000)
        dest.x = 1000 - dest.w;

      // left boundary
      if (dest.x < 0)
        dest.x = 0;

      // bottom boundary
      if (dest.y + dest.h > 1000)
        dest.y = 1000 - dest.h;

      // upper boundary
      if (dest.y < 0)
        dest.y = 0;
    
  }

  void 
  BaseApp::onRender() {
    // clears the screen
    SDL_RenderClear(m_renderer.m_renderer);

    // Remder information
    
    SDL_RenderCopy(m_renderer.m_renderer, m_texture.m_texture, NULL, &dest);
    
    // triggers the double buffers
    // for multiple rendering
    SDL_RenderPresent(m_renderer.m_renderer);

    // calculates to 60 fps
    SDL_Delay(1000 / 60);
  }
  
  void 
  BaseApp::onDestroy() {
    m_texture.destroy();

    m_renderer.destroy();
    m_window.destroy();

    // close SDL
    SDL_Quit();
  }
}