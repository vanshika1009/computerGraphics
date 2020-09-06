#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>


void init(){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,500,0,500,0,10);
}


void display(){
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0.0,0.0,1.0);
     glBegin(GL_TRIANGLES);
     glVertex2f(100,100);
     glVertex2f(400,100);
     glVertex2f(250,400);

     glColor3f(0.0,1.0,0.0);
     glVertex2f(100,300);
     glVertex2f(400,300);
     glVertex2f(250,20);

     glColor3f(1.0,0.0,0.0);
     glVertex2f(180,150);
     glVertex2f(320,150);
     glVertex2f(250,300);

     glColor3f(1.0,1.0,0.0);
     glVertex2f(210,220);
     glVertex2f(250,150);
     glVertex2f(290,220);
     glEnd();

     glBegin(GL_POLYGON);
     glColor3f(1.0,0.0,1.0);
     for(int i=0;i<360;i++)
     {
         float theta= i*3.142/180;
         glVertex2f(23*cos(theta)+250,23*sin(theta)+197);
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
