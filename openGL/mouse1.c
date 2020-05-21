#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
/*grid squares attempts doesnt really worlk */
GLfloat x11,y11;
float pos = 1.1;
int counter = 10;
float x_pos = 0.0;
int i= 0;

int state = 0;

void init(){

	glClearColor(1.0, 0.0, 0.0, .5);
	glEnable(GL_DEPTH_TEST);
}

void timer(){
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);

	switch (state) {
		case 1:
		if(x_pos < -5)
			x_pos += 0.30;
		else
			state = 0;

			glColor3f(.5,.5,0.0);
			break;


		case 0:
		if(x_pos > -15)
		x_pos -= 0.15;
		else
			state= 1;
			glColor3f(.5,0.0,0.0);
			break;
	}
}
void cube(){
	glBegin(GL_QUADS);
	glVertex3f(-.5,.5,0.0);
	glVertex3f(-.5,-.5,0.0);
	glVertex3f(.5,-.5, 0.0);
	glVertex3f(.5,.5, 0.0);
	glEnd();
}

void grid(){
	while(i<100){

		if(i == counter){glTranslatef(-11.0, -1.2,0.0); counter+=10;}

		glTranslatef(pos,0.0,0.0);
		cube();
		i++;

	}
}
/*
glBegin(GL_POLYGON);
glVertex3f(-.5,.5,0.0);
glVertex3f(-.5,-.5,0.0);
glVertex3f(.5,-.5, 0.0);
glVertex3f(.5,.5, 0.0);
glEnd();
*/


void display(void)
{
	glClear( GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	//glShadeModel(GL_SMOOTH is default); controls wether colours blend or not


	glTranslatef(-6.0,5.0,0.0);


	grid();
	glFlush();

}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{

		x11 = (x-250.0)/250.0;
		y11= -(y-250.0)/250.0;

		glTranslatef(x11,y11,0);
		glColor3f(1,0,0);
		cube();
		glutPostRedisplay();
}
return;
}

void reshape(GLsizei w, GLsizei h){

	glViewport(0,0, w, h); // at what size the window gets clipped
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10); //2d
	//gluPerspective(80/* FOV */ , 1/*aspec ratio*/, 2.0/*nearclip plcae on the Z axis*/,50.0/*far clip plane*/);
	glMatrixMode(GL_MODELVIEW);
}



int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);

	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutTimerFunc(0, timer, 0);
	init();
	glutMouseFunc(MyMouse);
	glutMainLoop();
}
