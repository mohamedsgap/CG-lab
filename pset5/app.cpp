#include<Windows.h>
#include<Gl/glut.h>

float nweWidth;
float angle = 0;
//float xPosition = -10;
float xPosition = 0;
int direction = 1; // right direction
void backgroundColor();
void myDraw();
void reSizeWindow(int, int);
void timer(int);
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(GetSystemMetrics(SM_CXSCREEN)
		, GetSystemMetrics(SM_CYSCREEN));
	glutCreateWindow("My game");
	// draw
	backgroundColor();
	glutDisplayFunc(myDraw);
	glutReshapeFunc(reSizeWindow);
	glutTimerFunc(0, timer, 0);
	////////////////
	glutMainLoop();
}

void backgroundColor() {
	glClearColor(0, 0, 0, 1);
}
void myDraw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	// my draw 
	//glShadeModel(GL_FLAT);
	/*
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex2f(xPosition,1);
	glColor3f(0,0,0);
	glVertex2f(xPosition,-1);
	glColor3f(1,1,0);
	glVertex2f(xPosition+2,-1);
	glColor3f(1,0,1);
	glVertex2f(xPosition+2,1);
	glEnd();


	glTranslatef(2,2,0);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex2f(xPosition,1);
	glColor3f(0,0,0);
	glVertex2f(xPosition,-1);
	glColor3f(1,1,0);
	glVertex2f(xPosition+2,-1);
	glColor3f(1,0,1);
	glVertex2f(xPosition+2,1);
	glEnd();

	glTranslatef(-2,2,0);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex2f(xPosition,1);
	glColor3f(0,0,0);
	glVertex2f(xPosition,-1);
	glColor3f(1,1,0);
	glVertex2f(xPosition+2,-1);
	glColor3f(1,0,1);
	glVertex2f(xPosition+2,1);
	glEnd();

	glTranslatef(-2,-2,0);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex2f(xPosition,1);
	glColor3f(0,0,0);
	glVertex2f(xPosition,-1);
	glColor3f(1,1,0);
	glVertex2f(xPosition+2,-1);
	glColor3f(1,0,1);
	glVertex2f(xPosition+2,1);
	glEnd();
	*/
	glTranslatef(xPosition, 0, 0);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(-1, 1);
	glColor3f(0, 0, 0);
	glVertex2f(-1, -1);
	glColor3f(1, 1, 0);
	glVertex2f(1, -1);
	glColor3f(1, 0, 1);
	glVertex2f(1, 1);
	glEnd();

	glTranslatef(2, 2, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(-1, 1);
	glColor3f(0, 0, 0);
	glVertex2f(-1, -1);
	glColor3f(1, 1, 0);
	glVertex2f(1, -1);
	glColor3f(1, 0, 1);
	glVertex2f(1, 1);
	glEnd();

	glTranslatef(-2, 2, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(-1, 1);
	glColor3f(0, 0, 0);
	glVertex2f(-1, -1);
	glColor3f(1, 1, 0);
	glVertex2f(1, -1);
	glColor3f(1, 0, 1);
	glVertex2f(1, 1);
	glEnd();

	glTranslatef(-2, -2, 0);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(-1, 1);
	glColor3f(0, 0, 0);
	glVertex2f(-1, -1);
	glColor3f(1, 1, 0);
	glVertex2f(1, -1);
	glColor3f(1, 0, 1);
	glVertex2f(1, 1);
	glEnd();

	//////////////
	glutSwapBuffers();
}
void reSizeWindow(int w, int h) {
	if (h == 0) h = 1;
	float aspect = (float)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w >= h) {
		gluOrtho2D(-10.0 * aspect, 10.0 * aspect, -10.0, 10.0);
		nweWidth = 10 * aspect - 2;
	}
	else {
		gluOrtho2D(-10.0, 10.0, -10.0 / aspect, 10.0 / aspect);
		nweWidth = 10 - 2;
	}
	glMatrixMode(GL_MODELVIEW);
}
void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	if (angle < 360)
		angle += 1;
	else
		angle = 0;
	switch (direction) {
	case 1:
		if (xPosition < nweWidth)
			xPosition += .3;
		else
			direction = -1;
		break;
	case -1:
		if (xPosition > -nweWidth)
			xPosition -= .3;
		else
			direction = 1;
		break;
	}

}
