#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
//rotate cube wth mouse click 2019 repeats Q5(b)
float x_rot, y_rot;
float x11, y11;

float xmov, ymov, zmov;
void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

	glRotatef(x_rot,1,0,0);
	glRotatef(y_rot,0,1,0);

	glTranslatef(xmov, ymov, zmov);
	glutSolidCube(0.5);
	//glTranslatef(-xmov, -ymov, -zmov);
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
void mouse(int button, int mouseState, int x, int y) {


    while(button == GLUT_LEFT_BUTTON && mouseState == GLUT_DOWN) {
      x11 = ((x*2)-500.0)/500.0;
      y11= -((y*2)-500.0)/500.0;

      if(x11>0){
				x_rot+= 20;}

		if(x11<0){
			x_rot -= 20;}
		if(y11>0){
			y_rot += 20;}
		if(y11<0){
			y_rot -= 20;}
			glutPostRedisplay();
			return;
}
}

void MyKeyboard(unsigned char key, GLint x, GLint y)
{

if(key == 'w')
{
	ymov += 1;
	glutPostRedisplay();

	return;
}
if(key == 's')
{
	ymov -= 1;
	glutPostRedisplay();

	return;
}
if(key == 'a')
{
	xmov -= 1;
	glutPostRedisplay();

	return;
}
if(key == 'd')
{
	xmov += 1;
	glutPostRedisplay();

	return;
}




}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(MyKeyboard);

	glutMainLoop();
}
