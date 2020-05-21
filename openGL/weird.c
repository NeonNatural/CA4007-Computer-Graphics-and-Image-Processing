#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

///gcc basic.c -o basic glut32.lib -lopengl32 -lglu32
double theta;
void display(void)
{
  glClearColor(0.0,1.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);





  glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0,0.0);
    for(int i=0; i < 1000; i++)
    { theta = theta + 0.01;
    glColor3f(1.0,0.0,0.0);
        glVertex2f(cos(theta),sin(theta));
    }
    glEnd();

    glFlush();
    return;
}

void reshape(GLsizei w, GLsizei h){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-2.0,2.0,-2.0,2.0);
  //glViewport(0,0,w,h);
  return;
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
    glutInitWindowPosition(500,500);
    glutInitWindowSize(500,500);

    glutCreateWindow("simple");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
