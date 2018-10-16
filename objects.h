#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
#include <cstdlib>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;

struct VAO {
	GLuint VertexArrayID;
	GLuint VertexBuffer;
	GLuint ColorBuffer;
	GLuint NormalBuffer;

	GLenum PrimitiveMode;
	GLenum FillMode;
	int NumVertices;
};
typedef struct VAO VAO;

struct color{
	float r, g, b;
};
typedef struct color color;
struct Object2D {
	float x, y, z;
	float height, width, depth;
	float anglex;
	float anglez;
	color objcolor;
	VAO *objectvao;
	int active;
};

typedef struct Object2D Object2D;

extern map <string, Object2D> blockparts;

extern float tileside;
extern float tiledepth;
extern int blockstate;
extern int curlevel;

extern color red;
extern color blue;
extern color black;
extern color grey;
extern color green;
extern color yellow;
extern color white;

extern VAO *rectangle;
extern VAO *cuboid;

extern int (*tilemap)[15];
extern int (*activetiles)[15];
extern Object2D (*tiles)[15];
extern Object2D (*base)[15];
extern int level1[10][15];
extern int active1[10][15];
extern int level2[10][15];
extern int active2[10][15];
extern int level3[10][15];
extern int active3[10][15];

extern Object2D tiles1[10][15];
extern Object2D base1[10][15];
extern Object2D tiles2[10][15];
extern Object2D base2[10][15];
extern Object2D tiles3[10][15];
extern Object2D base3[10][15];
extern Object2D block, lightSource, scamN;
extern color tilecolor[6];

extern map <string, Object2D> display;

bool operator==(const color& lhs, const color& rhs);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, const GLfloat* normal_buffer_data, GLenum fill_mode);
void draw3DObject (struct VAO* vao);
Object2D createCuboid (color objcolor, float anglex, float anglez, float x, float y, float z, float height, float width, float depth);
void initObjects();
