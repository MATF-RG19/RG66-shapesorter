#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "timers.h"
#include "utils.h"
#include "globals.h"

void on_timer1(int value)
{
    if  (value != 0)
        return;

    if (falling_figure_position >= 10) {
        falling_figure_position = 0;
        current_falling_figure  = std::rand() % 4;
        generate_spawn_axis();
    }

    falling_figure_position += 0.05;
    glutPostRedisplay();

    if (animation_ongoing)
        glutTimerFunc(20, on_timer1, 0);
}


void on_timer(int value)
{
    if (value != 0)
        return;
    
    if (rotation_cycle_angle >= 90) {
        rotation_in_progress = false;
        rotation_cycle_angle = 0;
    } else {
        rotation_cycle_angle += 10;
        if (angle >= 360 || angle <= -360)
            angle = 0;

        switch (main_cube_rotation_axis)
        {
            // TODO rename 1 -> POSITIVE_Z_AXIS, -1 -> NEGATIVE_Z_AXIS 
            case 1:
                angle += 10;
                break;
            case -1:
                angle -= 10;
                break;
            default:
                break;
        }
    }

    
    glutPostRedisplay();

    if (rotation_in_progress)
        glutTimerFunc(20, on_timer, 0);
}

