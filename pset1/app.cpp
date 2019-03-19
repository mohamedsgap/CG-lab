// to get screen size W & H
#include <Windows.h>
// For OpenGL API
#include <gl/glut.h>

// prototype for my display function to draw objects on screen
void myDisplay();
void reShape(int, int);
void changeColor();


// to initlize our glut
int main(int argc, char** argv) {


	// to initilize the display mode with
	// a sigle buffer and RGB color
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// to control the position of window
	glutInitWindowPosition(0, 0);
	// specify the window size in pixel
	glutInitWindowSize(640, 480);
	glutInitWindowSize(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	// for adding a title to window
	glutCreateWindow("Some Basic Primitives");
	changeColor();
	// using this callback function to call myDisplay 
	glutDisplayFunc(myDisplay);
	//using this callback to reshape window size
	glutReshapeFunc(reShape);
	// to create excuation loop 
	glutMainLoop();
}

void myDisplay() {
	// clearing the buffer 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// reset the current matrix 
	glLoadIdentity();
	// draw our objects (width  of line in the draw )
	glLineWidth(10.0);
	// specify type of primites you want to draw
	glBegin(GL_TRIANGLES);
	glColor3b(1, 1, 0);
	/*
	these functions take every 2 endpoints
	for every line of the triangle
	*/
	glVertex2f(0.0, 5.0);
	glVertex2f(4.0, -3.0);
	glVertex2f(-4.0, -3.0);
	glEnd();
	// for displaying on the screen
	glFlush();

}
void changeColor() {
	/*
	this function take the RGB parameters
	in 0's & 1's in float way and
	the last parameters for the opacity value;
	*/
	// changing the default color buffer (black)
	glClearColor(1.0,1.0,0.0, 1.0);
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