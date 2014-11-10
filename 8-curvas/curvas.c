#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define NP 4

enum { BEZIER, BSPLINE, NURBS };


GLfloat puntos_ctrl[NP][3] = {
        { -4.0, -4.0, 0.0}, { -3.0, 2.0, 0.0}, 
        {2.0, 4.0, 0.0}, {4.0, -3.0, 0.0}};

GLfloat puntos_ctrl_nuevos[NP][3];

GLfloat nudos[8] = {0.0,0.0,0.0,0.0,1.0,1.0,1.0,1.0};


int punto=0; // indice del punto que se esta controlando con el teclado
int detalle=20; // nº de puntos a interpolar a partir de los puntos de control

int tipo_curva=BEZIER;

static float id[4][4] = {
  {1.0, 0.0, 0.0, 0.0},
  {0.0, 1.0, 0.0, 0.0},
  {0.0, 0.0, 1.0, 0.0},
  {0.0, 0.0, 0.0, 1.0}
};

static float bspline[4][4] = {
  {1.0/6.0, 4.0/6.0, 1.0/6.0, 0.0},
  {0.0, 4.0/6.0, 2.0/6.0, 0.0},
  {0.0, 2.0/6.0, 4.0/6.0, 0.0},
  {0.0, 1.0/6.0, 4.0/6.0, 1.0/6.0}
};

void vmult(float m[4][4],float v[4][3],float r[4][3])
{
  int i,j,k;
  
  for(i=0;i<4;i++)
    for(j=0;j<3;j++)
      for(k=0, r[i][j]=0.0 ;k<4;k++)
        r[i][j]+= m[i][k] * v[k][j];
}

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void)
{
  int i;
  GLUnurbsObj *nurbs;
    
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glPointSize(1.0);


  if(tipo_curva==NURBS) {
    // Comienza la definición NURBS
    nurbs = gluNewNurbsRenderer();
    gluBeginCurve(nurbs);
      gluNurbsCurve(
        nurbs,
        8,                      // Número de nudos
        nudos,                   // Vector de nudos
        3,                       // Ancho de los puntos de control
        &puntos_ctrl[0][0],      // Puntero a la matriz de puntos de control
        4,                       // Orden de la curva
        GL_MAP1_VERTEX_3
      );
    gluEndCurve(nurbs);
  }
  else {
    // Multiplica los puntos de control por la matriz seleccionada
    if(tipo_curva==BEZIER) vmult(id,puntos_ctrl,puntos_ctrl_nuevos);
    else vmult(bspline,puntos_ctrl,puntos_ctrl_nuevos);

    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &puntos_ctrl_nuevos[0][0]);
    glEnable(GL_MAP1_VERTEX_3);

    glBegin(GL_LINE_STRIP);
      for (i = 0; i <= detalle; i++) 
         glEvalCoord1f((GLfloat) i/detalle);
    glEnd();
  }

  /* Esto pinta los puntos de control */
  glPointSize(5.0);
   
  glBegin(GL_POINTS);
    for (i = 0; i < NP; i++) {
      if(punto==i) glColor3f(1.0, 0.0, 0.0);
      else glColor3f(1.0, 1.0, 0.0);
      glVertex3fv(&puntos_ctrl[i][0]);
    }
  glEnd();

  glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho(-10.0, 10.0,
              -10.0*(GLfloat)h/(GLfloat)w, 
               10.0*(GLfloat)h/(GLfloat)w,
              -10.0, 10.0);
   else
      glOrtho(-10.0*(GLfloat)w/(GLfloat)h, 10.0*(GLfloat)w/(GLfloat)h,
              -10.0, 10.0,
              -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key,int x,int y)
{
  switch(key) {
    case 'q':
    case 'Q':
      puntos_ctrl[punto][1]+=1.0f;
      break;
    case 'a':
    case 'A':
      puntos_ctrl[punto][1]-=1.0f;
      break;
    case 'o':
    case 'O':
      puntos_ctrl[punto][0]-=1.0f;
      break;
    case 'p':
    case 'P':
      puntos_ctrl[punto][0]+=1.0f;
      break;
    case 'z':
    case 'Z':
      punto=(punto+1)%NP;
      break;
    case 'n':
    case 'N':
      if(detalle>2) detalle-=1;
      break;
    case 'm':
    case 'M':
      if(detalle<200) detalle+=1;
      break;
    case 'c':
    case 'C':
      if(tipo_curva==BEZIER) { tipo_curva=BSPLINE; printf("BSPLINE\n"); break; }
      if(tipo_curva==BSPLINE) { tipo_curva=NURBS; printf("NURBS\n"); break; }
      if(tipo_curva==NURBS) { tipo_curva=BEZIER; printf("BEZIER\n"); break; }
      break;
  }
  display();
}

int main(int argc, char** argv)
{
  printf("Utilice las siguientes teclas para controlar la curva:\n\n");
  printf("Q,A,O,P para mover el punto de control arr,aba,izq,der respectivamente\n");
  printf("Z       para seleccionar el punto de control a mover\n");
  printf("C       para seleccionar curva de Bezier, B-spline o NURBS\n");
  printf("N,M     para disminuir o aumentar el tamaño de la curva (solo Bezier o B-spline)\n");
  
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}


