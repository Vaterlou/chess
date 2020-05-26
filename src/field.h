#pragma once
#include <vector>
#include <iostream>
#include "figure.h"

using ChessField = std::vector<std::vector<Figure> >;

class Field
{
public:
    Field();

    void update_field(ChessField _field);
    ChessField get_field() const;
    std::vector<std::pair<int, int> > possbly_atcks(Figure fig);
    std::vector<std::pair<int, int> > possbly_moves(Figure fig);
private:
    Figure create_figure(int x, int y);
    ChessField field;
};