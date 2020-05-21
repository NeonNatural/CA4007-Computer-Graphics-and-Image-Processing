#include <GL/gl.h>
#include <GL/glext.h>
#include "glut.h"
#include <math.h>



void RenderSineWave()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);  // clear background with black
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    double ar = w / h;
    glOrtho( -360 * ar, 360 * ar, -120, 120, -1, 1 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPointSize(10);
    glColor3f(1.0,0.0,0.0);

    glBegin(GL_POINTS);
    for(int i=0;i<361;i=i+5)
    {
        float x = (float)i;
        float y = 100.0 * sin(i *(6.284/360.0));
        glVertex2f(x,y);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 640, 480 );
    glutCreateWindow( "SineWave.cpp" );
    glutDisplayFunc( RenderSineWave );
    glutMainLoop();
    return 0;
}
