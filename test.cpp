#include<math.h>
#include<GL/glut.h>

void myinit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
	
void putpixel(float xc,float yc,float x,float y)
{ 
	glBegin(GL_POINTS); 
	glVertex3f(xc+x,yc+y,0); 
	glEnd();
}  
void drawEllipse(float xc,float yc,float a,float b) 
{ 
	float x,y; 
	float d1,d2; 
	x=0; 
	y=b; 
	d1=b*b+a*a*(-b+0.25); 
	putpixel(xc,yc,x,y); 
	putpixel(xc,yc,-x,-y); 
	putpixel(xc,yc,-x,y); 
	putpixel(xc,yc,x,-y); 
	while(b*b*(x+1)<a*a*(y-0.5)) 
	{ 
		if(d1<0) 
		{ 
			d1+=b*b*(2*x+3); 
			x++; 
		} 
		else 
		{ 
			d1+=b*b*(2*x+3)+a*a*(-2*y+2); 
			x++; 
			y--; 
		} 
		putpixel(xc,yc,x,y); 
		putpixel(xc,yc,-x,-y); 
		putpixel(xc,yc,-x,y); 
		putpixel(xc,yc,x,-y); 
	} 
	d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b; 
	while(y>0) 
	{ 
	if(d2<=0) 
	{ 
		d2+=b*b*(2*x+2)+a*a*(-2*y+3); 
		x++; 
		y--; 
	} 
	else 
	{ 
		d2+=a*a*(-2*y+3); 
		y--; 
	} 
		putpixel(xc,yc,x,y); 
		putpixel(xc,yc,-x,-y); 
		putpixel(xc,yc,-x,y); 
		putpixel(xc,yc,x,-y); 
	} 
} 

void display3() 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	glViewport(0, 0, 0.5, 500); 
	drawEllipse(0.25,0.25,0.06,0.04); 
	glFlush(); 
}

int main(int argc , char * argv[])
{
	glutInit(&argc,argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutDisplayFunc(display3);
	myinit();
	glutMainLoop();
	return 0;
}
