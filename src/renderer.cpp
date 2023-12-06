#include "renderer.h"
#include <SDL_ttf.h>
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width), screen_height(screen_height),
      grid_width(grid_width), grid_height(grid_height),
      font(nullptr) { // Initialize font to nullptr

  // Initialize SDL_ttf
  if (TTF_Init() < 0) {
    std::cerr << "SDL_ttf could not initialize.\n";
    std::cerr << "SDL_ttf Error: " << TTF_GetError() << "\n";
  }

  // Load a font (adjust the path to your font file)
  font = TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeSans.ttf",
                      36); // Change the path and size as needed

  if (font == nullptr) {
    std::cerr << "Failed to load font.\n";
    std::cerr << "SDL_ttf Error: " << TTF_GetError() << "\n";
  }

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::renderText(const char *text, int x, int y, TTF_Font *font,
                          bool isSelected) {
  SDL_Surface *surface;
  if (isSelected) {
    surface = TTF_RenderText_Shaded(font, text, {255, 255, 255, 255},
                                    {255, 0, 0}); // White text, red bg
  } else {
    surface = TTF_RenderText_Shaded(font, text, {255, 255, 255, 255},
                                    {0, 0, 0}); // White text, black bg
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);

  SDL_Rect destRect = {x, y, surface->w, surface->h};
  SDL_RenderCopy(sdl_renderer, texture, nullptr, &destRect);

  SDL_FreeSurface(surface);
  SDL_DestroyTexture(texture);
}

void Renderer::RenderMenu(TTF_Font *font, int &selectedItem) {
  bool isSelected = false;
  SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0,
                         255); // Set background color to black
  SDL_RenderClear(sdl_renderer);
  // Render "New Game" option
  if (selectedItem == 0) {
    // Highlight the selected item with a different background color
    // SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 255); // Red background
    isSelected = true;
  } else {
    // std::cout << "selected 0 else\n";
    // SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255); // Black background
    isSelected = false;
  }
  renderText("New Game", 100, 200, font, isSelected);

  // Render "Quit Game" option
  if (selectedItem == 1) {
    // std::cout << "selected 1\n";
    // Highlight the selected item with a different background color
    // SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 255); // Red background
    isSelected = true;
  } else {
    // std::cout << "selected 1 else\n";
    // SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255); // Black background
    isSelected = false;
  }
  renderText("Quit Game", 100, 300, font, isSelected);

  SDL_RenderPresent(sdl_renderer); // Update the screen
}

void Renderer::Render(Snake const snake, SDL_Point const &food) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) +
                    " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
