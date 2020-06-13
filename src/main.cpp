#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "figures.h"
#include "globals.h"
#include "display.h"
#include "keyboard.h"

// ############################################################################
// initialization of global variables

std::vector<Cube_side> cube_sides { 
    Cube_side::blue_square, 
    Cube_side::triangle, 
    Cube_side::green_square, 
    Cube_side::circle 
};

// vector iterator, points on top side of the main cube
std::vector<Cube_side>::const_iterator iter = cube_sides.cbegin();

bool rotation_in_progress = false;
float angle = 0;
float rotation_cycle_angle = 0;

bool animation_ongoing = false;

float falling_figure_position = 10;
int current_falling_figure = 0;

int main_cube_rotation_axis = 1;

int spawn_axis = -1;

float tx = 0;
float ty = 0;

float g_width = 500;
float g_height = 500;

// ############################################################################

void init();


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(g_width, g_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("ShapeSorter");

    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);    
    glutKeyboardFunc(on_keyboard);

    init();

    glutMainLoop();

    return 0;
}

void init()
{
    glClearColor(0.5, 0.5, 0.5, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    std::srand(std::time(nullptr));
    
    // let glColor3f define colors
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);

    // setup default white light at light_position
    GLfloat light_position[] = { 10, 10, 10, 0 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}
