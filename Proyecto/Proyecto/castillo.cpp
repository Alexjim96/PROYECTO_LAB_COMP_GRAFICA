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

float elev=0;
bool play=false,bandera=false;

CTexture textMesa;
CTexture textPata;
CTexture textWall;
CTexture textSilla;
CTexture textTecho;
CTexture textMarble;
CTexture textPiso;
CTexture textGlassWasser;
CTexture textBarrote;
CTexture textCuadro1;
CTexture textMarco;
CTexture textLibroCG;
CTexture textPB;
CTexture textPuerta;
CTexture textPuerta_princ;
CTexture textMarco_1;
CTexture textMarco_2;
CTexture textMarco_3;
CTexture textGrass;
CTexture textSky;
CTexture textLibrero;

CFiguras tablaMesa;
CFiguras pata1Mesa;
CFiguras pata2Mesa;
CFiguras pata3Mesa;
CFiguras pata4Mesa;
CFiguras asientoSilla;
CFiguras respaldoSilla1;
CFiguras respaldoSilla2;
CFiguras respaldoSilla3;
CFiguras respaldoSilla4;
CFiguras techoCasa;
CFiguras pisoCasa;

CFiguras cama;
CFiguras buro;
CFiguras cono;
CFiguras lampara;
CFiguras laptop;
CFiguras cubo;

//***ROSE****
CTexture textAlmohada;
CTexture textColcha;
CTexture textMaderaBuro;
CTexture textMaderaCama;
CTexture textLampara;
CTexture textLaptop;
CTexture textPantalla;
CTexture textTeclado;
CTexture textTouchPad;
CTexture textGW;

bool cancion = true;
void sonido();
int i;
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat g_lookupdown = 0.0f;

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	
CFiguras fig5;	
CFiguras fig6;

CTexture text1;
CTexture text2;
CTexture text3;
CTexture text4;
CTexture text5;
CTexture t_arbusto;
int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;

CModel dragon;


CCamera objCamera;

void mesa(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosMesa, GLfloat yPosMesa, GLfloat zPosMesa) {
	//mesa	
	//tabla
	glPushMatrix();
	glScalef(xMadera, yMadera, zMadera);
	glTranslatef(xPosMesa, yPosMesa, zPosMesa);
	glPushMatrix();
	glScalef(10, .5, 5);
	tablaMesa.prisma(1.0, 1.0, 1.0, textMarble.GLindex, textMarble.GLindex, textMarble.GLindex);
	//patas
	glPopMatrix();
	glPushMatrix();
	glTranslatef(4, -2.75, 2);
	glScalef(.5, 5, .5);
	pata1Mesa.prisma(1.0, 1.0, 1.0, textMarble.GLindex, textMarble.GLindex, textMarble.GLindex);
	glTranslatef(0, 0, -8);
	pata2Mesa.prisma(1.0, 1.0, 1.0, textMarble.GLindex, textMarble.GLindex, textMarble.GLindex);
	glTranslatef(-16, 0, 0);
	pata3Mesa.prisma(1.0, 1.0, 1.0, textMarble.GLindex, textMarble.GLindex, textMarble.GLindex);
	glTranslatef(0, 0, 8);
	pata4Mesa.prisma(1.0, 1.0, 1.0, textMarble.GLindex, textMarble.GLindex, textMarble.GLindex);
	glPopMatrix();
	glPopMatrix();

	return;
}

void Cama(GLfloat xMadera, GLfloat yMadera, GLfloat zMadera, GLfloat xPosCama, GLfloat yPosCama, GLfloat zPosCama)
{
	glPushMatrix();
	glScalef(xMadera, yMadera, zMadera); //posicion y tamaño 
	glTranslatef(xPosCama, yPosCama, zPosCama); //figura 

												//dibujamos la cabecera
	glPushMatrix();
	glTranslatef(9.0, 1.5, 0.5);
	glScalef(18.0, 3.0, 1.0);  //Tamaño de cabecera
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 6.0, 0.5);
	glScalef(1.0, 6.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.0, 6.0, 0.5);
	glScalef(4.0, 6.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 6.0, 0.5);
	glScalef(4.0, 6.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14.0, 6.0, 0.5);
	glScalef(4.0, 6.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(17.5, 6.0, 0.5);
	glScalef(1.0, 6.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 9.5, 0.5);
	glScalef(18.0, 1.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 5.0, 0.5);
	glScalef(1.0, 10.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();


	//dibujamos la base de la cama
	glPushMatrix();
	glTranslatef(0.5, 1.0, 11.0);
	glScalef(1.0, 2.0, 22.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(17.5, 1.0, 11.0);
	glScalef(1.0, 2.0, 22.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 1.0, 21.5);
	glScalef(18.0, 2.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();


	//colchon
	glPushMatrix();
	glTranslatef(9.0, 3.5, 11.0);
	glScalef(18.0, 3.0, 20.0);
	cama.prisma(1.0, 1.0, 1.0, textColcha.GLindex, textColcha.GLindex, textColcha.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 3.5, 11.0);
	glScalef(1.0, 3.0, 20.0);
	cama.prisma(1.0, 1.0, 1.0, textColcha.GLindex, textColcha.GLindex, textColcha.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(17.5, 3.5, 11.0);
	glScalef(1.0, 3.0, 20.0);
	cama.prisma(1.0, 1.0, 1.0, textColcha.GLindex, textColcha.GLindex, textColcha.GLindex);
	glPopMatrix();

	//almohada izquierda
	glPushMatrix();
	glTranslatef(4.0, 5.5, 3.0);
	glScalef(8.0, 1.0, 4.0);
	cama.prisma(1.0, 1.0, 1.0, textAlmohada.GLindex, textAlmohada.GLindex, textAlmohada.GLindex);
	glPopMatrix();

	//almohada derecha
	glPushMatrix();
	glTranslatef(14.0, 5.5, 3.0);
	glScalef(8.0, 1.0, 4.0);
	cama.prisma(1.0, 1.0, 1.0, textAlmohada.GLindex, textAlmohada.GLindex, textAlmohada.GLindex);
	glPopMatrix();


	//enfrente
	glPushMatrix();
	glTranslatef(9.0, 6.5, 21.5);
	glScalef(16.0, 1.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 2.5, 21.5);
	glScalef(16.0, 5.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 4.0, 21.5);
	glScalef(1.0, 8.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(17.5, 4.0, 21.5);
	glScalef(1.0, 8.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();


	//patas
	glPushMatrix();
	glTranslatef(0.5, -1.0, 21.5);
	glScalef(1.0, 2.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(17.5, -1.0, 21.5);
	glScalef(1.0, 2.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(17.5, -1.0, 0.5);
	glScalef(1.0, 2.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -1.0, 0.5);
	glScalef(1.0, 2.0, 1.0);
	cama.prisma(1.0, 1.0, 1.0, textMaderaCama.GLindex, textMaderaCama.GLindex, textMaderaCama.GLindex);
	glPopMatrix();
	glPopMatrix();
}


void InitGL(GLvoid)     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
														//glClearDepth(1.0f);									// Configuramos Depth Buffer
														//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
														//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	
	glEnable(GL_BLEND);

	text1.LoadTGA("pared-pv.tga");
	text1.BuildGLTexture();
	text1.ReleaseImage();
	text2.LoadTGA("pared.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();
	text3.LoadTGA("pared-p.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();
	text4.LoadTGA("cuarto-p.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();
	text5.LoadTGA("cuarto-p2.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();
	t_arbusto.LoadTGA("labe/arbusto.tga");
	t_arbusto.BuildGLTexture();
	t_arbusto.ReleaseImage();
	textMarble.LoadBMP("casa/marble_2.bmp");
	textMarble.BuildGLTexture();
	textMarble.ReleaseImage();
	textAlmohada.LoadBMP("casa/almohada.bmp");
	textAlmohada.BuildGLTexture();
	textAlmohada.ReleaseImage();

	textColcha.LoadBMP("casa/colcha.bmp");
	textColcha.BuildGLTexture();
	textColcha.ReleaseImage();
	textMaderaCama.LoadBMP("casa/maderaCama.bmp");
	textMaderaCama.BuildGLTexture();
	textMaderaCama.ReleaseImage();

	dragon._3dsLoad("Dragon.3ds");

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
	objCamera.Position_Camera(10, 2.5f, 20, 10, 2.5f, 10, 0, 1, 0);
}

void prisma(GLuint textura1)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void laberinto() {
	glPushMatrix();
		glPushMatrix();//1
			glScalef(0.5, 1.5, 4.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//2
			glTranslatef(-1.0, 0.0, 1.0);
			glScalef(0.5, 1.5, 2.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//3
			glTranslatef(-2.25, 0.0, 1.75);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 2.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//4
			glTranslatef(-3.25, 0.0, 1.75);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 2.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//5
			glTranslatef(-4.25, 0.0, 1.75);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 2.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//6
			glTranslatef(0.0, 0.0, -3.25);
			glScalef(0.5, 1.5, 2.5);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//7
			glTranslatef(-0.75, 0.0, -1.75);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 1.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//8
			glTranslatef(-1.0, 0.0, -2.25);
			glScalef(0.5, 1.5, 1.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//9
			glTranslatef(-2.5, 0.0, -1.25);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 1.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//10
			glTranslatef(-2.5, 0.0, 0.75);
			glScalef(0.5, 1.5, 1.5);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//11
			glTranslatef(-2.5, 0.0, -2.75);
			glScalef(0.5, 1.5, 2.5);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//12
			glTranslatef(-1.75, 0.0, -4.25);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 3.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//12-1
			glTranslatef(-4.75, 0.0, -4.25);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 3.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//13
			glTranslatef(-4.25, 0.0, -2.0);
			glScalef(1.0, 1.5, 2.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//13-1
			glTranslatef(-4.25, 0.0, 0.0);
			glScalef(1.0, 1.5, 2.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//14
			glTranslatef(-5.5, 0.0, 0.75);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 1.5);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//15
			glTranslatef(-6.5, 0.0, 0.12);
			glScalef(0.5, 1.5, 1.75);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//16
			glTranslatef(-6.25, 0.0, -0.85);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 1.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//17
			glTranslatef(-5.0, 0.0, -2.5);
			glScalef(0.5, 1.5, 1.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//18
			glTranslatef(-6.5, 0.0, -3.75);
			glScalef(0.5, 1.5, 1.5);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//19
			glTranslatef(-6.5, 0.0, 1.75);
			glRotatef(90, 0.0, 1.0, 0.0);
			glScalef(0.5, 1.5, 2.5);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//20
			glTranslatef(-8.0, 0.0, 0.0);
			glScalef(0.5, 1.5, 4.0);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
		glPushMatrix();//20-1
			glTranslatef(-8.0, 0.0, -3.25);
			glScalef(0.5, 1.5, 2.5);
			prisma(t_arbusto.GLindex);
		glPopMatrix();
	glPopMatrix();
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
		glDisable(GL_LIGHTING);
		fig6.skybox(1000, 1000, 1000, 0);
		glEnable(GL_LIGHTING);
		//glTranslatef(0,0,-90);
		glTranslatef(10,3.0,-10.0);
		glPushMatrix();
		glTranslatef(110,-4.8,75);
		glScalef(15,6,10);
		laberinto();
		glPopMatrix();
		glPushMatrix();
		fig1.prisma(20,20,20,text1.GLindex,text2.GLindex,text2.GLindex);	//Edificio principal
		glPopMatrix();
		glPushMatrix();
		glTranslatef(19.1, -2.5, -2.0);
			//glColor3f(0.0, 0.0, 1.0);
			glPushMatrix();
			glRotatef(90, 0, 1, 0);
			fig2.prisma(16, 15, 18, text3.GLindex, text2.GLindex, text2.GLindex);		//Edificio derecho
			glPopMatrix();	
			//Cuadros de contorno en el edicio de la derecha
			for (i = 0; i < 18; i+=3)
			{
				glPushMatrix();
					glTranslatef(-7.6+i, 9, 7);
					//glColor3f(0.0, 1.0, 1.0);
					fig1.prisma(2, 2, 2,text2.GLindex ,text2.GLindex, text2.GLindex);
				glPopMatrix();
			}
			for (i = 3; i < 15; i += 3)
			{
				glPushMatrix();
					glTranslatef(7.6, 9, 7.5-i);
					//glColor3f(0.0, 1.0, 1.0);
					fig1.prisma(2, 2, 2, text2.GLindex, text2.GLindex, text2.GLindex);
				glPopMatrix();
			}
			for (i = 0; i < 18; i += 3)
			{
				glPushMatrix();
					glTranslatef(7.6 - i, 9, -7);
					//glColor3f(0.0, 1.0, 1.0);
					fig1.prisma(2, 2, 2, text2.GLindex, text2.GLindex, text2.GLindex);
				glPopMatrix();
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-19.1, -2.5, -2.0);
			//glColor3f(0.0, 1.0, 0.0);
			glPushMatrix();
			glRotatef(-90,0,1,0);
			fig2.prisma(16, 15, 18, text3.GLindex, text2.GLindex, text2.GLindex);	//Edificio Izquierdo
			glPopMatrix();
			//Cuadros de contorno en el edicio izquierdo
			for (i = 0; i < 18; i += 3)
			{
				glPushMatrix();
				glTranslatef(-7.5 + i, 9, 7);
				//glColor3f(0.0, 1.0, 1.0);
				fig1.prisma(2, 2, 2, text2.GLindex, text2.GLindex, text2.GLindex);
				glPopMatrix();
			}
			for (i = 3; i < 15; i += 3)
			{
				glPushMatrix();
				glTranslatef(-7.5, 9, 7.5 - i);
				//glColor3f(0.0, 1.0, 1.0);
				fig1.prisma(2, 2, 2, text2.GLindex, text2.GLindex, text2.GLindex);
				glPopMatrix();
			}
			for (i = 0; i < 18; i += 3)
			{
				glPushMatrix();
				glTranslatef(7.5 - i, 9, -7);
				//glColor3f(0.0, 1.0, 1.0);
				fig1.prisma(2, 2, 2, text2.GLindex, text2.GLindex, text2.GLindex);
				glPopMatrix();
			}
		glPopMatrix();
		glPushMatrix();
			glTranslatef(14,-10,10);
			//glColor3f(1.0, 1.0, 0.0);
			fig3.cilindro(4.0,22,50, text2.GLindex);	//Torre derecha
			//Dragon
			glPushMatrix();
			glRotatef(45, 0, 1, 0);
			glTranslatef(-0.5, 27.05, -12);
			glScalef(.08, .08, .08);
			dragon.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-14, -10, 10);
			//glColor3f(1.0, 1.0, 0.0);
			fig3.cilindro(4.0, 22, 50, text2.GLindex);	//Torre izquierda
			//Dragon
			glPushMatrix();
			glRotatef(-45, 0, 1, 0);
			glTranslatef(-0.5, 27.05, -12);
			glScalef(.08, .08, .08);
			dragon.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 10, 0);
			//glColor3f(1.0, 1.0, 0.0);
			fig4.cilindro(4.0, 8, 50, text2.GLindex);	//Torre central
			//Dragon
			glPushMatrix();
			glTranslatef(-0.5, 13.7, -14);
			glScalef(.09, .09, .09);
			dragon.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
		glPopMatrix();
		//Cuadros de contorno en el edicio central
		for (i = 0; i < 20 ; i+=3)
		{
			glPushMatrix();
				glTranslatef(-9+i, 11.05, 9);
				//glColor3f(1.0, 0.0, 1.0);
				fig1.prisma(2, 2, 2, text2.GLindex, text2.GLindex, text2.GLindex);
			glPopMatrix();
		}
		for (i = 3; i < 20; i += 3)
		{
			glPushMatrix();
			glTranslatef(9, 11.05, 9-i);
			//glColor3f(1.0, 0.0, 1.0);
			fig1.prisma(2, 2, 2, text2.GLindex, text2.GLindex, text2.GLindex);
			glPopMatrix();
		}
		for (i = 3; i < 20; i += 3)
		{
			glPushMatrix();
			glTranslatef(9-i, 11.05, -9);
			//glColor3f(1.0, 0.0, 1.0);
			fig1.prisma(2, 2, 2, text2.GLindex, text2.GLindex, text2.GLindex);
			glPopMatrix();
		}
		for (i = 3; i < 18; i += 3)
		{
			glPushMatrix();
			glTranslatef(-9, 11.05, -9+i);
			//glColor3f(1.0, 0.0, 1.0);
			fig1.prisma(2, 2, 2, text2.GLindex, text2.GLindex, text2.GLindex);
			glPopMatrix();
		}
		//Cuarto 1
		glPushMatrix();
		glRotatef(-90, 0, 1, 0);
		glTranslatef(6.9, -4.8, -6.9);
		fig6.prisma(10,6,6,text3.GLindex, text2.GLindex, text2.GLindex);
			//mesa
			glPushMatrix();
				mesa(.2, .5, .2, 8, -4.8, -10);
			glPopMatrix();
			//cama
			glPushMatrix();
				Cama(0.05, 0.2, 0.1, -55, -23, -25);
			glPopMatrix();
			//Elevador
			glPushMatrix();
			glTranslatef(-6.03, elev, 0);
			fig6.prisma(10, 6, 6, text3.GLindex, text2.GLindex, text2.GLindex);
			glPopMatrix();
		glPopMatrix();
		//Cuarto 2
		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(-6.9, -4.8, -6.9);
		fig6.prisma(10, 6, 6, text3.GLindex, text2.GLindex, text2.GLindex);
			//mesa
			glPushMatrix();
				mesa(.2, .5, .2, 8, -4.8, -10);
			glPopMatrix();
			//cama
			glPushMatrix();
				Cama(0.05, 0.2, 0.1, -55, -23, -25);
			glPopMatrix();
			//Cuarto 3
			glPushMatrix();
				glTranslatef(6.03, 0, 0);
				fig6.prisma(10, 6, 6, text3.GLindex, text2.GLindex, text2.GLindex);
				//mesa
				glPushMatrix();
					mesa(.2, .5, .2, 8, -4.8, -10);
				glPopMatrix();
				//cama
				glPushMatrix();
					Cama(0.05, 0.2, 0.1, -55, -23, -25);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
		//Cuarto 4
		glPushMatrix();
		glTranslatef(5, -4.8, -5.9);
		fig6.prisma(10, 9.8, 7.4, text5.GLindex, text2.GLindex, text2.GLindex);
			//mesa
			glPushMatrix();
				mesa(.4, .5, .4, 5, -4.8, -6);
			glPopMatrix();
			//cama
			glPushMatrix();
				Cama(0.15, 0.2, 0.15, -30, -23, -20);
			glPopMatrix();
		glPopMatrix();
		//Cuarto 5
		glPushMatrix();
			glTranslatef(-5, -4.8, -5.9);
			fig6.prisma(10, 9.8, 7.4, text4.GLindex, text2.GLindex, text2.GLindex);
			//mesa
			glPushMatrix();
				mesa(.4, .5, .4, 5, -4.8, -6);
			glPopMatrix();
			//cama
			glPushMatrix();
				Cama(0.15, 0.2, 0.15, -30, -23, -20);
			glPopMatrix();
		glPopMatrix();
		//Cuarto 1 superior
		glPushMatrix();
			glRotatef(-90, 0, 1, 0);
			glTranslatef(6.9, 5, -7);
			fig6.prisma(10, 6, 6, text3.GLindex, text2.GLindex, text2.GLindex);
			//mesa
			glPushMatrix();
				mesa(.2, .5, .2, 8, -4.7, -10);
			glPopMatrix();
			//cama
			glPushMatrix();
				Cama(0.05, 0.2, 0.1, -55, -22.7, -25);
			glPopMatrix();
		glPopMatrix();
		//Cuarto 2 superior
		glPushMatrix();
			glRotatef(90, 0, 1, 0);
			glTranslatef(-6.9, 5, -6.9);
			fig6.prisma(10, 6, 6, text3.GLindex, text2.GLindex, text2.GLindex);
			//mesa
			glPushMatrix();
				mesa(.2, .5, .2, 8, -4.7, -10);
			glPopMatrix();
			//cama
			glPushMatrix();
				Cama(0.05, 0.2, 0.1, -55, -22.7, -25);
			glPopMatrix();
			//Cuarto 3 superior
			glPushMatrix();
				glTranslatef(6.03, 0, 0);
				fig6.prisma(10, 6, 6, text3.GLindex, text2.GLindex, text2.GLindex);
				//mesa
				glPushMatrix();
					mesa(.2, .5, .2, 8, -4.7, -10);
				glPopMatrix();
				//cama
				glPushMatrix();
					Cama(0.05, 0.2, 0.1, -55, -22.7, -25);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
		//Cuarto 4 superior
		glPushMatrix();
			glTranslatef(5, 5, -5.9);
			fig6.prisma(10, 9.8, 7.4, text5.GLindex, text2.GLindex, text2.GLindex);
			//mesa
			glPushMatrix();
				mesa(.4, .5, .4, 5, -4.7, -6);
			glPopMatrix();
			//cama
			glPushMatrix();
				Cama(0.15, 0.2, 0.15, -30, -22.7, -20);
			glPopMatrix();
		glPopMatrix();
		//Cuarto 5 superior
		glPushMatrix();
			glTranslatef(-5, 5, -5.9);
			fig6.prisma(10, 9.8, 7.4, text4.GLindex, text2.GLindex, text2.GLindex);
			//mesa
			glPushMatrix();
				mesa(.4, .5, .4, 5, -4.7, -6);
			glPopMatrix();
			//cama
			glPushMatrix();
				Cama(0.15, 0.2, 0.15, -30, -22.7, -20);
			glPopMatrix();
		glPopMatrix();
		//Piso 
		glPushMatrix();
			glTranslatef(0,0,3.95);
			fig5.prisma(0.5,7.7,12,text2.GLindex, text2.GLindex, text2.GLindex);
		glPopMatrix();
		glPopMatrix();
	glutSwapBuffers();
}

void animacion()
{
	if (play)
	{
		if (elev <= 9.8 && bandera == false) {
			if (elev > 9.6) {
				bandera = true;
				play = false;
			}
			elev += 0.2;
		}
		else {
			elev -= 0.2;
			if (elev<=0) {
				play = false;
				bandera = false;
			}
		}
	}


	glutPostRedisplay();
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
		objCamera.Move_Camera((CAMERASPEED + 0.2)/3);
		break;
	case 's':
	case 'S':
		objCamera.Move_Camera(-((CAMERASPEED + 0.2)/3));
		break;
	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-((CAMERASPEED + 0.4)/3));
		break;
	case 'd':
	case 'D':
		objCamera.Strafe_Camera((CAMERASPEED + 0.4)/3);
		break;
	case 'c':
	case 'C':
		cancion = !cancion;
		break;
	case 'p':
	case 'P':
		play= !play;
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
	//sonido();
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
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}

