

#include <GL/glut.h>
 #include <math.h> 
GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
int wired=0;
int angulos[3][4]={{0,0,0},{0,0,0}};
int i=0;

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

      glOrtho(-8,8, -8, 8, 1, 10);

    glMatrixMode(GL_MODELVIEW);
 
    ancho = width;
    alto = height;
}


void pierna(){

    /*muslo*/
    glPopMatrix();
    glTranslatef(1.0f, -2.5f, 0.0f);
    glPushMatrix();
    glScalef(1.0f,2.0f,1.0f);
    if (wired)
    glutWireSphere(0.65f,8,8);
    else
    glutSolidSphere(0.65f,8,8);

    /*rodilla*/
    glPopMatrix();
    glTranslatef(0.0f, -1.5f, 0.0f);
    glRotatef((GLfloat)angulos[i][0], 1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)angulos[i][1], 0.0f, 1.0f, 0.0f);
    glRotatef((GLfloat)angulos[i][2], 0.0f, 0.0f, 1.0f);
    glPushMatrix();
    if (wired)
        glutWireSphere(0.5f,8,8);
    else
    glutSolidSphere(0.5f,8,8);

    /*pierna*/
    glPopMatrix();
    glTranslatef(0.0f, -1.25f, 0.0f);
    glPushMatrix();
    glScalef(1.0f,2.0f,1.0f);
    if (wired)
    glutWireSphere(0.5f,8,8);
    else
    glutSolidSphere(0.5f,8,8);
    
    /*pie */
    glPopMatrix();
    glTranslatef(0.0f, -1.0f, -0.5f);
    glScalef(1.0f,0.5f,2.0f);
    if (wired)
    glutWireSphere(0.5f,8,8);
    else
    glutSolidSphere(0.5f,8,8);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*tronco*/
    glLoadIdentity();
    glTranslatef(0.0f, 2.0f, -5.0f);
    glPushMatrix();
    glPushMatrix();
    glScalef(3.0f,3.0f,1.0f);
    if(wired)
    glutWireCube(1.0f);
    else
    glutSolidCube(1.0f);
    i=0;
    pierna();
    glPopMatrix();
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glPushMatrix();
    i=1;pierna();
    glFlush();
    glutSwapBuffers();

}
void menuapp(int value)
{
    if(value==1) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(value==2) exit(0);
    if(value==3) wired=0;
    if(value==4) wired=1;
}
void init()
{
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    ancho = 400;
    alto = 400;
    /*menu*/
    int submenu1;
    submenu1=glutCreateMenu(menuapp);
    glutAddMenuEntry("Solido", 3);
    glutAddMenuEntry("Alambre", 4);
    glutCreateMenu(menuapp);
    glutAddMenuEntry("Borrar Pantalla",1);
     glutAddSubMenu("Apariencia", submenu1);
    glutAddMenuEntry("Salir",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
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
        angulos[0][0]=(angulos[0][0]+5)%360;
        break;
    case 'Q':
        angulos[0][0]=(angulos[0][0]-5)%360;
      break;
    case 'a':
          angulos[1][0]=(angulos[1][0]+5)%360;
	break;
    case 'A':
     angulos[1][0]=(angulos[1][0]-5)%360;
      break;
    //eje Y
    case 'w':
     angulos[0][1]=(angulos[0][1]+5)%360;
    break;
    case 'W':
    angulos[0][1]=(angulos[0][1]-5)%360;
      break;
    case 's':
            angulos[1][1]=(angulos[1][1]+5)%360;
      break;
    case 'S':
        angulos[1][1]=(angulos[1][1]-5)%360;
      break;
    case 'e':
        angulos[0][2]=(angulos[0][2]+5)%360;
    break;
    case 'E':
        angulos[0][2]=(angulos[0][2]-5)%360;
      break;
    case 'd':
        angulos[1][2]=(angulos[1][2]+5)%360;
      break;
    case 'D':
        angulos[1][2]=(angulos[1][2]-5)%360;
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


