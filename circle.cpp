#include<math.h>
#include<GL/glut.h>

const int n = 1000;
const GLfloat R = 0.5f;
const GLfloat PI = 3.1415926536f;
void init(void)
{
	int i;
	
	glEnable(GL_BLEND);             //启用混合功能，将图形颜色同周围颜色相混合  
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);  
        glEnable(GL_POINT_SMOOTH);       //点抗锯齿  
        glEnable(GL_LINE_SMOOTH);        //线抗锯齿  
        glEnable(GL_POLYGON_SMOOTH);     //多边形抗锯齿  
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	for(i = 0 ; i < n ; i ++ )
	{
		glVertex2f(R*cos(2*PI/n*i),R*sin(2*PI/n*i));
	}
	glEnd();
	glFlush();
}

int main(int argc , char * argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("circle");
	glutDisplayFunc(&init);
	glutMainLoop();
	return 0;
}
