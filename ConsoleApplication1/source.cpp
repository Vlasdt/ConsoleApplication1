#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <vector>
#include <cmath>
using namespace std;

int w = 1000, h = 1000;
float x_position = 0.0f;
float x_velocity = 0.1f;
float x_acceleration = 0.005f;

float wheel_angle = 0.0f;
float wheel_velocity = 0.005f;
float wheel_acceleration = 0.001f;
float smoke_speed = 1;
float startime = 0;
float lampcol = 0;


void update(int value) {
    if (startime > 3) {
        lampcol = 1;
        x_velocity += x_acceleration;
        x_position += x_velocity;

        wheel_velocity += wheel_acceleration;
        wheel_angle -= wheel_velocity;
    }
    else
    {
        startime += 0.05;
    }


    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void logClick(int x, int y)
{
    float glX = (float)(x - w);
    float glY = (float)(h / -y);

    ofstream file("clicks.txt", ios::app);
    if (file.is_open())
    {
        file << "glVertex3f(" << glX / 10 << ", " << glY << ",1);\n";
        file.close();
    }
}

void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        logClick(x, y);
        glutPostRedisplay();
    }
}

void drawwheels(float angle, float x) {
    glColor3f(0, 0, 0);
    float angle2 = 2.0f * 3.141592f / 10;

    // Отрисовка первого колеса
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 10; i++) {
        float dx = 3.5 * cosf(angle2 * i);
        float dy = 3.5 * sinf(angle2 * i);
        glVertex3f(x - 14 + dx, dy, 1);
    }
    glEnd();

    // Отрисовка второго колеса
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 10; i++) {
        float dx = 3.5 * cosf(angle2 * i);
        float dy = 3.5 * sinf(angle2 * i);
        glVertex3f(x + 13 + dx, dy, 1);
    }
    glEnd();

    // Центральные круги для эффекта диска
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 10; i++) {
        float dx = 3 * cosf(angle2 * i);
        float dy = 3 * sinf(angle2 * i);
        glVertex3f(x + 13 + dx, dy, 1);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 10; i++) {
        float dx = 3 * cosf(angle2 * i);
        float dy = 3 * sinf(angle2 * i);
        glVertex3f(x - 14 + dx, dy, 1);
    }
    glEnd();

    // Чёрные линии-спицы (чтобы они поворачивались правильно)
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    for (int i = 0; i < 3; i++) {
        float a = angle + (i * 3.141592f / 3); // равномерное распределение по колесу
        float dx = 3 * cosf(a);
        float dy = 3 * sinf(a);

        // Линии для переднего колеса
        glVertex2f(x + 13 + dx, dy);
        glVertex2f(x + 13 - dx, -dy);

        // Линии для заднего колеса
        glVertex2f(x - 14 + dx, dy);
        glVertex2f(x - 14 - dx, -dy);
    }
    glEnd();
}

void drawlamp(float r, float g, float b, float x) {
    glColor3f(r, g, b);
    float angle = 2.0f * 3.141591f / 10;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 10; i++)
    {
        float dx = 2 * cosf(angle * i);
        float dy = 1 * sinf(angle * i);
        glVertex3f(x + 18 + dx, 4 + dy, 1);
    }
    glEnd();
}

void DrawSkyline(float x)
{
    glColor3f(x + 1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x + -21.35, 7.65);
    glVertex2f(x + -17.45, 7.65);
    glVertex2f(x + -15.7, 6.55);
    glVertex2f(x + -10.0, 8.95);
    glVertex2f(x + 2.15, 9.2);
    glVertex2f(x + 8.35, 5.95);
    glVertex2f(x + 9.35, 5.85);
    glVertex2f(x + 18.1, 4.5);
    glVertex2f(x + 20.05, 3.55);
    glVertex2f(x + 20.75, 2.15);
    glVertex2f(x + 21.25, 1.55);
    glVertex2f(x + 21.25, 0.3);
    glVertex2f(x + 21.0, 0.0);
    glVertex2f(x + 20.85, -0.95);
    glVertex2f(x + 21.25, -1.55);
    glVertex2f(x + 16.85, -1.95);
    glVertex2f(x + 16.95, -0.25);
    glVertex2f(x + 16.05, 1.8);
    glVertex2f(x + 14.05, 3.15);
    glVertex2f(x + 12.1, 3.0);
    glVertex2f(x + 10.6, 2.3);
    glVertex2f(x + 9.6, 1.0);
    glVertex2f(x + 9.4, -1.35);
    glVertex2f(x + 3.95, -1.25);
    glVertex2f(x + -6.2, -1.3);
    glVertex2f(x + -9.85, -1.5);
    glVertex2f(x + -10.05, 0.75);
    glVertex2f(x + -11.55, 2.85);
    glVertex2f(x + -13.65, 3.25);
    glVertex2f(x + -15.6, 2.65);
    glVertex2f(x + -16.85, 1.45);
    glVertex2f(x + -17.25, -0.75);
    glVertex2f(x + -21.4, -0.1);
    glVertex2f(x + -21.75, 0.7);
    glVertex2f(x + -22.2, 1.2);
    glVertex2f(x + -21.55, 3.5);
    glVertex2f(x + -21.45, 4.75);
    glVertex2f(x + -21.05, 5.85);
    glVertex2f(x + -21.55, 7.8);
    glVertex2f(x + -17.45, 7.65);
    glVertex2f(x + -15.65, 6.4);
    glEnd();

    glColor3f(1, 0.2, 0);
    glBegin(GL_POLYGON);
    glVertex3f(x + .0, -0.9, 1);
    glVertex3f(x + 6.15, 5.475, 1);
    glVertex3f(x + -6.525, 5.625, 1);
    glVertex3f(x + -6.525, -1.2, 1);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(x + 8.91, 5.29, 1);
    glVertex3f(x + 2.35, 8.61, 1);
    glVertex3f(x + -0.97, 8.61, 1);
    glVertex3f(x + 6.73, 5.13, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(x + -0.8, 6.25 + 2, 1);
    glVertex3f(x + 2.7, 4.35 + 2, 1);
    glVertex3f(x + -5.35, 4.65 + 2, 1);
    glVertex3f(x + -5.85, 6.1 + 2, 1);
    glEnd();

    drawwheels(3.14159265358979323846, x);
    drawlamp(0, lampcol, 0, x);
}

void drawsmoke(float x, float y, float scaleY)
{
    glColor4f(0.5, 0.5, 0.5, scaleY); // Прозрачность зависит от масштаба
    float angle = 2.0f * 3.141591f / 10;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 10; i++)
    {
        float dx = 5 * cosf(angle * i);
        float dy = 5 * scaleY * sinf(angle * i);
        glVertex3f(x + dx, y + dy, 1);
    }
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

    DrawSkyline(x_position);
    drawwheels(wheel_angle, x_position);
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
    //glEnable(GL_DEPTH_TEST);
}

void initGLUT(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("s");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseClick);
}

int main(int argc, char** argv) {
    initGLUT(argc, argv);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}