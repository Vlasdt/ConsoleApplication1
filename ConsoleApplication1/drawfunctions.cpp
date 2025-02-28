#include <math.h>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "drawfunctions.h"

float xfrom = 0;
float xto = 10;
float v = 5;
int startTime = 0;

float vx = 5;
float yfrom = 0;
float yto = 10;
float vy = 3;
int startTimex = 0;
int startTimey = 0;

float vr = 90;
float rx = 10;
float ry = 5;


void InitOpenGL(int width, int height)
{
   glViewport(0,0,width,height);
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   gluPerspective(45.0, (GLfloat)width / height, 1.0, 10000.0);
   //glFrustum(-1.0,1.0,-1.0,1.0,1.5,100.0);

   glMatrixMode( GL_MODELVIEW );

   glEnable(GL_DEPTH_TEST); 
   glClearColor(0.2,0.3,0.4,0.0);

   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
   glEnable(GL_POINT_SMOOTH);

}

vector3 vector(float x, float y, float z)
{
	vector3 result = {x, y, z};
	return result;
}

color3 color(float r, float g, float b)
{
	color3 result = {r, g, b};
	return result;
}

void DrawPoint(float x, float y, float z, float r, float g, float b)
{
    glColor3d(r, g, b);
	glBegin(GL_POINTS);
	    glVertex3d(x, y, z);
    glEnd();
}

void DrawPoint(float x, float y, float z, float r, float g, float b, float size)
{
	glPointSize(size);
    glColor3d(r, g, b);
	glBegin(GL_POINTS);
	    glVertex3d(x, y, z);
    glEnd();
}

void DrawPoint(float x, float y, float size)
{
	glPointSize(size);
    glColor3d(1, 1, 1);
	glBegin(GL_POINTS);
	    glVertex2d(x, y);
    glEnd();
}

void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1, float r2, float g2, float b2)
{
	glBegin(GL_LINES);
    glColor3d(r1, g1, b1);
    glVertex3d(x1, y1, z1);
    glColor3d(r2, g2, b2);
    glVertex3d(x2, y2, z2);
    glEnd();
}

void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1)
{
	DrawLine(x1, y1, z1, x2, y2, z2, r1, g1, b1, r1, g1, b1); 
}

void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1, float r2, float g2, float b2)
{
	DrawLine(x1, y1, 0, x2, y2, 0, r1, g1, b1, r2, g2, b2); 
}

void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1)
{
	DrawLine(x1, y1, 0, x2, y2, 0, r1, g1, b1, r1, g1, b1); 
}

void DrawLine(float x1, float y1, float x2, float y2)
{
	DrawLine(x1, y1, 0, x2, y2, 0, 1, 1, 1, 1, 1, 1); 
}

void DrawLine(float x1, float y1, float x2, float y2, float size)
{
	glLineWidth(size);
	DrawLine(x1, y1, 0, x2, y2, 0, 1, 1, 1, 1, 1, 1); 
}

void DrawLine(vector3 v1, vector3 v2, color3 c1, color3 c2)
{
	DrawLine(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, c1.r, c1.g, c1.b, c2.r, c2.g, c2.b); 
}

void DrawLine(vector3 v1, vector3 v2, color3 c)
{
	DrawLine(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, c.r, c.g, c.b, c.r, c.g, c.b); 
}

void DrawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float r1, float g1, float b1, float r2, float g2, float b2, float r3, float g3, float b3)
{
	glBegin(GL_TRIANGLES);
    glColor3d(r1, g1, b1);
    glVertex3d(x1, y1, z1);
    glColor3d(r2, g2, b2);
    glVertex3d(x2, y2, z2);
    glColor3d(r3, g3, b3);
    glVertex3d(x3, y3, z3);
    glEnd();
}

void DrawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float r1, float g1, float b1)
{
	DrawTriangle(x1, y1, z1, x2, y2, z2, x3, y3, z3, r1, g1, b1, r1, g1, b1, r1, g1, b1);
}

void DrawTriangle(vector3 v1, vector3 v2, vector3 v3, color3 c)
{
	DrawTriangle(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, c.r, c.g, c.b);
}
void DrawTriangle(vector3 v1, vector3 v2, vector3 v3, color3 c1, color3 c2, color3 c3)
{
	DrawTriangle(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, c1.r, c1.g, c1.b, c2.r, c2.g, c2.b, c3.r, c3.g, c3.b);
}

void DrawQuad(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4,
			  float r1, float g1, float b1, float r2, float g2, float b2, float r3, float g3, float b3, float r4, float g4, float b4)
{
	glBegin(GL_QUADS);
	glColor3d(r1, g1, b1);
    glVertex3d(x1, y1, z1);
    glColor3d(r2, g2, b2);
    glVertex3d(x2, y2, z2);
    glColor3d(r3, g3, b3);
    glVertex3d(x3, y3, z3);
	glColor3d(r4, g4, b4);
    glVertex3d(x4, y4, z4);
    glEnd();
}

void DrawQuad(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4,
			  float r1, float g1, float b1)
{
	DrawQuad(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, r1, g1, b1, r1, g1, b1, r1, g1, b1, r1, g1, b1);
}

void DrawQuad(vector3 v1, vector3 v2, vector3 v3, vector3 v4, color3 c1, color3 c2, color3 c3, color3 c4)
{
	DrawQuad(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, v4.x, v4.y, v4.z, c1.r, c1.g, c1.b, c2.r, c2.g, c2.b, c3.r, c3.g, c3.b, c4.r, c4.g, c4.b);
}

void DrawQuad(vector3 v1, vector3 v2, vector3 v3, vector3 v4, color3 c)
{
	DrawQuad(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, v4.x, v4.y, v4.z, c.r, c.g, c.b);
}

void DrawRect(float x1, float y1, float z1, float w, float h, float r1, float g1, float b1)
{
	DrawQuad(x1-w/2, y1-h/2, z1, 
             x1+w/2, y1-h/2, z1, 
             x1+w/2, y1+h/2, z1, 
             x1-w/2, y1+h/2, z1, 
			 r1, g1, b1);
}

void DrawRect(float x1, float y1, float w, float h, float r1, float g1, float b1)
{
	DrawQuad(x1-w/2, y1-h/2, 0, 
             x1+w/2, y1-h/2, 0, 
             x1+w/2, y1+h/2, 0, 
             x1-w/2, y1+h/2, 0, 
			 r1, g1, b1);
}

void DrawRect(float x1, float y1, float w, float h)
{
	DrawQuad(x1-w/2, y1-h/2, 0, 
             x1+w/2, y1-h/2, 0, 
             x1+w/2, y1+h/2, 0, 
             x1-w/2, y1+h/2, 0, 
			 1, 1, 1);
}

void DrawPolygon(float **mas, int n, float r1, float g1, float b1)
{
  	glColor3d(r1, g1, b1);
	glBegin(GL_POLYGON);
	for (int i=0; i<n; i++)
		glVertex3d(mas[i][0], mas[i][1], mas[i][2]);
    glEnd();
}

void DrawCircle(float x, float y, float z, float radius, float r1, float g1, float b1)
{ // передаются координаты центра, радиус и цвет окружности
   glColor3d(r1, g1, b1);
   int n = 60;
   glBegin(GL_LINE_LOOP);
      for (int i = 0; i<n; i++)
          glVertex3d(x+radius*sin(i*2*3.14/n),
                            y+radius*cos(i*2*3.14/n), z);
    glEnd();
}

void DrawCircle(vector3 p, float radius, color3 c)
{ // передаются координаты центра, радиус и цвет окружности
	DrawCircle(p.x, p.y, p.z, radius, c.r, c.g, c.b);
}

void DrawRound(float x, float y, float z, float radius, float r1, float g1, float b1)
{ // передаются координаты центра, радиус и цвет круга
   glColor3d(r1, g1, b1);
   int n = 60;
   glBegin(GL_TRIANGLE_FAN);
      for (int i = 0; i<n; i++)
          glVertex3d(x+radius*sin(i*2*3.14/n),
                            y+radius*cos(i*2*3.14/n), z);
    glEnd();
}

void DrawRound(float x, float y, float radius)
{ // передаются координаты центра, радиус
  DrawRound(x, y, 0, radius, 1, 1, 1);
}


void DrawRound(vector3 p, float radius, color3 c)
{ // передаются координаты центра, радиус и цвет круга
	DrawRound(p.x, p.y, p.z, radius, c.r, c.g, c.b);
}

void DrawLines()
{
  float dx = 1;
  for (int i = -10; i<=10; i++)
	DrawLine(i*dx, -10, 0, i*dx, 10, 0, 1, 1, 1);
}

void Drawpoints()
{
	DrawLine(0, -10, 0, 0, 10, 0, 1, 1, 1);
	DrawLine(-10, 0, 0, 10, 0, 0, 1, 1, 1);

	glPointSize (20);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor3d(1, 1, 1);
	glBegin(GL_POINTS);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,3.0);
	glVertex2f(4.0,3.0);
	glVertex2f(6.0,1.5);
	glVertex2f(4.0,0.0);
	glEnd(); 

}

void DrawTriangles()
{
	DrawTriangle(vector(-5, 0), 
		         vector(1, 2), 
		         vector(4, -5), 
				 color(1, 0, 0), 
				 color(0, 1, 0), 
				 color(0, 0, 1));
}

void DrawGrid(float r, float g, float b)
{
	float dx = 1;
	for (int i = -10; i<=10; i++)
		DrawLine(i*dx, -10, 0, i*dx, 10, 0, r, g, b);
}

void DrawOneKube()
{
    glLineWidth(2);
	glTranslated(0, 0, 10); DrawGrid(1, 1, 1);	glRotated(90, 0, 0, 1);  DrawGrid(1, 1, 1);

	glPushMatrix();
	glTranslated(0, 0, -20);
	DrawGrid(1, 0, 0);	glRotated(90, 0, 0, 1);        DrawGrid(1, 0, 0);
	
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10, 0, -10);
	glRotated(90, 0, 1, 0);	DrawGrid(0, 1, 0); glRotated(90, 0, 0, 1);	DrawGrid(0, 1, 0);

	glTranslated(0, 0, 20);
	DrawGrid(0, 0, 1);	glRotated(90, 0, 0, 1);    DrawGrid(0, 0, 1);
	glPopMatrix();

	glTranslated(0, 10, -10);
	glRotated(90, 1, 0, 0);	DrawGrid(1, 1, 0); glRotated(90, 0, 0, 1);	DrawGrid(1, 1, 0);

	glTranslated(0, 0, 20);
	DrawGrid(0, 1, 1);	glRotated(90, 0, 0, 1);    DrawGrid(0, 1, 1);

}


void DrawKube()
{
    glTranslated(0, 0, -50 );
   glRotated(GetTickCount()/10.f, 0.1, 0.5, 0.3);

   // glRotated(40.f, 0.1, 0.5, 0.3);
  
     DrawOneKube();
}


void DrawMoving1()
{
    glTranslated(0, 0, -30 );
 
	DrawRect(0-1.2, 0, 0.4, 10);
	DrawRect(10+1.2, 0, 0.4, 10);
	float x = 0, y = 0;

	if (startTime==0) startTime = GetTickCount();

	float dt = (GetTickCount() - startTime)/1000.f;

	x = xfrom + v*dt;
	//if (x>xto) startTime = GetTickCount();

	if (((x>xto) &&(xto>xfrom)) || ((x<xto) &&(xto<xfrom)))
		{
			v = -v;
			float xtemp = xto;
			xto = xfrom;
			xfrom = xtemp;

			startTime = GetTickCount();
	}
	DrawRound(x, y, 1);
}

void DrawMoving2()
{

	glTranslated(0, 0, -30 );
 
    DrawRect(0-1.2, 5, 0.4, 12.8);
	DrawRect(10+1.2, 5, 0.4, 12.8);

    DrawRect(5, 0-1.2, 12, 0.4);
	DrawRect(5, 10+1.2, 12, 0.4);

	float x = 0;	float y = 0;

	if (startTimex==0) startTimex = GetTickCount();
	if (startTimey==0) startTimey = GetTickCount();

	float dtx = (GetTickCount() - startTimex)/1000.f;
	float dty = (GetTickCount() - startTimey)/1000.f;

	x = xfrom + vx*dtx;	
    y = yfrom + vy*dty;

	if (((x>xto) &&(xto>xfrom)) || ((x<xto) &&(xto<xfrom)))
		{
			vx = -vx;
			float xtemp = xto;
			xto = xfrom;
			xfrom = xtemp;

			startTimex = GetTickCount();
	}
	if (((y>yto) &&(yto>yfrom)) || ((y<yto) &&(yto<yfrom)))
		{
			vy = -vy;
			float ytemp = yto;
			yto = yfrom;
			yfrom = ytemp;

			startTimey = GetTickCount();
		}

	DrawRound(x, y, 1);

}

void DrawMoving3()
{
	  glTranslated(0, 0, -30 );

      float dt = (GetTickCount() - startTime)/1000.f;

	  float x = rx * sin(dt*vr/60.f);
	  float y = ry * cos(dt*vr/60.f);

	  DrawRound(x, y, 0.5);
}

void DrawMoving4()
{
	  glTranslated(0, 0, -30 );

      float dt = (GetTickCount() - startTime)/1000.f;

      float x = rx*sin(dt*vx/0.7);
	  float y = ry*cos(dt*vy/1.2);


	  DrawRound(x, y, 0.5);
}

void DrawMoving5()
{
	 glTranslated(0, 0, -60 );
     float scale = (sin(GetTickCount()/1000.f) + 2)/2.f;
	 
 	  glScaled(scale, scale, 1);
      glRotated(GetTickCount()/10.f, 0.1, 0.2, 1);

	 DrawOneKube();
}

void DrawCamera1()
{
	DrawOneKube();
}

void Draw()
{

   //DrawKube();
   DrawMoving1();
   //DrawMoving2();
   //DrawMoving3();
   //DrawMoving4();
   //DrawMoving5();

//   glTranslated(0, 0, -5);
  // DrawCamera1();

//   DrawRound(0, 0, 10);
}
