#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
//roatate cube with arrow keys
float x_rot = 0.0;
float y_rot = 0.0;
void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);


	glRotatef(x_rot,1,0,0);
	glRotatef(y_rot,0,1,0);

	glutWireCube(0.5);

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



void MySpecial(GLint key, GLint x, GLint y)
{


if(key == GLUT_KEY_RIGHT) y_rot += 1;
else if(key == GLUT_KEY_LEFT) y_rot -= 1;
if(key == GLUT_KEY_UP) x_rot += 1;
else if(key == GLUT_KEY_DOWN) x_rot -= 1;

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
	glutSpecialFunc(MySpecial);


	glutMainLoop();
}
