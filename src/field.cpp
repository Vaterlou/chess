#include "field.h"

Field::Field()
{
    field.resize(8, std::vector<Figure>(8));
    for (size_t i(0); i < 8; ++i)
    {
        for (size_t j(0); j < 8; ++j)
        {
            Figure fig = create_figure(j, i);
            field[i][j] = fig;
        }
    }
}

void Field::update_field(ChessField _field)
{
    field = _field;
}

ChessField Field::get_field() const
{
    return field;
}

Figure Field::create_figure(int x, int y)
{
    if (y >= 0 && y < 2)
    {
        Figure fig(x, y, Types::BISHOP, Colors::BLACK, Direction::DOWN);
        return fig;
    }
    else if (y >= 2 && y < 6)
    {
        Figure fig(x, y, Types::NONE, Colors::NONE_COLOR, Direction::NONE_DIRECT);
        return fig;
    }
    else if (y >= 6 && y <= 7)
    {
        Figure fig(x, y, Types::BISHOP, Colors::WHITE, Direction::UP);
        return fig;
    }
        
}

std::vector<std::pair<int, int> > Field::possbly_atcks(Figure fig)
{
    std::pair<int, int> pos = fig.get_position();

    int x = pos.first;
    int y = pos.second;

    std::vector<std::pair<int, int> > possible_attacks;
    switch (fig.get_type())
    {
    case PAWN:
        if (fig.get_direct() == Direction::DOWN)
        {
            if (x + 1 > 7 || x - 1 < 0 || y + 1 > 7 || y - 1 < 0)
                return possible_attacks;

            if (field[y + 1][x + 1].get_type() != Types::NONE)
                possible_attacks.push_back(std::make_pair(x + 1, y + 1));

            if (field[y + 1][x - 1].get_type() != Types::NONE)
                possible_attacks.push_back(std::make_pair(x - 1, y + 1));
        }
        else  if (fig.get_direct() == Direction::UP)
        {
            if (x + 1 > 7 || x - 1 < 0 || y - 1 < 0)
                return possible_attacks;

            if (field[y - 1][x + 1].get_type() != Types::NONE)
                possible_attacks.push_back(std::make_pair(x + 1, y - 1));

            if (field[y - 1][x - 1].get_type() != Types::NONE)
                possible_attacks.push_back(std::make_pair(x - 1, y - 1));
        }        
        break;

    case BISHOP:
        break;

    case ROOK:
        break;

    case KNIGHT:
        break;

    case KING:
        break;

    case QUEEN:
        break;
    
    default:
        break;
    }
    return possible_attacks;
}

std::vector<std::pair<int, int> > Field::possbly_moves(Figure fig)
{
     std::pair<int, int> pos = fig.get_position();
    int x = pos.first;
    int y = pos.second;
    int p_x = x, p_y = y;

    std::vector<std::pair<int, int> > possible_moves;
    switch (fig.get_type())
    {
    case PAWN:
        if (x + 1 > 7 || x - 1 < 0 || y + 1 > 7 || y - 1 < 0)
                return possible_moves;

        if (fig.get_direct() == Direction::DOWN)
        {
            y++;
            possible_moves.push_back(std::make_pair(x, y));
        }
        else  if (fig.get_direct() == Direction::UP)
        {
            y--;
            possible_moves.push_back(std::make_pair(x, y));
        }        
        break;

    case BISHOP:
        while (p_x < 7 && p_y > 0)
        {
            p_x++;
            p_y--;
            if (field[y][p_x].get_type() == Types::NONE)
                possible_moves.push_back(std::make_pair(p_x, p_y));
            else 
            {
                possible_moves.push_back(std::make_pair(p_x, p_y));
                break;
            }
        }
        p_x = x, p_y = y;

        while (p_x < 7 && p_y < 7)
        {
            p_x++;
            p_y++;
            if (field[p_y][p_x].get_type() == Types::NONE)
                possible_moves.push_back(std::make_pair(p_x, p_y));
            else 
            {
                possible_moves.push_back(std::make_pair(p_x, p_y));
                break;
            }
        }
        p_x = x, p_y = y;

        while (p_x > 0 && p_y < 7)
        {
            p_y++;
            p_x--;
            if (field[p_y][p_x].get_type() == Types::NONE)
                possible_moves.push_back(std::make_pair(x, p_y));
            else 
            {
                possible_moves.push_back(std::make_pair(x, p_y));
                break;
            }
        }
        p_x = x, p_y = y;

        while (p_x < 7 && p_y > 0)
        {
           p_y--;
           p_x++;
           if (field[p_y][p_x].get_type() == Types::NONE)
                possible_moves.push_back(std::make_pair(p_x, p_y));
            else 
            {
                possible_moves.push_back(std::make_pair(p_x, p_y));
                break;
            }
        }
        p_x = x, p_y = y;
        break;

    case ROOK:       
        while (p_x < 7)
        {
            p_x++;
            if (field[y][p_x].get_type() == Types::NONE)
                possible_moves.push_back(std::make_pair(p_x, y));
            else 
            {
                possible_moves.push_back(std::make_pair(p_x, y));
                break;
            }
        }
        p_x = x, p_y = y;

        while (p_x > 0)
        {
            p_x--;
            if (field[y][p_x].get_type() == Types::NONE)
                possible_moves.push_back(std::make_pair(p_x, y));
            else 
            {
                possible_moves.push_back(std::make_pair(p_x, y));
                break;
            }
        }
        p_x = x, p_y = y;

        while (p_y < 7)
        {
            p_y++;
            if (field[p_y][x].get_type() == Types::NONE)
                possible_moves.push_back(std::make_pair(x, p_y));
            else 
            {
                possible_moves.push_back(std::make_pair(x, p_y));
                break;
            }
        }
        p_x = x, p_y = y;

        while (p_y > 0)
        {
           p_y--;
           if (field[p_y][x].get_type() == Types::NONE)
                possible_moves.push_back(std::make_pair(x, p_y));
            else 
            {
                possible_moves.push_back(std::make_pair(x, p_y));
                break;
            }
        }
        p_x = x, p_y = y;

        break;

    case KNIGHT:
        break;

    case KING:
        break;

    case QUEEN:
        break;
    
    default:
        break;
    }
    return possible_moves;
}