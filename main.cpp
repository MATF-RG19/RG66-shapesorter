#include <iostream>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

static void on_display(void);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("ShapeSorter");

    glutDisplayFunc(on_display);

    glClearColor(0.75, 0.75, 0.75, 0);

    glutMainLoop();

    return 0;
}

static void on_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}
