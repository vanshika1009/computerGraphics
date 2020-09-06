#include<gl/glut.h>
#include<math.h>

void init(){
    glClearColor(1,1,1,0);
}

void line_join(float x1 , float y1 , float x2 , float y2){

    glBegin(GL_LINES);
    glLineWidth(10.0);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}


void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);



    glColor3f(0.0,1.0,1.0);

    line_join(0.0, 1.0, -0.86, -0.50);
    line_join(0.0, 1.0, 0.86, -0.50);
    line_join(-0.86, -0.50, 0.86, -0.50);

    glColor3f(1.0,0.0,0.0);


    line_join(0.0, -1.0, 0.86, 0.50);
    line_join(0.0, -1.0, -0.86, 0.50);
    line_join(0.86, 0.50, -0.86, 0.50);

    glColor3f(0.0,0.0,1.0);


    line_join(0.0, 0.5, 0.43, -0.25);
    line_join(0.0, 0.5, -0.43, -0.25);
    line_join(0.43, -0.25, -0.43, -0.25);

    glColor3f(0.0,0.0,0.0);

    line_join(0.0, -0.250, 0.216, 0.125);
    line_join(0.0, -0.250, -0.216, 0.125);
    line_join(0.216, 0.125, -0.216, 0.125);


    float x,y;
glColor3f(1, 1, 0);
for(double i =0; i <= 360;){
    glBegin(GL_TRIANGLES);
    x=5*cos(i);
    y=5*sin(i);
    glVertex2d(x, y);
    i=i+.5;
    x=5*cos(i);
    y=5*sin(i);
    glVertex2d(x, y);
    glVertex2d(0, 0);
    glEnd();
    i=i+.5;
}
glEnd();

    glFlush();
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(550, 550);
    glutCreateWindow("Devashish");
    init();
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
