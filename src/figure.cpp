#include "figure.h"

Figure::Figure(int _x, int _y, Types _type, Colors _color, Direction _direct)
{
    x = _x;
    y = _y;
    type = _type;
    color = _color;
    direct = _direct;
}

void Figure::set_position(std::pair<int, int> _pos)
{
    x = _pos.first;
    y = _pos.second;
}

void Figure::set_type(Types _type)
{
    type = _type;
}

void Figure::set_color(Colors _color)
{
    color = _color;
}

void Figure::set_direct(Direction _direct)
{
    direct = _direct;
}

std::pair<int, int> Figure::get_position() const
{
    std::pair<int, int> pair = std::make_pair(x, y);
    return pair;
}

Types Figure::get_type() const
{
    return type;
}

Colors Figure::get_color() const
{
    return color;
}

Direction Figure::get_direct() const
{
    return direct;
}
