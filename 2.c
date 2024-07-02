//Develop a program to demonstrate basic geometric operations on the 2D object
#include <glut.h>
#include<math.h>

float squareX = 0.0f;
float squareY = 0.0f;
float squareSize = 0.2f;
float rotationAngleDegrees = 45.0f;
float rotationAngleRadians = rotationAngleDegrees * (3.14/ 180.0f);

// Function to draw a square
void drawSquare(float x, float y, float size) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}

// Function to handle all rendering
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the original square
    glColor3f(1.0f, 0.0f, 0.0f);
    drawSquare(squareX, squareY, squareSize);

    // Draw the translated square
    glColor3f(0.0f, 1.0f, 0.0f);
    drawSquare(squareX + 0.5f, squareY, squareSize);

    // Draw the scaled square
    glColor3f(0.0f, 0.0f, 1.0f);
    drawSquare(squareX, squareY + 0.5f, squareSize * 2);


    // Calculate sine and cosine of the rotation angle
    float cosAngle = cos(rotationAngleRadians);
    float sinAngle = sin(rotationAngleRadians);


    // Calculate center of the square
    float centerX = squareX + squareSize / 2.0f;
    float centerY = squareY + squareSize / 2.0f;

    // Apply rotation matrix to each vertex
    float vertices[8] = {
        squareX, squareY,
        squareX + squareSize, squareY,
        squareX + squareSize, squareY + squareSize,
        squareX, squareY + squareSize
    };

    for (int i = 0; i < 8; i += 2) {
        float x = vertices[i] - centerX;
        float y = vertices[i + 1] - centerY;
        vertices[i] = x * cosAngle - y * sinAngle + centerX;
        vertices[i + 1] = x * sinAngle + y * cosAngle + centerY;
    }

    // Draw the rotated square
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    for (int i = 0; i < 8; i += 2) {
        glVertex2f(vertices[i] + 0.5, vertices[i + 1] + 0.4);
    }
    glEnd();

    glutSwapBuffers();
}

// Function to handle window resizing
void reshapeWindow(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    //glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Basic Geometric Operations");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reshapeWindow);
    glutMainLoop();
    return 0;
}
