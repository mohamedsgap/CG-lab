/*
Bresenham line-drawing procedure for |m| > 1.0.
BY:
Mohamed Abdel Nasser Mohamed Abdou
setion: 10

*/

#include <iostream>
#include <gl/glut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<Windows.h>
#include <vector>
using namespace std;

std::vector<int> xPoints;
int Ypar;

int lineBres(int, int, int, int);
//void setPixel(int x, int y);
void lineSegment(void);
void init(void);

//void main(){
int main(int argc, char** argv) {
	cout << "Hello, Bresenham :) Abdel Nasser is here ";
	// Bresenham line-drawing procedure for |m| > 1.0. 
	cout << "Bresenham line-drawing procedure for |m| > 1.0.";
	glutInit(&argc, argv); // Initialize GLUT."
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode."
	glutInitWindowPosition(99, 99); // Set top-left display-window position."
	glutInitWindowSize(333, 333); // Set display-window width and height."
	glutCreateWindow("Bresenham Line"); // Create display window."
	init(); // Execute initialization procedure."
	glutDisplayFunc(lineSegment); // Send graphics to display window."
	glutMainLoop(); // Display everything and wait."
}


void setPixel(int x, int y)
{
	glColor3f(0.0, 0.0, 0.0); //Set pixel to black  
	glBegin(GL_POINTS);
	glVertex2i(x, y); //Set pixel coordinates 
	glEnd();
	glFlush(); //Render pixel
}
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white."
	glMatrixMode(GL_PROJECTION); // Set projection parameters."
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment(void)
{

	int num = lineBres(0, 0, 100, 200);//call Bresenham to calculate the xpoints array
	Ypar -= 1;//minus Yinitial 

	glClear(GL_COLOR_BUFFER_BIT); // Clear display window."
	glColor3f(0.0, 0.4, 0.2); // 

	glBegin(GL_LINES);
	for (int i = 0; i<num;i++)// draw every point of X and Y
		glVertex2i(xPoints[i], Ypar++); // Specify line-segment geometry."


	glEnd();
	glFlush(); // Process all OpenGL routines as quickly as possible."
}

int lineBres(int X0, int Y0, int Xe, int Ye) {

	Ypar = Y0;
	int dxdx = 2 * (Xe - X0);
	int dy = (Ye - Y0);
	int pk = dxdx - dy;//calculate PK
	int pointsnum = Ye - Y0 + 1;
	xPoints.push_back(X0);

	while (Y0<Ye)
	{
		if (pk >= 0)
		{
			X0 += 1;
			xPoints.push_back(X0);
			pk = pk + dxdx - 2 * dy;
		}
		else
		{
			xPoints.push_back(X0);
			pk = pk + dxdx;
		}

		Y0++;
	}
	return pointsnum;
}