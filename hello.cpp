#include<GL/glut.h>

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.5f,-0.5f,0.5f,0.5f);
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//不懂
	glutInitWindowPosition(100,100);//设置窗口初始位置
	glutInitWindowSize(400,400);//设置窗口大小
	glutCreateWindow("the first openGL program!!!");//将上述的属性设置成窗口，同时设置一个窗口的名字
	glutDisplayFunc(&myDisplay);//窗口调用的画图函数
	glutMainLoop();	//让主函数不断循环调用，以在屏幕上正常成像，否则只有一帧的显示图片，表象为没有图片显示
	return 0;
}
