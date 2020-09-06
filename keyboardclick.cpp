#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
GLfloat t,u=1;
void init(){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,500,0,500,0,10);
}
void display(){
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(t,u,0);
     glBegin(GL_TRIANGLES);
     glVertex2f(50,50);
     glVertex2f(200,50);
     glVertex2f(125,250);
     glEnd();
     glFlush();
}


void key(unsigned char button,int x,int y){
    if(button=='S'){
        t=0;
        u=1;
    }
    else{

    }
    glutPostRedisplay();
}


void mouse(int button,int state,int x,int y){

    if(button==GLUT_RIGHT_BUTTON){
        t=1;
        u=0;
    }
    else{

    }
    glutPostRedisplay();
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
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutMainLoop();
}
