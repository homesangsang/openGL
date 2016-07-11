#include<GL/glut.h>

void drawVertex(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*
		画一个矩形的方法
		思路是在坐标系内建立四个点，然后依次连线
		代码分析：
			glBegin()函数是一个图形区域的开始，glEnd()函数是一个图形区域的结束，中间的glVertex*函数是确定的点
			确定的点必须两两一组，确定一条直线，glVertex的参数是点的坐标

		glBegin函数的参数：
			GL_POINTS:只在坐标中表示出来指定的点
			GL_LINES:每次连接两个点（一组）
			GL_LINE_STRIP:依次连接出现的点
			GL_LINE_LOOP:依次首尾连接出现的点
			GL_TRIANGLES:首尾连接之后填充连接起来的区域
			GL_TRIANGLE_STRIP:...
			GL_TRIANGLE_FAN

	*/
	glBegin(GL_LINES);
		glVertex2f(0.0f,0.0f);
		glVertex2f(0.6f,0.0f);

		glVertex2f(0.0f,0.6f);
		glVertex2f(0.6f,0.6f);

		glVertex2f(0.0f,0.0f);
		glVertex2f(0.0f,0.6f);

		glVertex2f(0.6f,0.6f);
		glVertex2f(0.6f,0.0f);
	glEnd();
	glFlush();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("画点");
	glutDisplayFunc(&drawVertex);
	glutMainLoop();
	return 0;
}
