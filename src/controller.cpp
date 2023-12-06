#include "controller.h"
#include "SDL.h"
#include "snake.h"
#include <iostream>

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1)
    snake.direction = input;
  return;
}

void Controller::HandleMenuInput(bool &running, int &selectedItem, bool &showMenuFlag) const {
    // Handle SDL events
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        running =false;
      } else if (e.type == SDL_KEYDOWN) {
        // Handle arrow keys for menu item selection
        switch (e.key.keysym.sym) {
        case SDLK_UP:
          selectedItem = (selectedItem - 1 + 2) % 2;
          break;
        case SDLK_DOWN:
          selectedItem = (selectedItem + 1) % 2;
          break;
        case SDLK_RETURN:
          // Handle the selected menu item (start game, quit, etc.)
          if (selectedItem == 0) {
            // Start new game
            showMenuFlag = false;
            return;
          } else if (selectedItem == 1) {
            // Quit game
            showMenuFlag = false;
            running = false;
            return;
          }
          break;
        }
      }
  }
}

void Controller::HandleGameInput(bool &running, Snake &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
      case SDLK_UP:
        ChangeDirection(snake, Snake::Direction::kUp, Snake::Direction::kDown);
        break;

      case SDLK_DOWN:
        ChangeDirection(snake, Snake::Direction::kDown, Snake::Direction::kUp);
        break;

      case SDLK_LEFT:
        ChangeDirection(snake, Snake::Direction::kLeft,
                        Snake::Direction::kRight);
        break;

      case SDLK_RIGHT:
        ChangeDirection(snake, Snake::Direction::kRight,
                        Snake::Direction::kLeft);
        break;
      }
    }
  }
}