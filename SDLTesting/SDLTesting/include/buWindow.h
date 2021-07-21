#pragma once
#include <Prerequisites.h>

namespace buSDLSDK {
  class buWindow
  {
  public:
    buWindow() = default;
    ~buWindow() = default;

    void
    init(string _windowName, int _width, int _height);

    void
    update();


    void
    render();

    void
    destroy();

  public:
    SDL_Window* m_window;
  };
}
