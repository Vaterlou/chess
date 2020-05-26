#pragma once
#include <utility> 
#include <vector>

enum Types { NONE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum Colors { NONE_COLOR, BLACK, WHITE };
enum Direction { NONE_DIRECT, UP, DOWN};

class Figure
{
public:
    Figure() {};
    Figure( int _x, int _y, Types _type, Colors _color, Direction _direct );

    void set_position(std::pair<int, int> _pos);
    void set_type(Types _type);
    void set_color(Colors _color);
    void set_direct(Direction _direct);

    std::pair<int, int> get_position() const;
    Types get_type() const;
    Colors get_color() const;
    Direction get_direct() const;

private:
    int x, y;
    Types type;
    Colors color;
    Direction direct;
};