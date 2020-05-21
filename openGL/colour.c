/*
background Colours changed based on what colour is under the mouse by reading pixel colours

*/


#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
float r=0.0,g=0.0,b=0.0;

float x11,y11;
void init(){
	glClearColor(r,g,b,1.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//glClearColor(r,g,b,1.0);
	glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(-0.5,-0.5);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(-0.5,0.5);
		glColor3f(0.0,0.0,1);
		glVertex2f(0.5,0.5);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(0.5,-0.5);
	glEnd();

	glFlush();
	return;
}
void mouse(int x, int y){

		unsigned char pixel[3];
		glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
		r = pixel[0]/255.0;
		g = pixel[1]/255.0;
		b = pixel[2]/255.0;
		glClearColor(r,g,b,1.0);
		glutPostRedisplay();
		return;



}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500.0,500.0);
	glutInitWindowPosition(500.0,200);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutPassiveMotionFunc(mouse);
	//init();
	glutMainLoop();
}
