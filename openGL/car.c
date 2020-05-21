#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

float xmov=0.0,ymov=0.0,zmov=-1.0;
float eyex=0.0,eyey=1.0,eyez=5.0;
float rot=0,wheelrot=0;
float r=0.5,g=0.5,b=0.5;

int id;//id of menu
void car();
void wheels();

void init(){
	glEnable(GL_DEPTH_TEST);//enable depth
	glClearColor(0.0,0.0,1.0,1.0);
}

void setEye(){
	gluLookAt(eyex,eyey,eyez,0.0,0.0,0.0,0.0,1.0,0.0);
}

void road(){
	glPushMatrix();
	glColor3f(0.4,0.7,0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.9,-0.5,30);
	glVertex3f(-0.9,-0.5,-30);
	glVertex3f(0.9,-0.5,-30);
	glVertex3f(0.9,-0.5,30);
	glEnd();

	glRotatef(90,0,1,0);

	glBegin(GL_POLYGON);

	glVertex3f(-0.9,-0.5,30);
	glVertex3f(-0.9,-0.5,-30);
	glVertex3f(0.9,-0.5,-30);
	glVertex3f(0.9,-0.5,30);
	glEnd();
	glPopMatrix();
}
void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//enable depth and rgb

	glLoadIdentity();


glEnable(GL_LIGHTING);
glColorMaterial(GL_FRONT, GL_DIFFUSE);

	setEye();


	road();

	glTranslatef(xmov,ymov,zmov);
	glRotatef(rot,0,1,0);
	car();

	glFlush();
	return;
}

void wheels(){
	glPushMatrix();
	glRotatef(90,0,1,0);
	glRotatef(wheelrot,0,0,1);
	glutSolidTorus(0.05,0.1,12,12);

glPopMatrix();}

void carBody(){




	glPushMatrix();

	glColor3f(r,g,b);
	glutSolidCube(0.5);
	GLfloat pos[4] = {0,0,0.30};
	GLfloat pos2[4] = {0,0,0.30};
	glTranslatef(0,0.35,0);
	glColor3f(1,1,1);
	glutSolidCube(0.25);

	glTranslatef(0,-0.35,0);
	glTranslatef(0.15,0,0.30);
	glColor3f(1,0,0);
	glutSolidTorus(0.03,0.05,12,12);
	glTranslatef(-0.30,0,0);
	glColor3f(1,0,0);
	glutSolidTorus(0.03,0.05,12,12);


	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, (pos,pos2));
	glPopMatrix();
	return;
	//glLoadIdentity();
}

void car(){

	glPushMatrix();

	carBody();
	glColor3f(0,0,0);
	glTranslatef(0.30,-0.25, 0.25);
	wheels();
	glTranslatef(-0.6,0, 0.0);//front left
	wheels();

	glTranslatef(0,0, -0.5);//back left
	wheels();

	glTranslatef(0.6,0, 0);//back right
	wheels();

	glPopMatrix();
	return;
}

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

void MySpecial(GLint key, GLint x, GLint y)
{

if(key == GLUT_KEY_RIGHT){eyex +=0.5;}
if(key == GLUT_KEY_LEFT){eyex -=0.5;}
if(key == GLUT_KEY_UP){eyey +=0.5;}
if(key == GLUT_KEY_DOWN){eyey -=0.5;}

glutPostRedisplay();

return;
}

void MyKeyboard(unsigned char key, GLint x, GLint y)
{

if(key == 'w'){zmov-= 0.5; }
if(key == 's'){zmov+= 0.5; }
if(key == 'a'){xmov-= 0.5; }
if(key == 'd'){xmov+= 0.5 ;}
if(key == 'c'){rot+= 90 ;}
glutPostRedisplay();
return;
}

void mymenu(int value){
	if(value == 0){  exit(0);}
	if(value == 1){  r=1;g=1;b=0;}
	if(value == 2){  r=0;g=1;b=0; }
	if(value == 3){  r=1;g=0;b=1; }
	glutPostRedisplay();
}
void idle(){
	wheelrot += 20;
	glutPostRedisplay();

}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);//depth
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);

	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutIdleFunc(idle);
	init();


	id = glutCreateMenu(mymenu);
	glutAddMenuEntry("Exit",0);
	glutAddMenuEntry("Yello",1);
	glutAddMenuEntry("Green",2);
	glutAddMenuEntry("Pink",3);



	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();
}
