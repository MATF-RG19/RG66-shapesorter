#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

#include "figures.h"

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>


struct rot_state {
    bool rotating;
    float x;
} current_rotation;

bool animation_ongoing = false;
float temp = 0;
double falling_figure_position = 0;
int current_falling_figure = 0;
int rotation_axis = 1;


int spawn_axis = -1;
float tx = 0;
float ty = 0;


void on_display(void);
void on_keyboard(unsigned char key, int x, int y);
void on_reshape(int w, int h);
void on_timer(int value);
void on_timer1(int value);


void set_callbacks();
void init();
void generate_spawn_axis();
void set_translation_params();




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


void on_display(void)
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    glLoadIdentity();
    gluLookAt(
            10, 10, 10,
            0, 0, 0,
            0, 1, 0
        );

    coordinate_axes(10);

    // draw falling object
    glPushMatrix();
        // if object is still falling, translate it on current spawn axis
        if (falling_figure_position < 10) 
        {
            set_translation_params();
            glTranslatef(tx, ty, 0);
            draw_falling_figure(current_falling_figure);
        } 
        // object is in coordinate centre, need to check which side of main cube is facing it
//        else {
//          #TODO handle collision 
//        }
    glPopMatrix();


    // drawing main cube
    glPushMatrix(); 
        glRotatef(current_rotation.x, 0, 0, 1);
        draw_main_cube();
    glPopMatrix();
 
    glutSwapBuffers();
}

void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            std::exit(EXIT_SUCCESS);
            break;
        case 'd':
        case 'D':
            if (!current_rotation.rotating) {
                rotation_axis = -1;
                glutTimerFunc(20, on_timer, 0);
                current_rotation.rotating = true;
            }
            break;
        case 'a':
        case 'A':
            if (!current_rotation.rotating) {
                rotation_axis = 1;
                glutTimerFunc(20, on_timer, 0);
                current_rotation.rotating = true;
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
        default:
            break;  
    }
}

void on_reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            (float) w / h,
            0.01f,
            100.0f);
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
    glClearColor(0.5, 0.5, 0.5, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);

    current_rotation.rotating = false;
    current_rotation.x = 0;

    std::srand(std::time(nullptr));

    glEnable(GL_COLOR_MATERIAL);

    glShadeModel(GL_SMOOTH);

    // setup default white light at light_position
    GLfloat light_position[] = { 10, 10, 10, 0 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}


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
    
    if (temp >= 90) {
        current_rotation.rotating = false;
        temp = 0;
    } else {
        temp += 10;
        if (current_rotation.x >= 360 || current_rotation.x <= -360)
            current_rotation.x = 0;

        switch (rotation_axis)
        {
            // TODO rename 1 -> POSITIVE_Z_AXIS, -1 -> NEGATIVE_Z_AXIS 
            case 1:
                current_rotation.x += 10;
                break;
            case -1:
                current_rotation.x -= 10;
                break;
            default:
                break;
        }
    }

    
    glutPostRedisplay();

    if (current_rotation.rotating)
        glutTimerFunc(20, on_timer, 0);
}
void generate_spawn_axis()
{
    spawn_axis = std::rand() % 2;
}
void set_translation_params()
{
    if (spawn_axis == 0) // y axis
    {
        tx = 0;
        ty = 10 - falling_figure_position;
    } else if (spawn_axis == 1) // x axis
    {
        tx = 10 - falling_figure_position;
        ty = 0;
    }
}
