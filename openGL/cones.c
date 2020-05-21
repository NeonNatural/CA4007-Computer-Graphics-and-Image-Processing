/*
cube with cones on each face and light source on top of each cone
*/

#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
float eyex, eyey, eyez =1.0;


void cuboids();
void init(){

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
}
void display(void)
{




	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1,1,1,0.0,0.0,0.0,0.0,1.0,0.0);






	glEnable(GL_LIGHTING);


	GLfloat pos[4] = {0.0,1.0,0.0,0.0};
	GLfloat pos2[4] = {0.0,0.0,1.0,0.0};

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0,GL_POSITION,(pos,pos2));




	cuboids();

	glFlush();
	return;
}

void cuboids(){

	glPushMatrix();
	glColor3f(1.0,0.0,1.0);
	glutSolidCube(0.5);

	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glTranslatef(0,0.4,0);
	glRotated(65, -1.0, 0.0, 0.0);
	glutWireCone(.1/*base radius size*/,0.3/*height*/,20.0/*stacks*/,20.0/*stacks*/); //top cone
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	glTranslatef(0.4,0,0);
	glRotated(65, 0.0, 1.0, 0.0);
	glutWireCone(.1/*base radius size*/,0.3/*height*/,20.0/*stacks*/,20.0/*stacks*/);
	glPopMatrix();  //right face cone

	glPushMatrix();

	glTranslatef(0.0,-0.4,0);
	glRotated(65, 1.0, 0.0, 0.0);
	glutWireCone(.1/*base radius size*/,0.3/*height*/,20.0/*stacks*/,20.0/*stacks*/);
	glPopMatrix();  //bottom face cone

	glPushMatrix();
	glColor3f(1.0,1.0,0.0);
	glTranslatef(-0.4,0.0,0);
	glRotated(65, 0.0, -1.0, 0.0);
	glutWireCone(.1/*base radius size*/,0.3/*height*/,20.0/*stacks*/,20.0/*stacks*/);
	glPopMatrix();  //left face cone

	glPushMatrix();
	glColor3f(0.0,1.0,1.0);
	glTranslatef(0.0,0.0,-0.4);
  glRotated(180, 0.0, -1.0, 0.0);
	glutWireCone(.1/*base radius size*/,0.3/*height*/,20.0/*stacks*/,20.0/*stacks*/);
	glPopMatrix();  //back face cone

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glTranslatef(0.0,0.0,0.4);
  //glRotated(180, 0.0, -1.0, 0.0); no need to change cone already pointing towards u
	glutWireCone(.1/*base radius size*/,0.3/*height*/,20.0/*stacks*/,20.0/*stacks*/); //top cone
	glPopMatrix();  //front face cone





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

void MySpecial(GLint key, GLint x, GLint y)
{


if(key == GLUT_KEY_RIGHT) eyex += 1;
else if(key == GLUT_KEY_LEFT) eyex -= 1;
if(key == GLUT_KEY_UP) eyey += 1;
else if(key == GLUT_KEY_DOWN) eyey -= 1;

glutPostRedisplay();
glFlush();
return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);

	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(MySpecial);
	init();

	glutMainLoop();
}
