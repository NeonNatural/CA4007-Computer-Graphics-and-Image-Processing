/*
cube with smaller cube on each face
*/


#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

float mainLoop = 0.0;
int smallCubes = 0;

void cuboids();
void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

	cuboids();

	glFlush();
	return;
}


void cuboids(){

	glPushMatrix();

	glRotatef(mainLoop,0,0,1);
	glutWireCube(0.5);

	glRotatef(mainLoop, 0,0,1);
	glTranslatef(0,0.4,0);
	glutWireCube(0.2);

	glRotatef(mainLoop, 0,0,1);
	glTranslatef(0.4,-0.4,0);
	glutWireCube(0.2);

	glRotatef(mainLoop, 0,0,1);
	glTranslatef(-0.8,0,0);
	glutWireCube(0.2);

	glRotatef(mainLoop, 0,0,1);
	glTranslatef(0.4,0,-0.4);
	glutWireCube(0.2);

	glRotatef(mainLoop, 0,0,1);
	glTranslatef(0,0,0.8);
	glutWireCube(0.2);

	glRotatef(mainLoop, 0,0,1);
	glTranslatef(0,-0.4,-0.4);
	glutWireCube(0.2);
	glPopMatrix();
}

void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);
	glViewport(0,0,w,h);
	return;
}


void MyIdle()
{
	mainLoop += 0.01;
	if(mainLoop > 360){mainLoop = 0;}
	glutPostRedisplay();
	return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutInitDisplayMode(GLUT_DEPTH);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutIdleFunc(MyIdle);


	glutMainLoop();
}
