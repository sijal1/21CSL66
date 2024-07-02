// 5. Develop a program to demonstrate 3D transformation on 3D objects


#include <glut.h>
// Transformation parameters
float tx = 0.0, ty = 0.0, tz = 0.0;  // Translation factors
float angleX = 0.0, angleY = 0.0, angleZ = 0.0;  // Rotation angles
float scale = 1.0;  // Scaling factor

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set the background color to black
    glEnable(GL_DEPTH_TEST);           // Enable depth testing for 3D rendering
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear the color and depth buffers

    glMatrixMode(GL_MODELVIEW);  // Set the model-view matrix
    glLoadIdentity();  // Reset the model-view matrix

    // Apply transformations
    glTranslatef(tx, ty, tz);  // Apply translation
    glRotatef(angleX, 1.0, 0.0, 0.0);  // Rotate around the X axis
    glRotatef(angleY, 0.0, 1.0, 0.0);  // Rotate around the Y axis
    glRotatef(angleZ, 0.0, 0.0, 1.0);  // Rotate around the Z axis
    glScalef(scale, scale, scale);  // Apply scaling

    // Draw a cube
    glBegin(GL_QUADS);
    // Front face
    glColor3f(0.5, 0.0, 0.0);  // Red

    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    // Back face
    glColor3f(0.0, 1.0, 0.0);  // Green

    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);

    // Top face
    glColor3f(0.0, 0.0, 1.0);  // Blue

    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);

    // Bottom face
    glColor3f(1.0, 1.0, 0.0);  // Yellow

    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);

    // Right face
    glColor3f(1.0, 0.0, 1.0);  // Magenta

    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);

    // Left face
    glColor3f(0.0, 1.0, 1.0);  // Cyan

    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    glutSwapBuffers();  // Swap the front and back buffers
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'u': ty += 0.1f; break;  // Move up
    case 'd': ty -= 0.1f; break;  // Move down
    case 'l': tx -= 0.1f; break;  // Move left
    case 'r': tx += 0.1f; break;  // Move right
    case 'q': tz += 0.3f; break;  // Move forward
    case 'e': tz -= 0.3f; break;  // Move backward
    case 'x': angleX += 5.0f; break;  // Rotate around X axis
    case 'X': angleX -= 5.0f; break;  // Rotate around X axis
    case 'y': angleY += 5.0f; break;  // Rotate around Y axis
    case 'Y': angleY -= 5.0f; break;  // Rotate around Y axis
    case 'z': angleZ += 5.0f; break;  // Rotate around Z axis
    case 'Z': angleZ -= 5.0f; break;  // Rotate around Z axis
    case 's': scale += 0.1f; break;  // Scale up
    case 'S': scale -= 0.1f; break;  // Scale down
    case 27: exit(0);  // Escape key to exit
    }
    glutPostRedisplay();  // Redraw the scene
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Transformations in OpenGL");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
