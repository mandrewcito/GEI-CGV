/*
 * Capitulo 2
 *  OpenGL
 *  Dibujando poligonos 
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
    glOrtho(-14,14,-14,14,-14,14);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    // selecciona el color con el que se borra la pantalla
    //glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
    //color con el que se va a dibujar 


	//GL_LINE_STRIP une los puntos con lineas 
	//GL_LINE_LOOP es igual a line strip pero cierra fin con inicio


	glutWireSphere(1.0f,10,10);



 //  glFlush ();




  glutSwapBuffers(); //se tiene que llamar siempre que es double buff
}

void init()
{
    glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB |GLUT_DEPTH );// GLUT_DOUBLE para doble buff
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello OpenGL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
