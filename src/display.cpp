#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>


#include "display.h"
#include "globals.h"
#include "figures.h"
#include "utils.h"


void on_display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    glLoadIdentity();
    gluLookAt(
            15, 10, 15,
            0, 0, 0,
            0, 1, 0
        );

    draw_background_figures();
    coordinate_axes(10);

    // draw falling object
    glPushMatrix();
        if (falling_figure_position < 10) 
        {
            set_translation_params();
            glTranslatef(tx, ty, 0);
            draw_falling_figure(current_falling_figure);
        } else 
        {
            check_collision();
        }
    glPopMatrix();


    // drawing main cube
    glPushMatrix(); 
        glRotatef(angle, 0, 0, 1);
        draw_main_cube(3);
    glPopMatrix();

    
     
    glutSwapBuffers();
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
