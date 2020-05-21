#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

GLfloat xs = 0.0;
float x11,y11;
void MyIdle();
void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,3.0,0.0,0.0,0.0,0.0,1.0,0.0);

  glRotated(xs, 0.0, 0.0, -1.0);

	glutSolidCube(0.5);
	MyIdle();
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
//	glFrustum(-1.0,1.0,-1.0,1.0,9.5,12.0);
	gluPerspective(60,1.0,0.3,10.0);
	glViewport(0,0,w,h);
	return;
}

void MyIdle()
{
xs += 1.0;


if(xs > 350) xs = -350;
glutPostRedisplay();
}

void MyMouse2(GLint x, GLint y)
{

	x11 = ((x*2)-500.0)/500.0;
	y11= -((y*2)-500.0)/500.0;
	if(x11>0){xs += 1.0;}
	if(x11<0){xs -= 1.0;}



	if(xs > 350) xs = -350;
	glutPostRedisplay();

	glFlush();

	return;
}




int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
  //glutIdleFunc(MyIdle);
  glutMotionFunc(MyMouse2);


	glutMainLoop();
}
