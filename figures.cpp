#include "figures.h"
#include <GL/glut.h>

void coordinate_axes(int len)
{
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(len,0,0);
        
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,len,0);
        
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,len);
    glEnd();
}

void draw_main_cube()
{
    glPushMatrix();
        glColor3f(1, 1, 1);
        glutWireCube(1.0);
        coordinate_axes(1);

    glPopMatrix();
}

void draw_falling_figure(int id)
{
    switch (id) {
        case 0:
            glColor3f(0, 1, 0);
            glutWireCube(1);
            break;
        case 1:
            glColor3f(1, 0, 0);
            glutWireSphere(1, 10, 10);
            break;
        case 2:
            glColor3f(0, 0, 1);
            glutWireTeapot(1);
            break;
        case 3:
            glColor3f(1, 0, 1);
            glutWireIcosahedron();
        default:
            glColor3f(1, 0, 1);
            glutWireCube(1);
    }
}
