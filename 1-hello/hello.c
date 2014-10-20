/*
 * Capitulo 2
 * 'Hello World' de OpenGL
 * Aberto Jaspe Villanueva
 */

#include <GL/glut.h>

void reshape(int width, int height)
{
    //porción de ventana donde puede dibujar ogl
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //delimitar el volumen de vista y son, por este orden:
    // x_mínima, x_máxima, y_mínima, y_máxima, z_mínima, z_máxima
    glOrtho(-1,1,-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    // selecciona el color con el que se borra la pantalla
    glClear(GL_COLOR_BUFFER_BIT);
    //color con el que se va a dibujar 
    glColor3f(1,1,1);
    glLoadIdentity();
    glBegin(GL_TRIANGLES);
      glVertex3f(-1,-1,0); // lower left vertex
      glVertex3f(1,-1,0); // lower right vertex
      glVertex3f(0,1,1); // upper vertex
    glEnd();
    glFlush();
   // glutSwapBuffers(); se tiene que llamar siempre que es double buff
}

void init()
{
    glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// GLUT_DOUBLE para doble buff
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello OpenGL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
