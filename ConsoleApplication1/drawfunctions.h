struct vector3
{
 float x, y, z;
} ;

struct color3
{
 float r, g, b;
};

vector3 vector(float x, float y, float z=0);

color3 color(float r, float g, float b);

void DrawPoint(float x, float y, float z, float r, float g, float b);
void DrawPoint(float x, float y, float z, float r, float g, float b, float size);
void DrawPoint(float x, float y, float size);

void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1, float r2, float g2, float b2);
void DrawLine(float x1, float y1, float z1, float x2, float y2, float z2, float r1, float g1, float b1);
void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1, float r2, float g2, float b2);
void DrawLine(float x1, float y1, float x2, float y2, float r1, float g1, float b1);
void DrawLine(float x1, float y1, float x2, float y2);
void DrawLine(vector3 v1, vector3 v2, color3 c1, color3 c2);
void DrawLine(vector3 v1, vector3 v2, color3 c);
void DrawLine(float x1, float y1, float x2, float y2, float size);

void DrawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float r1, float g1, float b1, float r2, float g2, float b2, float r3, float g3, float b3);
void DrawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float r1, float g1, float b1);
void DrawTriangle(vector3 v1, vector3 v2, vector3 v3, color3 c);
void DrawTriangle(vector3 v1, vector3 v2, vector3 v3, color3 c1, color3 c2, color3 c3);

void DrawQuad(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4,
			  float r1, float g1, float b1, float r2, float g2, float b2, float r3, float g3, float b3, float r4, float g4, float b4);
void DrawQuad(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4,
			  float r1, float g1, float b1);
void DrawQuad(vector3 v1, vector3 v2, vector3 v3, vector3 v4, color3 c1, color3 c2, color3 c3, color3 c4);
void DrawQuad(vector3 v1, vector3 v2, vector3 v3, vector3 v4, color3 c);

void DrawRect(float x1, float y1, float z1, float w, float h, float r1, float g1, float b1);

void DrawPolygon(float **mas, int n, float r1, float g1, float b1);

void DrawCircle(float x, float y, float z, float radius, float r1, float g1, float b1);
void DrawCircle(vector3 p, float radius, color3 c);

void DrawRound(float x, float y, float z, float radius, float r1, float g1, float b1);
void DrawRound(vector3 p, float radius, color3 c);

void InitOpenGL(int width, int height);

void Draw();
