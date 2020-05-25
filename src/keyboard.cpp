#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>


#include "keyboard.h"
#include "globals.h"
#include "utils.h"
#include "timers.h"

#define NEGATIVE_X_AXIS -1 
#define POSITIVE_X_AXIS 1

void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            std::exit(EXIT_SUCCESS);
            break;
        case 'd':
        case 'D':
            if (!rotation_in_progress) {
                main_cube_rotation_axis = NEGATIVE_X_AXIS;
                glutTimerFunc(20, on_timer, 0);
                rotation_in_progress = true;
                update_cube_side_iterator('d');
            }
            break;
        case 'a':
        case 'A':
            if (!rotation_in_progress) {
                main_cube_rotation_axis = POSITIVE_X_AXIS;
                glutTimerFunc(20, on_timer, 0);
                rotation_in_progress = true;
                update_cube_side_iterator('a');
            }
            break;
        case 'g':
        case 'G':
            if (!animation_ongoing) 
            {
                generate_spawn_axis();
                glutTimerFunc(20, on_timer1, 0);
                animation_ongoing = true;
            }
            break;
        case 'b':
        case 'B':
            animation_ongoing = false;
            break;
        case 'r':
        case 'R':
            // TODO reset the game
            break;
        default:
            break;  
    }
}
