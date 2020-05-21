#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
//Draw cube at the location of the mouse click
GLfloat x11,y11;
float rot = 0.0;
float size = 0.05;

void cube(){
  glBegin(GL_POLYGON);
		glVertex2f(-size,-size);
		glVertex2f(-size,size);
		glVertex2f(size,size);
		glVertex2f(size,-size);
	glEnd();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

  glTranslatef(x11,y11,0);
  //glRotatef(rot, 0, 1, 0);


  cube();
	glFlush();
  glTranslatef(-x11,-y11,0); //MAKE SURE TO DO THIS TO GO BACK TO ORIGIN


	return;
}

void mouse(int button, int mouseState, int x, int y) {


    if(button == GLUT_LEFT_BUTTON && mouseState == GLUT_DOWN) {
      x11 = (x-250.0)/250.0;
      y11= -(y-250.0)/250.0;



		glutPostRedisplay();
    }
    return;
}

void mymenu(int value)
{
if(value == 1) {glRotatef(20, 0, 1, 0); glutPostRedisplay();}
if(value == 2){size +=0.05;glutPostRedisplay();}
if(value == 3){size -= 0.05 ;glutPostRedisplay();}
if(value == 4){ exit(0);}
}

int main(int argc, char **argv)
{
  GLint id;
	glutInit(&argc, argv);
  glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
  glutMouseFunc(mouse);
  id = glutCreateMenu(mymenu);
  glutAddMenuEntry("Rotate",1);
  glutAddMenuEntry("Big",2);
  glutAddMenuEntry("Small",3);
  glutAddMenuEntry("exit",4);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop();
}
