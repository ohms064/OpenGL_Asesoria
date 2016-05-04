#define _CRT_SECURE_NO_WARNINGS
#define DIRECTORY "Materiales/"
#include <windows.h>
//#include <wingdi.h>
#include <stdlib.h>
#include "glm/glm.h"
#include <math.h>
#include < GL/glut.h>
#include <stdio.h>

//#include "targa.h"
#define SPACE 32


GLfloat a2 = 0, desplazamiento=1, desplazamiento_A=-4.8, desplazamiento_azul = 0, 
desplazamiento_azul_A=-6, desplazamiento_amarillo = 0, desplazamiento_amarillo_A=-6;
GLuint tex1, tex2,tex3;

GLfloat posY = 0.0;
GLfloat posX = 0.0;
GLfloat movimiento_balaX = 0.0;
GLfloat movimiento_balaY = 0.0;
bool pushed_w, pushed_a, pushed_s, pushed_d, pushed_barra, pushed, baja_M;
bool draw=true;
//int numbalas = 5;

GLMmodel *model;
GLMmodel *model2;
GLint width, height;


GLint balaDisparada=0;
double baja_municion =1.0;

float posXBALA[100];
float posYBALA[100];
//float posX_B, posY_B;
float trayectoriaX[100];


void Init();
void Display();
void Reshape();
void keyboard(unsigned char key, int x, int y);


void Init()
{
	//glClearColor(0,0,0,0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);	
	
	glEnable(GL_LIGHT0);
      glEnable(GL_LIGHTING);

	model = glmReadOBJ(DIRECTORY"test.obj");
	model2 = glmReadOBJ(DIRECTORY"enemigo.obj");

		
	
	    tex1 = SOIL_load_OGL_texture(
			//EDIFICIOS
									DIRECTORY"imageA.png",

                                   SOIL_LOAD_AUTO,

                                   SOIL_CREATE_NEW_ID,

                                   SOIL_FLAG_POWER_OF_TWO

                                   );

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		tex2 = SOIL_load_OGL_texture(
			//NUBES
			DIRECTORY"nubes.png",

			SOIL_LOAD_AUTO,

			SOIL_CREATE_NEW_ID,

			SOIL_FLAG_POWER_OF_TWO


			);


		
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		tex3 = SOIL_load_OGL_texture(
			//edificios
			DIRECTORY"imageC.png",

			SOIL_LOAD_AUTO,

			SOIL_CREATE_NEW_ID,

			SOIL_FLAG_POWER_OF_TWO


			);



		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	
}


//CONTADOR BALA
void dispara(float posx, float posy, float postX)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	movimiento_balaX = posx + postX + 0.6+0.4;
	movimiento_balaY = posy + 0.4;
	glTranslatef(movimiento_balaX,movimiento_balaY, 0.0);
	
	
	if (movimiento_balaX >= 4.0 && movimiento_balaY >= -0.4 && movimiento_balaY <= 0.9 && balaDisparada == 5)
	{
		//if (balaDisparada == 5)
		//{
			//printf("\n DRAW");
		printf("\n mov x bala%f", movimiento_balaX);
			draw = false;
			//printf("%d\n", draw);
		//}
	}
	
	glutSolidCube(0.2);
	//glEnd();

}

void Display()
{
	
	
	desplazamiento_A += 0.0001;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_NOTEQUAL, 0);

	//CIUDAD

	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();

	desplazamiento += 0.0001;

	glTranslatef(desplazamiento, 0, 0);
	
	glBindTexture(GL_TEXTURE_2D,tex1);
	glEnd();

	glMatrixMode(GL_MODELVIEW);
	glClearColor(1, 1, 1, 1);
	glLoadIdentity();

	

	glBegin(GL_QUADS);
		

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-3.5f, -3.5f,-1);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.5f, -3.5f, -1);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(3.5f, 3.5f,-1);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3.5f, 3.5f, -1);

	glEnd();

   
	// EDIFIFIOS ATRAS

	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();



	glTranslatef(desplazamiento_A, 0, 0);

	glBindTexture(GL_TEXTURE_2D,tex2);
	glEnd();

	glMatrixMode(GL_MODELVIEW);
	

	glBegin(GL_QUADS);


	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-3.5f, -3.5f, -1);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.5f, -3.5f, -1);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(3.5f, 3.5f, -1);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3.5f, 3.5f, -1);

	glEnd();


	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();

	//edificios ALTOS

	glTranslatef(desplazamiento_A, 0, 0);

	glBindTexture(GL_TEXTURE_2D, tex3);
	glEnd();

	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_QUADS);


	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-3.5f, -3.5f, -1);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.5f, -3.5f, -1);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(3.5f, 3.5f, -1);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3.5f, 3.5f, -1);

	glEnd();



	if (pushed_w == true && posY <= 2.7)
	{

		posY += 0.1;
	}

	if (pushed_s == true && posY >= -3.5)
	{
		posY -= 0.1;

	}
	if (pushed_a == true && posX >= -2.5)
	{
		posX -= 0.1;
	}
	if (pushed_d == true && posX <= 2.5)
	{
		posX += 0.1;

	}

	// BALA

	posXBALA [balaDisparada]= posX;
	posYBALA [balaDisparada] = posY;
	trayectoriaX[balaDisparada] = 0 ;

		for (int i = 0; i < balaDisparada; i++)
		{
			trayectoriaX[i] += 0.1;
			
		    dispara(posXBALA[i], posYBALA[i], trayectoriaX[i]);
			
		}


	// MUNICION
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	glTranslatef(2,3.0, 0);
	
		glScalef(baja_municion, 0.3, 0.0);
		glutSolidCube(1.5);

	glPopMatrix();
	//glEnd();
	
	
	
    glTranslatef(posX, posY, 0.0);
	glScalef(0.4, 0.4, 0);


	glmDraw(model, GLM_TEXTURE | GLM_SMOOTH | GLM_MATERIAL);
	
	glLoadIdentity();


	glTranslatef(2.5, 0.0, 0.0);
	glScalef(0.4, 0.4, 0);
	
	//printf("PINTA NAVE\n", draw);
	//printf("%d\n", draw);
	if (draw == true)
	{
		glmDraw(model2, GLM_TEXTURE | GLM_SMOOTH | GLM_MATERIAL);
	}

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);

	
	glutSwapBuffers();
	glutPostRedisplay();

}





void Reshape(int w, int h)
{
	width = w;
	height = h;
	glViewport(0, 0, w, h);   //actualizar la ventana

	//______________AQUI_______________________
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.5, 3.5, -3.5, 3.5, -3.5, 3.5);
	//_________________________________________
}

void keyboard(unsigned char key, int x, int y){

	switch (key){
	case 'w':
		pushed_w = true;
		break;
	case 'd':
		pushed_d = true;
		break;
	case 's':
		pushed_s = true;
		break;
	case 'a':
		pushed_a = true;
		break;

	case SPACE:

		pushed = true;
		break;
	

	}
}

void keyboardUp(unsigned char key, int x, int y){

	switch (key){
	case 'w':
		pushed_w = false;
		break;
	case 'd':
		pushed_d = false;
		break;
	case 's':
		pushed_s = false;
		break;
	case 'a':
		pushed_a = false;
		break;

	case SPACE:

		pushed = false;
		balaDisparada = balaDisparada + 1;
		baja_municion = baja_municion - 0.1;

		break;

	}

}



int main (int artcp, char **argv)
{

  glutInit(&artcp, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(640,640);
  glutCreateWindow("Textures");		//crear una ventana
  //dispara(posX_B, posY_B);
  glutDisplayFunc(Display);					//callback principal
  glutReshapeFunc(Reshape);					//callback de reshape
  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
  //dispara(posX_B,posY_B);
  Init();									//Inicializaciones
  glutMainLoop();							//loop del programa
  return 0;

}