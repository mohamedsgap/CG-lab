
#include <GL/glut.h> // Include the GLUT header file  

void display(void) {
	

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Clear the background of our window to blue 
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer   
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations  

	glTranslatef(0.0f, 0.0f, -5.0f); // Push eveything 5 units back into the scene, otherwise we won't see the primitive  

	glutWireCube(2.0f); // Render the primitive  

	glFlush(); // Flush the OpenGL buffers to the window  
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window  
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed  
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)  
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes  
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly  

}



int main(int argc, char **argv) {
	glutInit(&argc, argv); // Initialize GLUT  
	glutInitDisplayMode(GLUT_SINGLE); // Set up a basic display buffer (only single buffered for now)  
	glutInitWindowSize(500, 500); // Set the width and height of the window  
	glutInitWindowPosition(100, 100); // Set the position of the window  
	glutCreateWindow("Your first OpenGL Window"); // Set the title for the window  

	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering  

	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping  

	glutMainLoop(); // Enter GLUT's main loop  
}