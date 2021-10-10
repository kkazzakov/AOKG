
#include <GraphicObject.h>
#include <stdio.h>
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <GL/freeglut.h>






// МАССИВ ОБЪЕКТОВ ДЛЯ ВЫВОДА
const int graphicObjectCount = 1;
GraphicObject graphicObjects[graphicObjectCount];

//функция вызывается каждые 20 мс
void Simulation(int value) {
    //устанавливаем признак того, что окно нуждается в перерисовке
    glutPostRedisplay(); 
    // эта же функция будет вызвана еще раз через 20 мс
    glutTimerFunc(20, Simulation, 0);
}

void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(25.0, (float)w / h, 0.2, 70.0);
}

void Display(void) {
    // отчищаем буфер цвета
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // включаем тест глубины
    glEnable(GL_DEPTH_TEST);
    // устанавливаем камеру
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(15, 15, 7.5, 0, 0, 0, 0, 1, 0);
    // выводим объекты
    graphicObjects[0].setColor(1, 1, 1);
    for (int i = 0; i < graphicObjectCount; i++) {
        graphicObjects[i].draw();
    };
    // смена переднего и заднего буферов
    glutSwapBuffers();
}

void KeyboardFunc(unsigned char key, int x, int y) {
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(600, 600);
    glutCreateWindow("laba1");
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutTimerFunc(20, Simulation, 0);
    glutKeyboardFunc(KeyboardFunc);
    
    glutMainLoop();
}
