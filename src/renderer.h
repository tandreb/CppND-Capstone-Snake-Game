#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "snake.h"
#include <SDL_ttf.h>
#include <vector>

class Renderer {
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);
  void renderText(const char *text, int x, int y,
                  TTF_Font *font, bool isSelected);
  void RenderMenu( TTF_Font *font, int &selectedItem);
  // Add getter functions for renderer and font
  SDL_Renderer *GetRenderer() const { return sdl_renderer; }
  TTF_Font *GetFont() const { return font; }

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  TTF_Font *font;
  SDL_Color _bgcolor = {0, 0, 0};

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif