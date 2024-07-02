// 4. Develop a program to demonstrate 2D transformation on basic objects

#include <glut.h>
#include <math.h>

float tx = 0.0, ty = 0.0;  // Translation factors
float angle = 0.0;          // Rotation angle
float scale = 1.0;          // Scaling factor

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set the background color to black
    glMatrixMode(GL_PROJECTION);       // Set the projection matrix
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // Set the orthographic projection
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);      // Clear the color buffer
    //glMatrixMode(GL_MODELVIEW);        // Set the model-view matrix
    glLoadIdentity();                  // Reset the model-view matrix

    // Apply transformations
    glTranslatef(tx, ty, 0.0);        // Apply translation
    glRotatef(angle, 0.0, 0.0, 1.0);// Apply rotation
    glScalef(scale, scale, 1.0);      // Apply scaling

    // Draw a square
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);   // Red color
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    // Draw a triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);   // Blue color
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();

    glutSwapBuffers();                 // Swap the front and back buffers
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'u': ty += 0.1; break;   // Move up
    case 'd': ty -= 0.1; break;   // Move down
    case 'l': tx -= 0.1; break;   // Move left
    case 'r': tx += 0.1; break;   // Move right
    case 'q': angle += 5.0; break;// Rotate counterclockwise
    case 'e': angle -= 5.0; break;// Rotate clockwise
    case 's': scale += 0.1; break;// Scale up
    case 'S': scale -= 0.1; break;// Scale down
    case 27: exit(0);              // Escape key to exit
    }
    glutPostRedisplay();               // Redraw the scene
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Transformations in OpenGL");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
