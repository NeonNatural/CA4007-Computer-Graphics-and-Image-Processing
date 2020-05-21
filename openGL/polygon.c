#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
//draw polygon with mouse click, select number of corners from mouse menu and clear the screen usng mouse menu
int counter = 1;
float x11=0.0,y11=0.0,x2=0.0,y2=0.0,x3=0.0,y3=0.0,x4=0.0,y4=0.0,x5=0.0,y5=0.0;
int polyCount = 3;
void init(){
	glClearColor(0.0,0.0,1.0,1.0);
}
void three_poly(){
	glBegin(GL_POLYGON);
		glVertex2f(x11,y11);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
	glEnd();
}
void four_poly(){
	glBegin(GL_POLYGON);
		glVertex2f(x11,y11);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
	glEnd();
}
void five_poly(){
	glBegin(GL_POLYGON);
		glVertex2f(x11,y11);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
		glVertex2f(x5,y5);
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	if(counter > polyCount){
	glColor3f(1,0,0);
	if(polyCount == 3){three_poly();}
	if(polyCount == 4){four_poly();}
	if(polyCount == 5){five_poly();}
counter = 1;}

	glFlush();
	return;
}

void mouse(int button, int mouseState, int x, int y) {


    if(button == GLUT_LEFT_BUTTON && mouseState == GLUT_DOWN) {


			if(counter == 1){
				x11 = ((x*2)-500.0)/500.0;
	      y11= -((y*2)-500.0)/500.0;
				counter ++;
				return;
			}
			if(counter == 2){
				x2 = ((x*2)-500.0)/500.0;
				y2 = -((y*2)-500.0)/500.0;
				counter ++;
				return;
			}

			if(counter == 3){
				x3 = ((x*2)-500.0)/500.0;
				y3 = -((y*2)-500.0)/500.0;
				counter ++;
				if(polyCount == 3){glutPostRedisplay(); return;}
				return;
			}

			if(counter == 4){
				x4 = ((x*2)-500.0)/500.0;
				y4 = -((y*2)-500.0)/500.0;
				counter++;
				if(polyCount == 4){glutPostRedisplay(); return;}
				return;

			}
			if(counter == 5){
				x4 = ((x*2)-500.0)/500.0;
				y4 = -((y*2)-500.0)/500.0;
				counter++;
				if(polyCount == 5){glutPostRedisplay(); return;}
				return;

			}

    }

}

void mymenu(int value){
	if(value == 1){glClear(GL_COLOR_BUFFER_BIT);glutPostRedisplay();}//clear screen
	if(value == 0){  exit(0); }
	if(value == 3){  polyCount = 3; }
	if(value == 4){  polyCount = 4; }
	if(value == 5){  polyCount = 5; }

}

int main(int argc, char **argv)
{
	int id;
	glutInit(&argc, argv);
	glutInitWindowSize(500.0,500.0);
	glutInitWindowPosition(500.0,200);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);


	id = glutCreateMenu(mymenu);
	glutAddMenuEntry("Exit",0);
	glutAddMenuEntry("Clear",1);
	glutAddMenuEntry("3 poly",3);
	glutAddMenuEntry("4 poly",4);
	glutAddMenuEntry("5 poly",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	init();
	glutMainLoop();}
