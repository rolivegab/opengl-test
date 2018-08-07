#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

float theta = 0;

float randomf() {
	return ((float)rand())/RAND_MAX;
}

void inicializacao() {
	//cor de fundo eh cinza
	glClearColor(0.5, 0.5, 0.5, 0.0);
}

//funcao para desenhar um triangulo
void triangle_with_lines() {
	// glViewport(0, 0, 100, 100);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);

	glVertex2f(1, -1);
	glVertex2f(0, 1);
	
	glVertex2f(0, 1);
	glVertex2f(-1, -1);
	glEnd();
}

void triangle() {
	// glViewport(0, 0, 100, 100);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(0, 1);
	glEnd();
}

void funcaoDisplay() {
	//mensagem para verificar quando esta funcao eh chamada
	printf("display\n");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//limites das coordenadas de mundo
	gluOrtho2D(-4, 4, -4, 4);
	
	//limpa a tela com a cor de fundo
	glClear(GL_COLOR_BUFFER_BIT);

	//use a funcao triangulo, glTranslatef e glRotatef para desenhar varios
	//triangulos transladados e rotacionados
	// glRotatef(30, 0, 0, 1);
	triangle();

	glFlush();
}

void funcaoKeyboard(unsigned char key, int x, int y) {

	if(key == 'q') {
		exit(-1);
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) {

	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello world");
	glutKeyboardFunc(funcaoKeyboard);
	glutDisplayFunc(funcaoDisplay);
	inicializacao();

	glutMainLoop();

	return 0;
}

