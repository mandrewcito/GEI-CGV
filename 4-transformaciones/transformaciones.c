

#include <GL/glut.h>
 
GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
GLfloat anguloEsferax = 0.0f;
GLfloat anguloEsferay = 0.0f;
GLfloat anguloEsferaz = 0.0f;
GLfloat esferax = 0.0f;
GLfloat esferay = 0.0f;
GLfloat esferaz = -5.0f;

GLint ancho=400;

GLint alto=400;
 
int hazPerspectiva = 0;
 
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(hazPerspectiva)
     gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 20.0f);
    else

      glOrtho(-4,4, -4, 4, 1, 10);

    glMatrixMode(GL_MODELVIEW);
 
    ancho = width;
    alto = height;
}
 
void drawCube(void)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);       //cara frontal
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);       //cara trasera
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);       //cara lateral izq
    glVertex3f(-1.0f,-1.0f, -1.0f);
    glVertex3f(-1.0f,-1.0f,  1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);       //cara lateral dcha
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glEnd(); 

    glColor3f(0.0f,      1.0f, 1.0f);
    glBegin(GL_QUADS);       //cara arriba
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
 
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);       //cara abajo
    glVertex3f( 1.0f,-1.0f, -1.0f);
    glVertex3f( 1.0f,-1.0f,  1.0f);
    glVertex3f(-1.0f,-1.0f,  1.0f);
    glVertex3f(-1.0f,-1.0f, -1.0f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*hombro*/
    glLoadIdentity();
    glRotatef(anguloEsferay, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloEsferax, 0.0f, 1.0f, 0.0f);
    glRotatef(anguloEsferaz, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.0f, -5.0f);
    glutWireSphere(0.5f, 8, 8);
    /*brazo*/
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(anguloEsferay, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloEsferax, 0.0f, 1.0f, 0.0f);
    glRotatef(anguloEsferaz, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -1.0f, -5.0f);
    glutSolidCube(1.0f);
    /*codo*/
    glLoadIdentity();
    glRotatef(anguloEsferay, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloEsferax, 0.0f, 1.0f, 0.0f);
    glRotatef(anguloEsferaz, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -2.0f, -5.0f);
    glutWireSphere(0.5f, 8, 8);
    /*antebrazo*/
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(anguloEsferay, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloEsferax, 0.0f, 1.0f, 0.0f);
    glRotatef(anguloEsferaz, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.0f, -2.0f, -5.0f);
    glutSolidCube(1.0f);
    /*mano*/
    glLoadIdentity();
    glRotatef(anguloEsferay, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloEsferax, 0.0f, 1.0f, 0.0f);
    glRotatef(anguloEsferaz, 0.0f, 0.0f, 1.0f);
    glTranslatef(2.0f, -2.0f, -5.0f);
    glutWireSphere(0.5f, 8, 8);
    glFlush();
    glLoadIdentity();
    glutSwapBuffers();

}

void init()
{
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    ancho = 400;
    alto = 400;
}
 

void idle()
{
    display();
}

 
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'p':
    case 'P':
      hazPerspectiva=1;
      reshape(ancho,alto);
      break;
 
    case 'o':
    case 'O':
      hazPerspectiva=0;
      reshape(ancho,alto);
      break;
    //EJE X
    case 'q':
    case 'Q':
    anguloEsferax+=1.0f;
      break;
    case 'a':
    case 'A':
    anguloEsferax-=1.0f;
      break;
    //eje Y
    case 'w':
    case 'W':
    anguloEsferay+=1.0f;
      break;
    case 'S':
    case 's':
    anguloEsferay-=1.0f;
      break;
    case 'e':
    case 'E':
    anguloEsferaz+=1.0f;
      break;
    case 'd':
    case 'D':
    anguloEsferaz-=1.0f;
      break;	
    case 27:   // escape
      exit(0);
      break;
    }
}
 
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(ancho, alto);
    glutCreateWindow("Cubo 1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}


