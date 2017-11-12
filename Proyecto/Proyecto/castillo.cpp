//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//

#include <Windows.h>;

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

bool cancion = true;
void sonido();
int i;
GLfloat g_lookupdown = 0.0f;

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	
CFiguras fig5;	
CFiguras fig6;

CCamera objCamera;

void InitGL(GLvoid)     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
														//glClearDepth(1.0f);									// Configuramos Depth Buffer
														//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
														//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
	objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1, 0);
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview
	
	glPushMatrix();
	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
		glColor3f(1.0,0.0,0.0);
		glTranslatef(10,3.0,-10.0);
		fig1.prisma(20,20,20,0);	//Edificio principal
		glPushMatrix();
			glTranslatef(19, -2.5, -2.0);
			glColor3f(0.0, 0.0, 1.0);
			fig2.prisma(15, 18, 16, 0);	//Edificio derecho
			//Cuadros de contorno en el edicio de la derecha
			for (i = 0; i < 18; i+=3)
			{
				glPushMatrix();
					glTranslatef(-7.5+i, 8.5, 7);
					glColor3f(0.0, 1.0, 1.0);
					fig1.prisma(2, 2, 2, 0);
				glPopMatrix();
			}
			for (i = 3; i < 15; i += 3)
			{
				glPushMatrix();
					glTranslatef(7.5, 8.5, 7.5-i);
					glColor3f(0.0, 1.0, 1.0);
					fig1.prisma(2, 2, 2, 0);
				glPopMatrix();
			}
			for (i = 0; i < 18; i += 3)
			{
				glPushMatrix();
					glTranslatef(7.5 - i, 8.5, -7);
					glColor3f(0.0, 1.0, 1.0);
					fig1.prisma(2, 2, 2, 0);
				glPopMatrix();
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-19, -2.5, -2.0);
			glColor3f(0.0, 1.0, 0.0);
			fig2.prisma(15, 18, 16, 0);	//Edificio Izquierdo
			//Cuadros de contorno en el edicio izquierdo
			for (i = 0; i < 18; i += 3)
			{
				glPushMatrix();
				glTranslatef(-7.5 + i, 8.5, 7);
				glColor3f(0.0, 1.0, 1.0);
				fig1.prisma(2, 2, 2, 0);
				glPopMatrix();
			}
			for (i = 3; i < 15; i += 3)
			{
				glPushMatrix();
				glTranslatef(-7.5, 8.5, 7.5 - i);
				glColor3f(0.0, 1.0, 1.0);
				fig1.prisma(2, 2, 2, 0);
				glPopMatrix();
			}
			for (i = 0; i < 18; i += 3)
			{
				glPushMatrix();
				glTranslatef(7.5 - i, 8.5, -7);
				glColor3f(0.0, 1.0, 1.0);
				fig1.prisma(2, 2, 2, 0);
				glPopMatrix();
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(14,-10,10);
			glColor3f(1.0, 1.0, 0.0);
			fig3.cilindro(4.0,18,50,0);	//Torre derecha
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-14, -10, 10);
			glColor3f(1.0, 1.0, 0.0);
			fig3.cilindro(4.0, 18, 50, 0);	//Torre izquierda
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 10, 0);
			glColor3f(1.0, 1.0, 0.0);
			fig4.cilindro(4.0, 8, 50, 0);	//Torre central
		glPopMatrix();
		//Cuadros de contorno en el edicio central
		for (i = 0; i < 20 ; i+=3)
		{
			glPushMatrix();
				glTranslatef(-9+i, 11.0, 9);
				glColor3f(1.0, 0.0, 1.0);
				fig1.prisma(2, 2, 2, 0);
			glPopMatrix();
		}
		for (i = 3; i < 20; i += 3)
		{
			glPushMatrix();
			glTranslatef(9, 11.0, 9-i);
			glColor3f(1.0, 0.0, 1.0);
			fig1.prisma(2, 2, 2, 0);
			glPopMatrix();
		}
		for (i = 3; i < 20; i += 3)
		{
			glPushMatrix();
			glTranslatef(9-i, 11.0, -9);
			glColor3f(1.0, 0.0, 1.0);
			fig1.prisma(2, 2, 2, 0);
			glPopMatrix();
		}
		for (i = 3; i < 18; i += 3)
		{
			glPushMatrix();
			glTranslatef(-9, 11.0, -9+i);
			glColor3f(1.0, 0.0, 1.0);
			fig1.prisma(2, 2, 2, 0);
			glPopMatrix();
		}

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;
	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;
	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;
	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;
	case 'c':
	case 'C':
		cancion = !cancion;
		break;
	case 27: exit(0);
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void sonido() {
	char soundfile[] = "miedo.wav";
	if (cancion == true)
	{
		PlaySound((LPCSTR)soundfile, NULL, SND_LOOP | SND_ASYNC);
	}
	else
	{
		PlaySound(NULL, NULL, NULL);
	}
}

int main(int argc, char** argv)   // Main Function
{
	sonido();
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	glutInitWindowSize(600, 600);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);
	glutMainLoop();          // 

	return 0;
}

