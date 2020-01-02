#include <iostream>
#include <cstdlib>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "figures.h"
#include <cmath>
#define X_AXIS 0
#define Y_AXIS 1


struct rot_state {
    bool rotating;
    float x, y;
    int current_rotation_axis;
} current_rotation;

bool animation_ongoing = false;
float x_angle, y_angle = 0.0;
float temp = 0;



static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int w, int h);
static void on_timer(int value);


void set_callbacks();
void init();


void coordinate_axes();
void draw_main_cube(float x_angle, float y_angle);

void update_rotation_angle(float& alpha);


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("ShapeSorter");

    set_callbacks();
    init();


    glutMainLoop();

    return 0;
}


static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    glLoadIdentity();
    gluLookAt(
            5, 5, 5,
            0, 0, 0,
            0, 1, 0
        );

    coordinate_axes(10);

    // draw falling object
    // get top side
    // check for collison

 
    glRotatef(current_rotation.x, 1, 0, 0);
    glRotatef(current_rotation.y, 0, 1, 0);
    draw_main_cube();
 



    glutSwapBuffers();
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            std::exit(EXIT_SUCCESS);
            break;
        case 'd':
        case 'D':
            if (!current_rotation.rotating) {
                current_rotation.rotating = true;
                current_rotation.current_rotation_axis = Y_AXIS;
                glutTimerFunc(20, on_timer, 0);
            }
            break;
        case 's':
        case 'S':
            if (!current_rotation.rotating) {
                current_rotation.rotating = true;
                current_rotation.current_rotation_axis = X_AXIS;
                glutTimerFunc(20, on_timer, 0);
            }
            break;
        default:
            break;  
    }
}

static void on_reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            w / (float) h,
            1.5,
            20);
    glMatrixMode(GL_MODELVIEW);

}

void set_callbacks()
{
    glutDisplayFunc(on_display);
    glutReshapeFunc(on_reshape);    
    glutKeyboardFunc(on_keyboard);
}

void init()
{
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    current_rotation.current_rotation_axis = X_AXIS;
    current_rotation.rotating = false;
    current_rotation.x = 0;
    current_rotation.y = 0;
}


static void on_timer(int value)
{
    if (value != 0)
        return;
    
    if (temp >= 90) {
        current_rotation.rotating = false;
        temp = 0;
    } else {
        temp += 2;
        switch (current_rotation.current_rotation_axis)
        {
        case X_AXIS:
            if (current_rotation.x >= 360)
                current_rotation.x = 0;
            current_rotation.x += 2;
            break;
        case Y_AXIS:
            if (current_rotation.y >= 360)
                current_rotation.y = 0;
            current_rotation.y += 2;
            break;
        default:
            break;
        }
    }
    
    glutPostRedisplay();

    if (current_rotation.rotating)
        glutTimerFunc(20, on_timer, 0);
}

