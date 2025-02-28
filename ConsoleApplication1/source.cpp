#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <vector>
using namespace std;

int w = 1000, h = 1000; 
vector<pair<float, float>> clicks; 


void logClick(int x, int y)
{

    float glX = (float)(x - w / 2);
    float glY = (float)(h / 2 - y);

    
    clicks.push_back({ glX, glY });

    ofstream file("clicks.txt", ios::app);
    if (file.is_open())
    {
        file << "glVertex3f(" << glX << ", " << glY << ",1)\n";
        file.close();
    }
}

// Обработчик кликов мыши
void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        logClick(x, y); // Логируем координаты клика
        glutPostRedisplay(); // Перерисовываем окно
    }
}

// Функция для рисования дерева
void drawTree(float x, float y, float z)
{
    // Ствол дерева
    glColor3f(0.5f, 0.3f, 0.1f); // Коричневый цвет
    glBegin(GL_QUADS);
    glVertex3f(x - 4.5f, y - 8.0f, z);
    glVertex3f(x + 4.5f, y - 6.0f, z);
    glVertex3f(x + 7.5f, y, z);
    glVertex3f(x - 2.5f, y, z);
    glEnd();

    // Крона дерева
    glColor3f(0.0f, 0.6f, 0.0f); // Зеленый цвет
    glBegin(GL_TRIANGLES);
    glVertex3f(x - 4.0f, y, z);
    glVertex3f(x + 4.0f, y, z);
    glVertex3f(x, y + 6.0f, z);
    glEnd();
}

void DrawCircleFill()
{
    glColor3f(0, 0, 0);
    float angle = 2.0f * 3.141591f / 10;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 10; i++)
    {
        float dx = 3.5 * cosf(angle * i);
        float dy = 3.5 * sinf(angle * i);
        glVertex3f(-14 + dx, dy, 1);
    }
    glEnd();

    glColor3f(0, 0, 0);
    angle = 2.0f * 3.141591f / 10;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 10; i++)
    {
        float dx = 3.5 * cosf(angle * i);
        float dy = 3.5 * sinf(angle * i);
        glVertex3f(13. + dx, dy, 1);
    }
    glEnd();
}

void DrawSkyline()
{
    glColor3f(1, 0, 0); // Красный цвет для полигона
    glBegin(GL_POLYGON);
    glVertex2f(-21.35, 7.65);
    glVertex2f(-17.45, 7.65);
    glVertex2f(-15.7, 6.55);
    glVertex2f(-10.0, 8.95);
    glVertex2f(2.15, 9.2);
    glVertex2f(8.35, 5.95);
    glVertex2f(9.35, 5.85);
    glVertex2f(18.1, 4.5);
    glVertex2f(20.05, 3.55);
    glVertex2f(20.75, 2.15);
    glVertex2f(21.25, 1.55);
    glVertex2f(21.25, 0.3);
    glVertex2f(21.0, 0.0);
    glVertex2f(20.85, -0.95);
    glVertex2f(21.25, -1.55);
    glVertex2f(16.85, -1.95);
    glVertex2f(16.95, -0.25);
    glVertex2f(16.05, 1.8);
    glVertex2f(14.05, 3.15);
    glVertex2f(12.1, 3.0);
    glVertex2f(10.6, 2.3);
    glVertex2f(9.6, 1.0);
    glVertex2f(9.4, -1.35);
    glVertex2f(3.95, -1.25);
    glVertex2f(-6.2, -1.3);
    glVertex2f(-9.85, -1.5);
    glVertex2f(-10.05, 0.75);
    glVertex2f(-11.55, 2.85);
    glVertex2f(-13.65, 3.25);
    glVertex2f(-15.6, 2.65);
    glVertex2f(-16.85, 1.45);
    glVertex2f(-17.25, -0.75);
    glVertex2f(-21.4, -0.1);
    glVertex2f(-21.75, 0.7);
    glVertex2f(-22.2, 1.2);
    glVertex2f(-21.55, 3.5);
    glVertex2f(-21.45, 4.75);
    glVertex2f(-21.05, 5.85);
    glVertex2f(-21.55, 7.8);
    glVertex2f(-17.45, 7.65);
    glVertex2f(-15.65, 6.4);
    glEnd();

    glColor3f(1, 0.2, 0);
    glBegin(GL_POLYGON);
    glVertex3f(6.0, -0.9, 1);
    glVertex3f(6.15, 5.475, 1);
    glVertex3f(-6.525, 5.625, 1);
    glVertex3f(-6.525, -1.2, 1);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(8.91, 5.29, 1);
    glVertex3f(2.35, 8.61, 1);
    glVertex3f(-0.97, 8.61, 1);
    glVertex3f(6.73, 5.13, 1);
    glEnd();
}

void Draw()
{
    glPointSize(2);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);

    glEnable(GL_BLEND); // Включаем смешивание
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Устанавливаем параметры смешивания
    glLineWidth(2);

    DrawSkyline();
    DrawCircleFill();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glScalef(15.0, 15.0, 1.0);

    Draw();

    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    if (height == 0) height = 1;
    w = width;
    h = height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0.2, 0.3, 0.4, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void initGLUT(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLUT Template");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseClick);
}

int main(int argc, char** argv)
{
    initGLUT(argc, argv); // Инициализация GLUT
    glutMainLoop();       // Основной цикл GLUT
    return 0;
}