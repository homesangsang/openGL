## openGL学习笔记

### class1   
1.gluInit(&argc,argv) 对GLUT进行初始化，这个函数必须在其他的GLUT函数之前调用一次，格式比较死板，一般直接照抄   
2.glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE) 设置显示方式，其中GLUT_RGB表示使用RGB颜色，与之对应的还有GLUT_DOUBLE(使用双缓冲）——   
3.glutInitWindowPosition(int,int) 设置窗口的位置   
4.glutInitWindowSize(int,int) 设置窗口的大小   
5.glutCreateWindow(string) 根据前面的设置的信息创建窗口。参数将被作为窗口的标题 。注意：窗口被创建后，并不立即显示到屏幕上，需要调用glutMainLoop()函数   
6.glutDisplayFunc 我们设置了“当需要画图时，请调用myDisplay函数”。于是myDisplay函数就用来画图。观察myDisplay中的三个函数的调用，发现他们都以gl开头。这种以gl开头的函数都是openGL的标准寒素，下面对用到的杉树进行介绍   

  1.glClear,清除，GL_COLOR_BUFFER_BIT表示清除颜色，glCLear函数还可以清除其他的东西，但这里不做介绍   
  2.glRectf,画一个举行。四个参数分别表示了对于对角线上的两个点的横纵坐标   
  3.glFlush,保证前面的openGL命令立即执行，而不是让他们在缓冲区中等待。其作用跟fflush（stdout）类似   

### class2   
glVertex2d
glVertex2f
glVertex3f
glVertex3fv
等等。
数字表示参数的个数，2表示有两个参数，3表示三个，4表示四个（我知道有点罗嗦~）。
字母表示参数的类型，s表示16位整数（OpenGL中将这个类型定义为GLshort），
                   i表示32位整数（OpenGL中将这个类型定义为GLint和GLsizei），
                   f表示32位浮点数（OpenGL中将这个类型定义为GLfloat和GLclampf），
                   d表示64位浮点数（OpenGL中将这个类型定义为GLdouble和GLclampd）。
                   v表示传递的几个参数将使用指针的方式，见下面的例子。
这些函数除了参数的类型和个数不同以外，功能是相同的。例如，以下五个代码段的功能是等效的：
（一）glVertex2i(1, 3);
（二）glVertex2f(1.0f, 3.0f);
（三）glVertex3f(1.0f, 3.0f, 0.0f);
（四）glVertex4f(1.0f, 3.0f, 0.0f, 1.0f);
（五）GLfloat VertexArr3[] = {1.0f, 3.0f, 0.0f};
      glVertex3fv(VertexArr3);
      
画点：
```
glBegin(GL_POINTS);//点
     glVertex2f(0.0f, 0.0f);
     glVertex2f(0.5f, 0.0f);
glEnd();
```   
画线：
```
glBegin(GL_LINES);//点
     glVertex2f(0.0f, 0.0f);
     glVertex2f(0.5f, 0.0f);
glEnd();
```
