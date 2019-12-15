#include <iostream>
#include <cstdlib>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>



static void on_display(void);
static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int w, int h);


void set_callbacks();
void init();


void coordinate_axes();


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

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            20/5, 30/5, 40/5,
            0, 0, 0,
            0, 1, 0
        );

	coordinate_axes();

    glutSwapBuffers();
}

static void on_keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 27:
			std::exit(EXIT_SUCCESS);
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
}

void coordinate_axes()
{
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(10,0,0);
        
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,10,0);
        
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,10);
    glEnd();
}
