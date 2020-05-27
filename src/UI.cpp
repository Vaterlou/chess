#include "UI.h"

void ManagementInterface::update_draw_field(Field &field)
 {
    auto matrix = field.get_field();
    for (size_t i(0); i < 8; ++i)
    {
        for (size_t j(0); j < 8; ++j)
        {
            int num = matrix[i][j].get_type();
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
 }

void ManagementInterface::control_terminal(Field &field)
{
    auto matrix = field.get_field();
    int x, y;
    std::cout << "Input x and y that select figure " << std::endl;
    std::cin >> x >> y;

    if (x < 0 || x > 7 || y < 0 || y > 7)
    {
        std::cout << "Uncorrect corrdinates" << std::endl;
        control_terminal(field);
    }
    

    auto possible_moves = field.possbly_moves(matrix[y][x]);
    auto possible_attacks = field.possbly_atcks(matrix[y][x]);

    if (possible_moves.size() < 1)
        {
            std::cout << "No possible moves " << std::endl;
            control_terminal(field);
        }
    else
        std::cout << "Possible moves " << std::endl;

    for (auto i : possible_moves)
        std::cout << i.first << " " << i.second << std::endl << std::endl;

    if (possible_attacks.size() < 1)
        {
            std::cout << "No possible attacks " << std::endl;
        }
    else
        std::cout << "Possible attacks " << std::endl;

    for (auto i : possible_attacks)
        std::cout << i.first << " " << i.second << std::endl << std::endl;

    std::cout << "Make step " << std:: endl;
    int new_x, new_y;
    std::cin >> new_x >> new_y;
    move_figure(field, x, y, new_x, new_y, possible_moves);
    attack_figure(field, x, y, new_x, new_y, possible_attacks);
}

void ManagementInterface::move_figure(Field &field, int x, int y,  int new_x, int new_y, std::vector<std::pair<int, int> > possible_moves)
{
    auto matrix = field.get_field();
    for (auto i : possible_moves)
    {
        if (i.first == new_x && i.second == new_y)
        {
            matrix[y][x].set_position(std::make_pair(new_x, new_y));
            matrix[new_y][new_x] = matrix[y][x];

            Figure empty_cell(x, y, Types::NONE, Colors::NONE_COLOR, Direction::NONE_DIRECT);
            matrix[y][x] = empty_cell;
            field.update_field(matrix);
        }
    }
}
void ManagementInterface::attack_figure(Field &field, int x, int y,  int new_x, int new_y, std::vector<std::pair<int, int> > possible_attacks)
{
    auto matrix = field.get_field();
    for (auto i : possible_attacks)
    {
        if (i.first == new_x && i.second == new_y)
        {
            matrix[y][x].set_position(std::make_pair(new_x, new_y));
            matrix[new_y][new_x] = matrix[y][x];

            Figure empty_cell(x, y, Types::NONE, Colors::NONE_COLOR, Direction::NONE_DIRECT);
            matrix[y][x] = empty_cell;
            field.update_field(matrix);

            std::cout << "KILL" << std::endl;
        }
    }
}