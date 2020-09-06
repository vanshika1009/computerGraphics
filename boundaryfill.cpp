#include <GL/glut.h>
  int ww = 600, wh = 500;
  float fillCol[3] = {0.4,0.0,0.0};
  float borderCol[3] = {0.0,0.0,0.0};
  void setPixel(int pointx, int pointy, float f[3])
  {
       glBegin(GL_POINTS);
            glColor3fv(f);
            glVertex2i(pointx,pointy);
       glEnd();
       glFlush();
  }
  void getPixel(int x, int y, float pixels[3])
  {
       glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);
  }
  void drawPolygon(int x1, int y1, int x2, int y2)
  {
       glColor3f(0.0,0.0,0.0);
       glBegin(GL_LINES);
            glVertex2i(x1, y1);
            glVertex2i(x1, y2);
       glEnd();
       glBegin(GL_LINES);
            glVertex2i(x2, y1);
            glVertex2i(x2, y2);
       glEnd();
       glBegin(GL_LINES);
            glVertex2i(x1, y1);
            glVertex2i(x2, y1);
       glEnd();
       glBegin(GL_LINES);
            glVertex2i(x1, y2);
            glVertex2i(x2, y2);
       glEnd();
       glFlush();
  }
  void display()
  {
       glClearColor(1.0,1.0,1.0, 1.0);
       glClear(GL_COLOR_BUFFER_BIT);
      drawPolygon(150,250,200,300);
       glFlush();
  }
  void boundaryFill4(int x,int y,float fillColor[3],float borderColor[3])
  {
       float interiorColor[3];
       getPixel(x,y,interiorColor);
       if((interiorColor[0]!=borderColor[0] && (interiorColor[1])!=borderColor[1] && (interiorColor[2])!=borderColor[2]) && (interiorColor[0]!=fillColor[0] && (interiorColor[1])!=fillColor[1] && (interiorColor[2])!=fillColor[2]))
       {
            setPixel(x,y,fillColor);
            boundaryFill4(x+1,y,fillColor,borderColor);
            boundaryFill4(x-1,y,fillColor,borderColor);
            boundaryFill4(x,y+1,fillColor,borderColor);
            boundaryFill4(x,y-1,fillColor,borderColor);
       }
  }
  void mouse(int btn, int state, int x, int y)
  {
       if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
       {
            int xi = x;
            int yi = (wh-y);
            boundaryFill4(xi,yi,fillCol,borderCol);
       }
  }
  void myinit()
  {
       glViewport(0,0,ww,wh);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
       glMatrixMode(GL_MODELVIEW);
  }
  int main(int argc, char** argv)
  {
       glutInit(&argc,argv);
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
       glutInitWindowSize(ww,wh);
       glutCreateWindow("Bountry-Fill-Recursive");
       glutDisplayFunc(display);
       myinit();
       glutMouseFunc(mouse);
       glutMainLoop();
       return 0;
  }
/*
#include <iostream>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
using namespace std;
void delay(float ms){
    clock_t goal = ms + clock();
    while(goal>clock());
}
void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}
void bound_it(int x, int y, float* fillColor, float* bc){
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
     color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_it(x+1,y,fillColor,bc);
        bound_it(x-2,y,fillColor,bc);
        bound_it(x,y+2,fillColor,bc);
        bound_it(x,y-2,fillColor,bc);
    }
}
void mouse(int btn, int state, int x, int y){
    y = 480-y;
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            float bCol[] = {1,0,0};
            float color[] = {0,0,1};
            //glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,intCol);
            bound_it(x,y,color,bCol);
        }
    }
}
void world(){
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(150,100);
        glVertex2i(300,300);
        glVertex2i(450,100);
    glEnd();
    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Many Amaze Very GL WOW");
    glutDisplayFunc(world);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
*/
