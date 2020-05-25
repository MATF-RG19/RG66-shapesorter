#include "utils.h"
#include "globals.h"
#include <random>

#define Y_AXIS 0
#define X_AXIS 1

void check_collision()
{
    auto next = iter + 1;
    switch (spawn_axis) {
        case Y_AXIS: // y axis
            if (current_falling_figure != *iter)
                // for debug purposes
                animation_ongoing = 0;
               //std::exit(EXIT_SUCCESS); 
            break;
        case X_AXIS: // x axis
            if (next == cube_sides.cend())
                next = cube_sides.cbegin();

            if (current_falling_figure != *next)
                animation_ongoing = 0;
                //std::exit(EXIT_SUCCESS); 
            break;
        default:
            break;
    }
}

void update_cube_side_iterator(unsigned char pressedKey)
{
    switch (pressedKey) {
        case 'a':
            ++iter;
            if (iter == cube_sides.cend())
                iter = cube_sides.cbegin();
            break;
        case 'd':
            if (iter == cube_sides.cbegin())
                iter = cube_sides.cend() - 1;
            else 
                --iter;
        default:
            break;
            
    }
}


void set_translation_params()
{
    if (spawn_axis == Y_AXIS) // y axis
    {
        tx = 0;
        ty = 10 - falling_figure_position;
    } else if (spawn_axis == X_AXIS) // x axis
    {
        tx = 10 - falling_figure_position;
        ty = 0;
    }
}



void generate_spawn_axis()
{
    spawn_axis = std::rand() % 2;
}
