#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include <gl\glut.h>

void setPixel(int x, int y);
void lineBres(int x0, int y0, int xEnd, int yEnd);
void myDraw();
void init(void);
void changeColor();
void reShape(int, int);

int main(int argc, char** argv) {
	glutInit(&argc, argv); // Initialize GLUT."
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode."
	//glutInitWindowPosition(99, 99); // Set top-left display-window position."
	//glutInitWindowSize(333, 333); // Set display-window width and height."
	glutCreateWindow("Bresenham Line"); // Create display window."
	//init();
	//changeColor();
	/* Bresenham line-drawing procedure for |m| < 1.0. */
	glutDisplayFunc(myDraw);
	//glutReshapeFunc(reShape);
	glutMainLoop(); // Display everything and wait."

	//system("pause");
}


/* Bresenham line-drawing procedure for |m| < 1.0. */
void lineBres(int x0, int y0, int xEnd, int yEnd)
{
	int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
	int x, y;
	/* Determine which endpoint to use as start position. */
	if (x0 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	} else {
		x = x0;
		y = y0;
	}
	setPixel(x, y);
	while (x < xEnd) {
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyMinusDx;
		}
		setPixel(x, y);
	}
}

void setPixel(int x, int y)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	//glColor3b(1, 1, 0);
	glVertex2i(x, y); //Set pixel coordinates 
	glEnd();
	glFlush(); //Render pixel
}
void myDraw() {
	lineBres(20, 10, 30, 18);
}
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white."
	glMatrixMode(GL_PROJECTION); // Set projection parameters."
	gluOrtho2D(-10, 10, -10, 10);
}
void changeColor() {
	glClearColor(1.0, 1.0, 1.0,0.0);
}

void reShape(int w, int h) {
	// specify Viewport
	glViewport((GLint)0, (GLint)0, (GLsizei)w, (GLsizei)h);
	// specify projection (switching to projection matrix)
	glMatrixMode(GL_PROJECTION);
	// restting the current matrix
	glLoadIdentity();
	// to specify ortho 2D projection
	gluOrtho2D(-10, 10, -10, 10);
	// returning to the normal modern view
	glMatrixMode(GL_MODELVIEW);
}