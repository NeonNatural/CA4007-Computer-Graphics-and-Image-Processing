/*grid of squares that change colour when pressed eamo edition*/


#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <stdio.h>


int squares[100][5];
int clickedSquare = -1;

int j = 0;

void display(void)
{



for(int iy = 0; iy < 10; iy++){
	int y1 = 460 - (35 * iy);
	int y2 = 490 - (35 * iy);

   for(int i = 0; i < 10; i++){
		 int x1 = 10 + (35 * i);
		 int x2 = 40 + (35 * i);

		 int k = ((i + 1) + (iy * 10)) - 1;
		 squares[k][0] = x1;
		 squares[k][1] = x2;
		 squares[k][2] = y1;
		 squares[k][3] = y2;


		 if(k == 2){
			 printf("%d\n", squares[k][0]);
			 printf("%d\n", squares[k-1][0]);
		 }

		 if (k == clickedSquare) {
			 if (squares[k][4] == 1) {
				 glColor3f(1.0,1.0,1.0);
				 squares[k][4] = 0;
			 } else {
				 glColor3f(1.0,0.0,0.0);
				 squares[k][4] = 1;
			 }
		 } else {
			 if (squares[k][4] == 1) {
				 glColor3f(1.0,0.0,0.0);
			 } else {
				 glColor3f(1.0,1.0,1.0);
				 squares[k][4] = 0;
			 }
		 }






	glBegin(GL_POLYGON);
		glVertex2f(x1,y1);
		glVertex2f(x2,y1);
		glVertex2f(x2,y2);
		glVertex2f(x1,y2);
	glEnd();
	}

}

  glFlush();


	return;

}

void MyMouse(GLint button, GLint state, GLint x, GLint y)
{


	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON)
	{
	    int yc = 500 - y;

			for(int i = 0; i < 100; i++) {

				if(yc > squares[i][2] && yc < squares[i][3] && x > squares[i][0] && x < squares[i][1]){
					clickedSquare = i;
					glutPostRedisplay();

					break;
				}

				clickedSquare = -1;
			}

	}

	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLfloat)w,0.0,(GLfloat)h);

	return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("mouse");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(MyMouse);



	glutMainLoop();
}
