#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

GLfloat xshift, yshift, x1, y1;
GLint xR, zR;
float angle;

void MySpecial(GLint key, GLint x, GLint y)
{
	if(key == GLUT_KEY_UP)
		xshift = 1.0f; yshift = 0.0f;
	if(key == GLUT_KEY_DOWN)
		xshift = -1.0f; yshift = 0.0f;
	if(key == GLUT_KEY_LEFT)
		yshift = -1.0f; xshift = 0.0f;
	if(key == GLUT_KEY_RIGHT)
		yshift = 1.0f; xshift = 0.0f;
	glutPostRedisplay();
}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{

	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
			x1=(x-250.0)/125.0;
			y1=(y-250)/125.0;
	{
		if (x1 > 0 & y1 > 0)
			{
				xR = 1;
				zR = -1;
				glutPostRedisplay();
			}
		if (x1 > 0 & y1 < 0)
			{
				xR = -1;
				zR = -1;
				glutPostRedisplay();
			}
		if (x1 < 0 & y1 < 0)
			{
				xR = -1;
				zR = 1;
				glutPostRedisplay();
			}
		if (x1 < 0 & y1 > 0)
			{
				xR = 1;
				zR = 1;
				glutPostRedisplay();
			}
        glutPostRedisplay();
	}

	return;
}

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
	//glRotatef(angle, -1.0, 0, 1.0);
	glRotatef(angle, xR, 0, zR);
	//glRotatef(angle, 0, 0.0, 0.0);
	glutWireCube(0.5);

	angle += 15.05f;

	glFlush();
	return;
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






int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	//glutIdleFunc(display);
	glutSpecialFunc(MySpecial);
	glutMouseFunc(MyMouse);


	glutMainLoop();
}
