//
//  main.cpp
//  Teste
//
//  Created by Andre Luiz Maciel Santana on 20/03/16.
//  Copyright © 2016 Andre Luiz Maciel Santana. All rights reserved.
//  Alunos: Gustavo Jasper e Anderson David
#include <iostream>
using namespace std;

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


#define HEIGHT 250
#define WIDTH 250
#define PI 3.1415926535

int escolha = 3;

float angle, raio_x, raio_y;
int i, circle_points = 500;

//Dois Pontos
void display() {

	glClear (GL_COLOR_BUFFER_BIT); /* Limpa todos os Pixels da Tela */

    switch (escolha)
    {
    case 1:

		glBegin(GL_LINES);
			glVertex2f (1 + 10, 240);
			glVertex2f (1 + 10, 1);
		glEnd();

        break;
    case 2:

		glBegin(GL_LINES);
			glVertex2f (240, 1 + 10);
			glVertex2f (1, 1 +  10);
		glEnd();

        break;
    case 3:

			/* Marca o inicio do desenho das primitivas, neste exemplo, uma linha */
		glBegin(GL_TRIANGLES);
		  //glBegin(GL_LINES);
			//Triangulo Abaixo
			glVertex2f (1, 10);
			glVertex2f (120, 10);
			glVertex2f (60, 60);

		glEnd();

        break;
	case 4:

		glBegin(GL_QUADS);
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
		 //glBegin(GL_LINE_LOOP);
		 glBegin(GL_POLYGON);
				   raio_x = 80.0;
				   raio_y = 100.0;
				   for(i = 0; i < circle_points; i++) {
					 angle = (2*PI*i)/circle_points;
					 glVertex2f(125.0+raio_x*cos(angle),125.0+raio_y*sin(angle));
					 }
		 glEnd();

        break;
    case 7:
        break;
    default:
        break;
    }

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
        cout << "[F6] displayCirculoo.\n";
        cout << "[F7] Finalizar o programa.\n\n";

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
                exit(1);
            break;
        default:
            system("cls");
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
