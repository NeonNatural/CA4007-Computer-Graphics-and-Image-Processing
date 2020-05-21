//gcc MyProg.c -o MyProg glut32.lib -lopengl32 -lglu32
#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>
#include <stdio.h>

#define Cos(x) cos(M_PI/180*(x))
#define Sin(x) sin(M_PI/180*(x))

int th = 0;
int ph = 0;



float dim = 1.0;

GLfloat xshift = 0.0, zshift = 0.0;
GLfloat objects[10][20];
GLint k=0, no_objects=0, item = 1;
GLfloat eyex=0.0, eyey=0.7, eyez=1.0;
GLint win2, win1;
GLfloat x1, z1, x2, z2;

GLfloat ambient[4] = {0.3, 0.0, 0.0, 1.0};
GLfloat diffuse[4] = {0.6, 0.0, 0.0, 1.0};
GLfloat specular[4] = {0.8, 0.6, 0.6, 1.0};
GLfloat shininess = 32.0;

GLfloat position[4] = {1.0,1.0,1.0,1.0};

float theta = M_PI/4;


void SetEye(){

		gluLookAt(eyex, eyey, eyez,0.0,0.0,0.0,0.0,1.0,0.0);


}

void tabletop(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.3,0.5,0.3);
	glutSolidCube(1.0);
	glPopMatrix();
	return;
}
void tableleg(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.05,0.3,0.05);
	glutSolidCube(1.0);
	glPopMatrix();
	return;
}

void table(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	glTranslatef(x,y,z);
	tabletop(0.0, 0.325, 0.0);
	tableleg(0.15, 0.15, 0.15);
	tableleg(-0.15, 0.15, 0.15);
	tableleg(0.15, 0.15, -0.15);
	tableleg(-0.15, 0.15, -0.15);
	glPopMatrix();
	return;
}

void matress(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.6,0.2,0.6);
	glutSolidCube(1.0);
	glPopMatrix();
	return;
}

void leg(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.05,0.1,0.05);
	glutSolidCube(1.0);
	glPopMatrix();
	return;
}

void bed(GLfloat x, GLfloat y, GLfloat z){
	glPushMatrix();
	glTranslatef(x,y,z);
	matress(0.0, 0.2, 0.0);
	leg(0.25, 0.05, 0.25);
	leg(-0.25, 0.05, 0.25);
	leg(0.25, 0.05, -0.25);
	leg(-0.25, 0.05, -0.25);
	glPopMatrix();
	return;
}

void wall(GLfloat xx1, GLfloat zz1, GLfloat xx2, GLfloat zz2)
{
	glBegin(GL_POLYGON);
	glVertex3f(xx2, 0.0, zz2);
	glVertex3f(xx2, 1.0, zz2);
	glVertex3f(xx1, 1.0, zz1);
	glVertex3f(xx1,0.0, zz1);
  glEnd();
	return;

}

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);


	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	SetEye();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	GLfloat x,y=-1.0,z,theta=0.0;

	glPushMatrix();
  glBegin(GL_POLYGON);
  //glNormal3f(0.0, 1.0, 0.0);
  glVertex3f(-2.0, 0.0, 0.5);
  glVertex3f(2.0, 0.0, 0.5);
  glVertex3f(2.0, 0.0, -1.5);
  glVertex3f(-2.0, 0.0, -1.5);
  glEnd();
  glPopMatrix();

	glPushMatrix();
  glBegin(GL_POLYGON);
  //glNormal3f(0.0, 1.0, 0.0);
  glVertex3f(-2.0, 1.0, 0.5);
  glVertex3f(2.0, 1.0, 0.5);
  glVertex3f(2.0, 1.0, -1.5);
  glVertex3f(-2.0, 1.0, -1.5);
  glEnd();
  glPopMatrix();




	for(k=0; k<no_objects; k++)
	{
	if(objects[0][k] == 1)
		bed(objects[1][k],0.0,objects[3][k]);
	else if(objects[0][k] == 2)
		table(objects[1][k],0.0,objects[3][k]);
	else
		wall(objects[1][k],objects[2][k],objects[3][k],objects[4][k]);
	}

	if(item == 1)
		bed(xshift,0.0,zshift);
	else if(item ==2)
		table(xshift,0.0,zshift);
	else
		wall(x1,z1,x2,z2);


	//wall(2.0, 0.5 ,2.0, -1.5);
	//wall(-2.0, 0.5 ,-2.0, -1.5);





	glFlush();
	return;
}

void plandisplay(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pos[4] = {1.0,1.0,1.0,0.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 1.0, 0.0,0.0,0.0,0.0,0.0,0.0,-1.0);

	GLfloat x,y=-1.0,z,theta=0.0;

	glPushMatrix();
  glBegin(GL_POLYGON);
  //glNormal3f(0.0, 1.0, 0.0);
  glVertex3f(-2.0, 0.0, 0.5);
  glVertex3f(2.0, 0.0, 0.5);
  glVertex3f(2.0, 0.0, -1.5);
  glVertex3f(-2.0, 0.0, -1.5);
  glEnd();
  glPopMatrix();


	for(k=0; k<no_objects; k++)
	{
	if(objects[0][k] == 1)
		bed(objects[1][k],0.0,objects[3][k]);
	else
		table(objects[1][k],0.0,objects[3][k]);
	}

	if(item == 1)
		bed(xshift,0.0,zshift);
	else
		table(xshift,0.0,zshift);


	wall(x1, z1, x2, z2);






	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.3,5.0);
//	gluPerspective(60,1.0,0.3,5.0);
	glViewport(0,0,w,h);
	return;
}
void PlanReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
	//glFrustum(-1.0,1.0,-1.0,1.0,0.3,5.0);
//	gluPerspective(60,1.0,0.3,5.0);
	glViewport(0,0,w,h);
	return;
}
void MyMouse(GLint button, GLint state, GLint x, GLint y)
{
	static int first=1;

	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON)
	{
		if (first)
		{
			x1=(x-250.0)/125.0;
			z1=(y-250)/125.0;
		}
		else
		{
			x2=(x-250.0)/125.0;
			z2=(y-250)/125.0;
			glutPostRedisplay();
			glutPostWindowRedisplay(win1);

		}
		first = !first;
	}

	return;
}

void MySpecial(GLint key, GLint x, GLint y)
{
  if(key == GLUT_KEY_RIGHT) xshift += 0.1;
  else if(key == GLUT_KEY_LEFT) xshift -= 0.1;
  if(key == GLUT_KEY_UP) zshift += 0.1;
  else if(key == GLUT_KEY_DOWN) zshift -= 0.1;

  glutPostRedisplay();
	glutPostWindowRedisplay(win2);
  //glFlush();
}

void MyKeyboard(unsigned char key, GLint x, GLint y){
	if(key == 'q'){

		if(item < 3)
{
objects[0][k]=item;
objects[1][k]=xshift;
objects[2][k]=0.0;
objects[3][k]=zshift;
}
else
{
objects[0][k]=item;
objects[1][k]=x1;
objects[2][k]=z1;
objects[3][k]=x2;
objects[4][k]=z2;
}


no_objects++;
}

	if(key == 'd')eyex += 0.01;
	if(key == 'a')eyex -= 0.01;
	if(key == 'w')eyey += 0.01;
	if(key == 's')eyey -= 0.01;
	if(key == 'o')eyez += 0.01;
	if(key == 'i')eyez -= 0.01;

	glutPostRedisplay();
  glFlush();
}

void mymenu(int value)
{
item=value;
glutPostRedisplay();
glutPostWindowRedisplay(win2);
return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	win1 = glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(MySpecial);
	glutKeyboardFunc(MyKeyboard);

	glutCreateMenu(mymenu);
	glutAddMenuEntry("Bed",1);
	glutAddMenuEntry("Table", 2);
	glutAddMenuEntry("wall",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	win2 = glutCreateWindow("plan");
	glutDisplayFunc(plandisplay);
	glutReshapeFunc(PlanReshape);
	glutMouseFunc(MyMouse);

	//glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}
