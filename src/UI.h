#pragma once
#include <iostream>
#include "field.h"

class ManagementInterface
{
public:
    ManagementInterface() {};

    void update_draw_field(Field &field);
    void control_terminal(Field  &field);
private:
    void move_figure(Field &field, int x, int y, int new_x, int new_y, std::vector<std::pair<int, int> > possible_moves);
    void attack_figure(Field &field, int x, int y,  int new_x, int new_y, std::vector<std::pair<int, int> > possible_attacks);
};