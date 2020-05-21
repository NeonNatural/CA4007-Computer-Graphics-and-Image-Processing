#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>

//draw circle and change colour of it based on click in teh circle


double theta;
float x11=0.0,y11=0.0;

int r,g,b;
 int first=1;
void display(void)
{
  glClearColor(1.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);


	glBegin(GL_TRIANGLE_FAN);

  glColor3f(r,g,b);
	glVertex2f(0.0,0.0);
	for(int i=0; i < 1000; i++)
	{ theta = theta + 0.01;
		glVertex2f(2*cos(theta),2*sin(theta));
	}
	glEnd();

	glFlush();
	return;
}
void mouse(int button, int mouseState, int x, int y) {


    if(button == GLUT_LEFT_BUTTON && mouseState == GLUT_DOWN) {
      x11 = ((x*2)-500.0)/500.0;
      y11= -((y*2)-500.0)/500.0;

      if(x11<.49 && y11 <.49 && x11> -.49 && y11 > -.49){

        if(first==1){
        r =1;
        g = 1;
        b = 1;
        glutPostRedisplay();
        first = 0;
        return;
        }

        if(first == 0){
        r =0;
        g = 0;
        b = 0;
        glutPostRedisplay();
        first = 1;
        return;
        }

      }


    }

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
  glutInitWindowSize(500.0,500.0);
  glutInitWindowPosition(500.0,200);

    glutCreateWindow("simple");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
