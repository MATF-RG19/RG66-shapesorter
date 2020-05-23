#include "figures.h"
#include <GL/glut.h>
#include <cmath>

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

void draw_main_cube(float size)
{
    // draw square on top of the main cube
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex3f(size / 4, size / 2, size / 4);
        glVertex3f(size / 4, size / 2, -size / 4);
        glVertex3f(-size /4, size / 2, -size / 4);
        glVertex3f(-size /4, size / 2, size / 4);
    glEnd();


    // draw square on bottom side of the cube
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex3f(size / 4, -size / 2, size / 4);
        glVertex3f(size / 4, -size / 2, -size / 4);
        glVertex3f(-size /4, -size / 2, -size / 4);
        glVertex3f(-size /4, -size / 2, size / 4);
    glEnd();


    // draw circle on negative x-axis side of the main cube
    float PI = 3.14159;
    glColor3f(1, 0.5, 0);
    glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < 10; ++i)
        {
            glVertex3f(
                    -size / 2, 
                    std::cos(2 * i * PI / 10) * 0.7,
                    std::sin(2 * i * PI / 10) * 0.7
                    );
        }
    glEnd();
    
    // draw triangle that lies on x-axis side of the main cube
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex3f(size / 2, -size/4, size/4);
        glVertex3f(size / 2, -size/4, -size/4);
        glVertex3f(size / 2, size/2, 0);
    glEnd();


    glPushMatrix();
        glColor3f(0.9, 0.0, 0.2);
        glutWireCube(size);
        //glutSolidCube(2.0);
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
