#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

float x_pos = -2.1;
int state = 1;

void init(){

	glClearColor(0.0, 0.0, 0.0, 1.0);
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

			glColor3f(1.0,1.0,0.0);
			break;


		case 0:
		if(x_pos > -15)
		x_pos -= 0.15;
		else
			state= 1;
			glColor3f(1.0,0.0,0.0);
			break;
	}
}
void cube(){
	//front
		glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    //back
    glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    //right
    glColor3f(0.0,0.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    //left
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    //top
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0);
    //bottom
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
		glEnd();
}
/*
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-1.0,-1.0,0.0);
glVertex3f(1.0,-1.0, 0.0);
glVertex3f(1.0,1.0, 0.0);
glEnd();
*/


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//glShadeModel(GL_SMOOTH is default); controls wether colours blend or not

	glTranslatef(0.0,0.0,-8.0);
	glRotatef(60.0, 1.0, 1.0, 1.0);

	cube();

	glutSwapBuffers();

}

void reshape(GLsizei w, GLsizei h){

	glViewport(0,0, w, h); // at what size the window gets clipped
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(-10, 10, -10, 10); //2d
	gluPerspective(60/* FOV */ , 1/*aspec ratio*/, 2.0/*nearclip plcae on the Z axis*/,50.0/*far clip plane both of these are actually engative*/);
	glMatrixMode(GL_MODELVIEW);
}



int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutTimerFunc(0, timer, 0);
	init();
	glutMainLoop();
}
