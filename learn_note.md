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
