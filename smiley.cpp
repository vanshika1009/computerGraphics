#include<GL/glut.h>
#include<GL/gl.h>
#include<cmath>

void draw(void){

glClear(GL_COLOR_BUFFER_BIT);

float t1,t2,t3,t4,t5,t6;

glPointSize(2);
 glBegin(GL_POINTS);
 for(int i=0;i<360;i++)
  {
  glVertex3f(200+150*cos(3.14159*i/180),200+150*sin(3.14159*i/180),0);
  
}  
 
 glEnd();

glPointSize(2);
 glBegin(GL_POINTS);
 for(int i=0;i<360;i++)
  {
  glVertex3f(240+10*cos(3.14159*i/180),250+10*sin(3.14159*i/180),0);
  
}  
 
 glEnd();

glPointSize(2);
 glBegin(GL_POINTS);
 for(int i=0;i<360;i++)
  {
  glVertex3f(155+10*cos(3.14159*i/180),250+10*sin(3.14159*i/180),0);
  
}  
 
 glEnd();


glPointSize(2);
 glBegin(GL_POINTS);
 for(int i=225;i<315;i++)
  {
  glVertex3f(200+50*cos(3.14159*i/180),200+50*sin(3.14159*i/180),0);
  
}  
 
 glEnd();


 glBegin(GL_LINES);
  glVertex2f(200,220);
  glVertex2f(200,180);
 glEnd();
  

glFlush();
}

int main(int argc,char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(500,500);
glutCreateWindow("SMILE");
//init();
//glClearColor(0,0,0,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,500,-100,500);
glutDisplayFunc(draw);
glutMainLoop();

return 0;
}
