#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"

/*cube showing plastic and brass colours rotate using arrow keys */
//red plastic
GLfloat ambient[4] = {0.3, 0.0, 0.0, 1.0};
GLfloat diffuse[4] = {0.6, 0.0, 0.0, 1.0};
GLfloat specular[4] = {0.8, 0.6, 0.6, 1.0};
GLfloat shininess = 32.0;
GLfloat position[4] = {0.0,1.0,1.0,0.0};
GLfloat position2[4] = {1.0,1.0,0.0,0.0};

float x_rot = 0.0;
float y_rot = 0.0;
/* Brass colours
GLfloat  ambient[4] = {0.33 , 0.22 , 0.03 , 1.0 };
	GLfloat  diffuse[4] = {0.78 , 0.57 , 0.11 , 1.0 };
	GLfloat specular[4] = {0.99 , 0.91 , 0.81 , 1.0 };

	GLfloat shininess = 27.8; //32.0;
*/
void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);
	glLightfv(GL_LIGHT0, GL_POSITION, (position,position2));


	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	glRotatef(x_rot,1,0,0);
	glRotatef(y_rot,0,1,0);

	glutSolidCube(0.5);

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


void special(int button, int x, int y){
	if(button == GLUT_KEY_RIGHT){y_rot +=5;}
	if(button == GLUT_KEY_LEFT){y_rot -=5;}
	if(button == GLUT_KEY_UP){x_rot +=5;}
	if(button == GLUT_KEY_DOWN){x_rot -=5;}
	glutPostRedisplay();


}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutSpecialFunc(special);


	glutMainLoop();
}
