#include "buTexture2D.h"
#include "buRenderer.h"
namespace buSDLSDK {
  void 
  buTexture2D::init(string _filepath, buRenderer & _renderer) {
    // please provide a path for your image
    m_surface = IMG_Load(_filepath.c_str());
    if (m_surface == nullptr) {
      std::cout << "IMG_Load: " << IMG_GetError() << "\n";
    }
    // loads image to our graphics hardware memory.
    m_texture = SDL_CreateTextureFromSurface(_renderer.m_renderer, m_surface);

    // clears main-memory
    SDL_FreeSurface(m_surface);
  }

  void 
  buTexture2D::update() {
  }
  
  void
  buTexture2D::render() {
  }

  void 
  buTexture2D::destroy() {
    // destroy texture
    SDL_DestroyTexture(m_texture);
  }
}