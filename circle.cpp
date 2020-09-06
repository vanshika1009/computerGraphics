#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>

void init()
{
 glClearColor(0,0,0,0);
 glMatrixMode(GL_PROJECTION);
 glOrtho(-10,10,-10,10,20,-20);
}


void display()
{
  glClear(GL_COLOR_BUFFER_BIT);




 glPointSize(2);
 glColor3f(1.0,1.0,1.0);
 glBegin(GL_POINTS);

    float rad = 5;
    float x=0.0f,y=0.0f;
    while(x<=rad/1.2)
    {
        y= sqrt((rad*rad - x*x));
        glVertex2f(x,y);
        glVertex2f(x,-y);
        glVertex2f(-x,y);
        glVertex2f(-x,-y);
        glVertex2f(y,x);
        glVertex2f(-y,x);
        glVertex2f(y,-x);
        glVertex2f(-y,-x);
        x=x+0.01;
    }


    glEnd();


  glFlush();
}





int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(800,100);
 glutCreateWindow("Vanshika");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
}
