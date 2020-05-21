#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

/*
-the program has a cylinder for a base
-cone on top of the MyCylinder
-polygon for the sails
-and an idle function to rotate the sails
*/
float r=0.0,g=0.0,b=0.7;
float eyex=0.0,eyey=0.0,eyez=0.5;
float x11,y11;
float rotz=90.0;
void init(){
	glClearColor(r,g,b,1.0);
  glEnable(GL_DEPTH_TEST);//enabled depth so that structures arent overlapping
}

void setEye(){
	gluLookAt(eyex,eyey,eyez,0.0,0.0,0.0,0.0,1.0,0.0);
}
void windmilltower(){//the tower
  GLUquadricObj *MyCylinder;
	MyCylinder = gluNewQuadric();
	gluQuadricDrawStyle(MyCylinder, GLU_LINE);
    glPushMatrix();
    glRotatef(-90.0,1.0,0.0,0.0);
    glTranslatef(0,0,-0.5);

  	gluCylinder(MyCylinder,0.05/*base diameter*/,0.05/*top diameter*/,0.3/*height*/,200,200);
    glPopMatrix();
}

void sails(){//assembles the sails

  glPushMatrix();
  glColor3f(0.4,0.7,0.5);
  glTranslatef(0,-0.1,0.1);
  glBegin(GL_POLYGON);
	glVertex3f(-0.03,-0.3,0);
	glVertex3f(-0.03,0.3,-0);
	glVertex3f(0.03,0.3,-0);
	glVertex3f(0.03,-0.3,0);
	glEnd();
  glRotatef(rotz,0,0,1);
  glBegin(GL_POLYGON);

  glVertex3f(-0.03,-0.3,0);
  glVertex3f(-0.03,0.3,-0);
  glVertex3f(0.03,0.3,-0);
  glVertex3f(0.03,-0.3,0);
  glEnd();


  glPopMatrix();
}


void windmill(){//assembels the cone, cube and cyldiner
  glPushMatrix();
  glColor3f(0,1,0);
  windmilltower();
  //glRotatef(90,0,0,1);
  sails();
  //glRotatef(90,0,0,-1);
  glTranslatef(0,-0.09,0);
  glColor3f(1,0,0);
  glutSolidCube(0.07);
  glTranslatef(0,0.09,0);
  glColor3f(1,1,0);
  glTranslatef(0,-0.2,0);
  glRotated(65, -1.0, 0.0, 0.0);

  glutWireCone(.05/*base radius size*/,0.1/*height*/,200.0/*stacks*/,200.0/*stacks*/); //top cone
  glPopMatrix();
}



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  setEye();
  glTranslatef(0,0,-0.5);
  windmill();
	glFlush();
	return;
}

/*
void gluCylinder(	GLUquadric* quad,
 	GLdouble base,
 	GLdouble top,
 	GLdouble height,
 	GLint slices,
 	GLint stacks)
*/

void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
gluPerspective(60/* FOV */ , 1/*aspec ratio*/, 0.1/*nearclip plcae on the Z axis*/,50.0/*far clip plane both of these are actually engative*/);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0,0,w,h);
	return;
}

void idle(){
	rotz += 20;
  //glutPostRedisplay();

}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500.0,500.0);
	glutInitWindowPosition(500.0,200);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
  glutReshapeFunc(MyReshape);

glutIdleFunc(idle);
	init();
	glutMainLoop();
}
