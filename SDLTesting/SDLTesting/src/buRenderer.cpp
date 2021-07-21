#include "..\include\buRenderer.h"
#include "buWindow.h"

namespace buSDLSDK {
  void
  buRenderer::init(buWindow & _window) {
    m_renderer = SDL_CreateRenderer(_window.m_window, -1, 0);
  }

  void 
  buRenderer::update() {
  }

  void 
  buRenderer::render() {
  }

  void 
  buRenderer::destroy() {
    // destroy renderer
    SDL_DestroyRenderer(m_renderer);
  }
}
