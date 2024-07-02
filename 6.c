//6. Develop a program to demonstrate Animation effects on simple objects
	
	
#include <glut.h>

// Define parameters for the object
float object_size = 0.2f;
float object_x = 0.0f;
float object_y = 0.0f;
float velocity_x = 0.005f;
float velocity_y = 0.005f;

// Function to initialize OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the background color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Set the viewing area
}

// Function to display the object
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw the object (a square)
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f); // Set the color to black
    glVertex2f(object_x - object_size, object_y - object_size); // Bottom-left vertex
    glVertex2f(object_x + object_size, object_y - object_size); // Bottom-right vertex
    glVertex2f(object_x + object_size, object_y + object_size); // Top-right vertex
    glVertex2f(object_x - object_size, object_y + object_size); // Top-left vertex
    glEnd();

    glFlush(); // Flush the buffer
}

// Function to update the position of the object
void update(int value) {
    // Move the object
    object_x += velocity_x;
    object_y += velocity_y;

    // Bounce the object off the edges of the window
    if (object_x + object_size >= 1.0f || object_x - object_size <= -1.0f) {
        velocity_x *= -1;
    }
    if (object_y + object_size >= 1.0f || object_y - object_size <= -1.0f) {
        velocity_y *= -1;
    }

    glutPostRedisplay(); // Request display callback
    glutTimerFunc(30, update, 0); // Schedule update again in 30 milliseconds
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Animation Effects");

    init(); // Initialize OpenGL
    glutDisplayFunc(display); // Register display callback
    glutTimerFunc(0, update, 0); // Schedule update

    glutMainLoop(); // Enter the event-processing loop

    return 0;
}
