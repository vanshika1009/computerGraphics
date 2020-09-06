#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>


void init(){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-100,100,-100,100,0,10);
}


void display(){
     glClear(GL_COLOR_BUFFER_BIT);
     //glColor3f(0.0,0.0,1.0);

     //glPointSize(2);
     glBegin(GL_POINTS);
     glColor3f(1.0,1.0,1.0);

     float r = 70;

     float d = 3 - 2*r;
     float x=0.0,y=r;
     glVertex2f(x,y);
     glVertex2f(-x,y);
     glVertex2f(x,-y);
     glVertex2f(-x,-y);
     glVertex2f(y,x);
     glVertex2f(-y,x);
     glVertex2f(y,-x);
     glVertex2f(-y,-x);

     while(x<=y)
     {
         x = x + 0.01;
         if(d<=0)
         {
             d = d + 4*x + 6;
         }
         else
         {
             y = y - 0.01;
             d = d + 4*(x-y) +10;
         }
         glVertex2f(x,y);
         glVertex2f(-x,y);
         glVertex2f(x,-y);
         glVertex2f(-x,-y);
         glVertex2f(y,x);
         glVertex2f(-y,x);
         glVertex2f(y,-x);
         glVertex2f(-y,-x);
     }

     glEnd();
     glFlush();
}





int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("My Window");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
