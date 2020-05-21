


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


  GLUquadricObj *MyCylinder;
	MyCylinder = gluNewQuadric();
	gluQuadricDrawStyle(MyCylinder, GLU_LINE);
    glPushMatrix();
    glRotatef(-90.0,1.0,0.0,0.0);
    glTranslatef(0,0,-0.5);
  	gluCylinder(MyCylinder,0.05/*base diameter*/,0.05/*top diameter*/,0.5/*height*/,50,50);
    glPopMatrix();
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

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500.0,500.0);
	glutInitWindowPosition(500.0,200);
	glutCreateWindow("simple");
	glutDisplayFunc(display);

	//init();
	glutMainLoop();
}
