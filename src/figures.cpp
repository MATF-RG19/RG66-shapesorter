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
        glColor3f(1, 1, 0);
        glColor3f(0.9, 0.0, 0.2);
        //glutWireCube(2.0);
        glutSolidCube(2.0);
        coordinate_axes(1);

    glPopMatrix();
}

void draw_falling_figure(int id)
{
    switch (id) {
        case 0:
            glColor3f(0, 1, 0);
            glutSolidCube(1);
            break;
        case 1:
            glColor3f(1, 0, 0);
            glutSolidSphere(1, 10, 10);
            break;
        case 2:
            glColor3f(0, 0, 1);
            //glutWireTeapot(1);
            glutSolidTeapot(1);
            break;
        case 3:
            glColor3f(1, 0, 1);
            //glutWireIcosahedron();
            glutSolidIcosahedron();
        default:
            glColor3f(1, 0, 1);
            //glutWireCube(1);
            glutSolidCube(1);
    }
}
