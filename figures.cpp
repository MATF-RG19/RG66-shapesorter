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

