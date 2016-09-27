//
//  main.cpp
//  Teste
//
//  Created by Andre Luiz Maciel Santana on 20/03/16.
//  Copyright © 2016 Andre Luiz Maciel Santana. All rights reserved.
//  Alunos: Gustavo Jasper e Anderson David
#include <iostream>
using namespace std;

#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


#define HEIGHT 250
#define WIDTH 250
#define PI 3.1415926535

int escolha = 10;

float angle, raio_x, raio_y;
int i, circle_points = 500;

long unsigned int startDrawningTime, deltaTime;

//Dois Pontos
void display() {

	glClear (GL_COLOR_BUFFER_BIT); /* Limpa todos os Pixels da Tela */

	startDrawningTime = glutGet(GLUT_ELAPSED_TIME);

    switch (escolha)
    {
    case 1:
		glBegin(GL_LINES);
		glColor3f(255,255,255);
			glVertex2f (1 + 10, 240);
			glVertex2f (1 + 10, 1);
		glEnd();
        break;
    case 2:
		glBegin(GL_LINES);
		glColor3f(255,255,255);
			glVertex2f (240, 1 + 10);
			glVertex2f (1, 1 +  10);
		glEnd();
        break;
    case 3:
			/* Marca o inicio do desenho das primitivas, neste exemplo, uma linha */
		glBegin(GL_TRIANGLES);
		glColor3f(255,255,255);
			//Triangulo Abaixo
			glVertex2f (1, 10);
			glVertex2f (120, 10);
			glVertex2f (60, 60);
		glEnd();
        break;
	case 4:
		glBegin(GL_QUADS);
		glColor3f(255,255,255);
			//Retângulo Abaixo
			glVertex2f (10, 10);
			glVertex2f (10, 100);
			glVertex2f (40, 100);
			glVertex2f (40, 10);
        glEnd();
        break;
	case 5:
		 glBegin(GL_QUADS);
			//Retângulo Abaixo
			glVertex2f (10, 10);
			glVertex2f (10, 100);
			glVertex2f (100, 100);
			glVertex2f (100, 10);
        glEnd();
        break;
	case 6:
		 // Desenha um círculo (elipse) preenchido com a cor corrente
		 glBegin(GL_POLYGON);
		 glColor3f(255,255,255);
				   raio_x = 80.0;
				   raio_y = 100.0;
				   for(i = 0; i < circle_points; i++) {
					 angle = (7*PI*i)/circle_points;
					 glVertex2f(125.0+raio_x*cos(angle),125.0+raio_y*sin(angle));
					 }
		 glEnd();
        break;
    case 7:
		 // Desenha um cilindro
		 glBegin(GL_POLYGON_BIT);
		 glColor3f(255,255,255);
				   raio_x = 50.0;
				   raio_y = 25.0;
				   for(i = 0; i < circle_points; i++) {
					 angle = (12*PI*i)/circle_points;
					 glVertex2f(100.0+raio_x*cos(angle),175.0+raio_y*sin(angle));
					 }
		 glEnd();
		 glBegin(GL_POLYGON_BIT);
		 glColor3f(255,255,255);
				   raio_x = 50.0;
				   raio_y = 25.0;
				   for(i = 0; i < circle_points; i++) {
					 angle = (12*PI*i)/circle_points;
					 glVertex2f(100.0+raio_x*cos(angle),75.0+raio_y*sin(angle));
					 }
		 glEnd();
		 glBegin(GL_QUADS);
		 glColor3f(255,255,255);
		 glVertex2f(50,75);
		 glVertex2f(51.5,75);
		 glVertex2f(51.5,175);
		 glVertex2f(50,175);
		 glEnd();
		 glBegin(GL_QUADS);
		 glColor3f(255,255,255);
		 glVertex2f(149,75);
		 glVertex2f(150.5,75);
		 glVertex2f(150.5,175);
		 glVertex2f(149,175);
		 glEnd();
        break;
    case 8:
		 glBegin(GL_LINE_LOOP);
		 glColor3f(255,255,255);
            //Poligono
			glVertex2f (10, 30);
			glVertex2f (10, 70);
			glVertex2f (40, 90);
			glVertex2f (70, 70);
            glVertex2f (70, 30);
            glVertex2f (40, 10);
            glVertex2f (10, 30);
         glEnd();
        break;
	case 9:
	    //Bandeira do Brasil
         glBegin(GL_QUADS);
            glColor3f(0,255,0);
            glVertex2f(10,20);
            glVertex2f(10,180);
            glVertex2f(240,180);
            glVertex2f(240,20);
         glEnd();
         glBegin(GL_QUADS);
            glColor3f(255,255,0);
            glVertex2f(30,100);
            glVertex2f(125,160);
            glVertex2f(210,100);
            glVertex2f(125,40);
          glEnd();
        glBegin(GL_POLYGON);
            glColor3f(0,0,255);
            raio_x = 45.0;
            raio_y = 45.0;
               for(i = 0; i < circle_points; i++) {
                 angle = (2*PI*i)/circle_points;
                 glVertex2f(122.5+raio_x*cos(angle),100.0+raio_y*sin(angle));
                 }
            glEnd();
        break;
    case 10:
        break;
    default:
        break;
    }

	FILE * fp;
	fp = fopen ("timelog.txt", "a+");

	deltaTime = glutGet(GLUT_ELAPSED_TIME) - startDrawningTime;
	fprintf(fp, "%d %d \n", deltaTime, escolha);

   fclose(fp);

    //cout << deltaTime;
    glFlush (); /*Libera o Buffer Principal */
}

void menuFx()
{
        cout << "Escolha uma opcao a baixo:\n\n";
        cout << "[F1] displayLinhaVertical.\n";
        cout << "[F2] displayLinhaHorizontal.\n";
        cout << "[F3] displayTriangulo.\n";
        cout << "[F4] displayRetangulo.\n";
		cout << "[F5] displayQuadrado.\n";
        cout << "[F6] displayCirculo.\n";
        cout << "[F7] displayCilindro.\n";
        cout << "[F8] displayPoligono.\n";
        cout << "[F9] displayBandeira.\n";
        cout << "[F10] Finalizar o programa.\n\n";


}

int window;
int myMenu;
int mySubMenu;

void menu(int op){
    switch (op) {
		case 1:
            escolha = 1;
            break;
		case 2:
            escolha = 2;
            break;
		case 3:
            escolha = 3;
            break;
		case 4:
            escolha = 4;
            break;
		case 5:
            escolha = 5;
            break;
		case 6:
            escolha = 6;
            break;
        case 7:
            escolha = 7;
            break;
        case 8:
            escolha = 8;
            break;
        case 9:
            escolha = 9;
            break;
        case 10:
            glutDestroyWindow(window);
            exit(0);
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

void createMenu(){
    mySubMenu = glutCreateMenu(menu);

    glutAddMenuEntry("Opcao 1", 1);
    glutAddMenuEntry("Opcao 2", 2);
    glutAddMenuEntry("Opcao 3", 3);
    glutAddMenuEntry("Opcao 4", 4);
	glutAddMenuEntry("Opcao 5", 5);
    glutAddMenuEntry("Opcao 6", 6);
    glutAddMenuEntry("Opcao 7", 7);
    glutAddMenuEntry("Opcao 8", 8);
    glutAddMenuEntry("Opcao 9", 9);
    glutAddMenuEntry("Sair", 0);

    myMenu = glutCreateMenu(menu);
    glutAddSubMenu("Menu 1", mySubMenu);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void specialKey(GLint key, GLint x, GLint y){

            glutPostRedisplay();

    switch(key){
        case GLUT_KEY_F1:
                escolha = 1;
            break;
        case GLUT_KEY_F2:
                escolha = 2;
            break;
        case GLUT_KEY_F3:
                escolha = 3;
            break;
        case GLUT_KEY_F4:
                escolha = 4;
            break;
        case GLUT_KEY_F5:
                escolha = 5;
            break;
        case GLUT_KEY_F6:
                escolha = 6;
            break;
        case GLUT_KEY_F7:
                escolha = 7;
            break;
        case GLUT_KEY_F8:
                escolha = 8;
            break;
        case GLUT_KEY_F9:
                escolha = 9;
            break;
        case GLUT_KEY_F10:
                exit(1);
            break;
        default:
            break;

    }
}

void init(){
    glClearColor (0.0, 0.0, 0.0, 0.0);  /* Define qual ser a cor do Fundo ao Chamar o GLCLear */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}

int main(int argc, char** argv) {
    int mode = GLUT_SINGLE | GLUT_RGB;
    glutInit(&argc, argv);                          //Inicializa a biblioteca GLUT
    glutInitDisplayMode(mode);    //
    glutCreateWindow("Exemplo Base");               // Cria uma janela com titulo
    glutInitWindowSize(250, 250);              // Define largura e altura da janela
    glutInitWindowPosition(0, 0);
    init();

    menuFx();
    createMenu();

    glutDisplayFunc(display);                       // Registra o listener que exibir imagens
	glutSpecialFunc(specialKey);

    glutMainLoop();                                 // Inicia a mquina de estados principal do OpenGL
    return 0;
}
