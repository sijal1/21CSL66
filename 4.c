
#include <glut.h>
#include <math.h>

float tx = 0.0, ty = 0.0; 
float angle = 0.0;         
float scale = 1.0;         

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION);       
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);      
    //glMatrixMode(GL_MODELVIEW);        
    glLoadIdentity();                 

    
    glTranslatef(tx, ty, 0.0);        
    glRotatef(angle, 0.0, 0.0, 1.0);
    glScalef(scale, scale, 1.0);      

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);   
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);   
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();

    glutSwapBuffers();              
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'u': ty += 0.1; break;  
    case 'd': ty -= 0.1; break;   
    case 'l': tx -= 0.1; break;   
    case 'r': tx += 0.1; break;   
    case 'q': angle += 5.0; break;
    case 'e': angle -= 5.0; break;
    case 's': scale += 0.1; break;
    case 'S': scale -= 0.1; break;
    case 27: exit(0);              
    }
    glutPostRedisplay();               
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
