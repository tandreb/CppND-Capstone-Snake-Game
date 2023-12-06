#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  void HandleGameInput(bool &running, Snake &snake) const;
  void HandleMenuInput(bool &running, int &selectedItem, bool &showMenuFlag) const ;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif