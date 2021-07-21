#include "buWindow.h"

namespace buSDLSDK {
  void 
  buWindow::init(string _windowName, int _width, int _height) {
    // Create windo
    m_window = SDL_CreateWindow(_windowName.c_str(),
                              SDL_WINDOWPOS_CENTERED, 
                              SDL_WINDOWPOS_CENTERED,
                              _width,
                              _height,
                              SDL_WINDOW_SHOWN);
  }
  
  void
  buWindow::update() {
  }


  void
  buWindow::render() {
  }
  
  void 
  buWindow::destroy() {
    // destroy window
    SDL_DestroyWindow(m_window);
  }
}