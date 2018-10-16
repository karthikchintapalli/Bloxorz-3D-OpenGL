#include "objects.h"
int level1[10][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
					  {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
					  {1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 0, 0, 0},
					  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
					  {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 3, 3, 0},
					  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, 2, 2},
					  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 2, 2},
					  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 5, 2, 2},
					  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}
					};
int active1[10][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
					  {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
					  {1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
					  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0},
					  {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
					  {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1},
					  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1},
					  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}
					};
int level2[10][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					  {0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0},
					  {0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0},
					  {1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
					  {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
					  {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
					  {1, 1, 0, 0, 0, 1, 1, 1, 3, 2, 2, 2, 2, 0, 0},
					  {0, 0, 0, 0, 0, 1, 1, 1, 3, 2, 2, 2, 2, 0, 0},
					  {0, 0, 0, 0, 0, 1, 5, 1, 0, 0, 2, 2, 4, 0, 0},
					  {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}
					};
int active2[10][15] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					  {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
					  {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
					  {1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
					  {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
					  {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
					  {1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0},
					  {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0},
					  {0, 0, 0, 0, 0, 1, 5, 1, 0, 0, 1, 1, -1, 0, 0},
					  {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}
					};
int level3[10][15] = {{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 3, 0, 0, 1, 1, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 3, 0, 0, 1, 1, 1, 2, 2, 0, 0},
					  {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 2, 2, 1, 1},
					  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 2, 5, 1},
					  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
					  {0, 0, 0, 0, 0, 0, 4, 0, 0, 1, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0}
					};
int active3[10][15] = {{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
					  {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
					  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
					  {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
					  {0, 0, 0, 0, 0, 0, -1, 0, 0, 1, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}
					};
int (*tilemap)[15] = level1;
int (*activetiles)[15] = active1; 
Object2D tiles1[10][15] = {};
Object2D base1[10][15] = {};
Object2D tiles2[10][15] = {};
Object2D base2[10][15] = {};
Object2D tiles3[10][15] = {};
Object2D base3[10][15] = {};
Object2D (*tiles)[15] = tiles1;
Object2D (*base)[15] = base1;
Object2D block, lightSource, scamN;
int curlevel = 1;
map <string, Object2D> display;

color red = {1.0, 0, 0};
color blue = {0, 0, 1};
color black = {0, 0, 0};
color grey = {168.0/255.0, 168.0/255.0, 168.0/255.0};
color darkgrey = {50.0/255.0, 50.0/255.0, 50.0/255.0};
color green = {0, 0.5, 0};
color yellow = {1, 1, 0};
color white = {1, 1, 1};
color darkbrown = {179.0/255.0, 60.0/255.0, 0.0};
color orange = {255.0/255.0, 153.0/255.0, 0.0};
color lightgreen = {102.0/255.0, 255.0/255.0, 102.0/255.0};
color tilecolor[6] = {white, grey, orange, green, lightgreen, darkgrey};

float tileside = 20.0;
float tiledepth = 6.0;
int blockstate = 0;

VAO *rectangle;
VAO *cuboid;

bool operator==(const color& lhs, const color& rhs)
{
    return (lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b);
}
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, const GLfloat* normal_buffer_data, GLenum fill_mode=GL_FILL)
{
	struct VAO* vao = new struct VAO;
	vao->PrimitiveMode = primitive_mode;
	vao->NumVertices = numVertices;
	vao->FillMode = fill_mode;

		// Create Vertex Array Object
		// Should be done after CreateWindow and before any other GL calls
		glGenVertexArrays(1, &(vao->VertexArrayID)); // VAO
		glGenBuffers (1, &(vao->VertexBuffer)); // VBO - vertices
		glGenBuffers (1, &(vao->ColorBuffer));  // VBO - colors
		glGenBuffers (1, &(vao->NormalBuffer));

		glBindVertexArray (vao->VertexArrayID); // Bind the VAO 
		glBindBuffer (GL_ARRAY_BUFFER, vao->VertexBuffer); // Bind the VBO vertices 
		glBufferData (GL_ARRAY_BUFFER, 3*numVertices*sizeof(GLfloat), vertex_buffer_data, GL_STATIC_DRAW); // Copy the vertices into VBO
		glVertexAttribPointer(
													0,                  // attribute 0. Vertices
													3,                  // size (x,y,z)
													GL_FLOAT,           // type
													GL_FALSE,           // normalized?
													0,                  // stride
													(void*)0            // array buffer offset
													);

		glBindBuffer (GL_ARRAY_BUFFER, vao->ColorBuffer); // Bind the VBO colors 
		glBufferData (GL_ARRAY_BUFFER, 3*numVertices*sizeof(GLfloat), color_buffer_data, GL_STATIC_DRAW);  // Copy the vertex colors
		glVertexAttribPointer(
													1,                  // attribute 1. Color
													3,                  // size (r,g,b)
													GL_FLOAT,           // type
													GL_FALSE,           // normalized?
													0,                  // stride
													(void*)0            // array buffer offset
													);

		glBindBuffer (GL_ARRAY_BUFFER, vao->NormalBuffer); // Bind the VBO colors 
		glBufferData (GL_ARRAY_BUFFER, 3*numVertices*sizeof(GLfloat), normal_buffer_data, GL_STATIC_DRAW);  // Copy the vertex colors
		glVertexAttribPointer(
													2,                  // attribute 1. Color
													3,                  // size (r,g,b)
													GL_FLOAT,           // type
													GL_FALSE,           // normalized?
													0,                  // stride
													(void*)0            // array buffer offset
													);

		return vao;
}

/* Generate VAO, VBOs and return VAO handle - Common Color for all vertices */
/* Render the VBOs handled by VAO */
void draw3DObject (struct VAO* vao)
{
	// Change the Fill Mode for this object
	glPolygonMode (GL_FRONT_AND_BACK, vao->FillMode);

	// Bind the VAO to use
	glBindVertexArray (vao->VertexArrayID);

	// Enable Vertex Attribute 0 - 3d Vertices
	glEnableVertexAttribArray(0);
	// Bind the VBO to use
	glBindBuffer(GL_ARRAY_BUFFER, vao->VertexBuffer);

	// Enable Vertex Attribute 1 - Color
	glEnableVertexAttribArray(1);
	// Bind the VBO to use
	glBindBuffer(GL_ARRAY_BUFFER, vao->ColorBuffer);

	glEnableVertexAttribArray(2);
	// Bind the VBO to use
	glBindBuffer(GL_ARRAY_BUFFER, vao->NormalBuffer);

	// Draw the geometry !
	glDrawArrays(vao->PrimitiveMode, 0, vao->NumVertices); // Starting from vertex 0; 3 vertices total -> 1 triangle
}
Object2D createCuboid (color objcolor, float anglex, float anglez, float x, float y, float z, float height, float width, float depth)
{
	//cout << objcolor.r << objcolor.g << objcolor.b;
	// GL3 accepts only Triangles. Quads are not supported
	GLfloat vertex_buffer_data [] = {
		//Front
		-width/2, height/2, depth/2, // vertex 1
		-width/2, -height/2, depth/2, // vertex 2
		width/2, -height/2, depth/2, // vertex 3

		width/2, -height/2, depth/2, // vertex 3
		width/2, height/2, depth/2, // vertex 4
		-width/2, height/2, depth/2,  // vertex 1
		//-------------------------------------------
		//Back
        -width/2, height/2, -depth/2, // vertex 1
		-width/2, -height/2, -depth/2, // vertex 2
		width/2, -height/2, -depth/2, // vertex 3

		width/2, -height/2, -depth/2, // vertex 3
		width/2, height/2, -depth/2, // vertex 4
		-width/2, height/2, -depth/2,  // vertex 1
		//-----------------------------------------
		//Top
		-width/2, height/2, depth/2, // vertex 1
		-width/2, height/2, -depth/2, // vertex 2
		width/2, height/2, -depth/2, // vertex 3

		width/2, height/2, -depth/2, // vertex 3
		width/2, height/2, depth/2, // vertex 4
		-width/2, height/2, depth/2,  // vertex 1
		//----------------------------------------
		//Bottom
        -width/2, -height/2, depth/2, // vertex 1
		-width/2, -height/2, -depth/2, // vertex 2
		width/2, -height/2, -depth/2, // vertex 3

		width/2, -height/2, -depth/2, // vertex 3
		width/2, -height/2, depth/2, // vertex 4
		-width/2, -height/2, depth/2,  // vertex 1
		//-----------------------------------------
		//Left
		-width/2, height/2, depth/2, // vertex 1
		-width/2, -height/2, depth/2, // vertex 2
		-width/2, -height/2, -depth/2, // vertex 3

		-width/2, -height/2, -depth/2, // vertex 3
		-width/2, height/2, -depth/2, // vertex 4
		-width/2, height/2, depth/2,  // vertex 1
		//-----------------------------------------
		//Right
        width/2, height/2, depth/2, // vertex 1
		width/2, -height/2, depth/2, // vertex 2
		width/2, -height/2, -depth/2, // vertex 3

		width/2, -height/2, -depth/2, // vertex 3
		width/2, height/2, -depth/2, // vertex 4
		width/2, height/2, depth/2  // vertex 1
	};

	GLfloat color_buffer_data [] = {
		objcolor.r, objcolor.g, objcolor.b, // color 1
		objcolor.r, objcolor.g, objcolor.b, // color 2
		objcolor.r, objcolor.g, objcolor.b, // color 3

		objcolor.r, objcolor.g, objcolor.b, // color 3
		objcolor.r, objcolor.g, objcolor.b, // color 4
		objcolor.r, objcolor.g, objcolor.b, // color 1

		objcolor.r, objcolor.g, objcolor.b, // color 1
		objcolor.r, objcolor.g, objcolor.b, // color 2
		objcolor.r, objcolor.g, objcolor.b, // color 3

		objcolor.r, objcolor.g, objcolor.b, // color 3
		objcolor.r, objcolor.g, objcolor.b, // color 4
		objcolor.r, objcolor.g, objcolor.b, // color 1

		objcolor.r, objcolor.g, objcolor.b, // color 1
		objcolor.r, objcolor.g, objcolor.b, // color 2
		objcolor.r, objcolor.g, objcolor.b, // color 3

		objcolor.r, objcolor.g, objcolor.b, // color 3
		objcolor.r, objcolor.g, objcolor.b, // color 4
		objcolor.r, objcolor.g, objcolor.b, // color 1

		objcolor.r, objcolor.g, objcolor.b, // color 1
		objcolor.r, objcolor.g, objcolor.b, // color 2
		objcolor.r, objcolor.g, objcolor.b, // color 3

		objcolor.r, objcolor.g, objcolor.b, // color 3
		objcolor.r, objcolor.g, objcolor.b, // color 4
		objcolor.r, objcolor.g, objcolor.b, // color 1

		objcolor.r, objcolor.g, objcolor.b, // color 1
		objcolor.r, objcolor.g, objcolor.b, // color 2
		objcolor.r, objcolor.g, objcolor.b, // color 3

		objcolor.r, objcolor.g, objcolor.b, // color 3
		objcolor.r, objcolor.g, objcolor.b, // color 4
		objcolor.r, objcolor.g, objcolor.b, // color 1

		objcolor.r, objcolor.g, objcolor.b, // color 1
		objcolor.r, objcolor.g, objcolor.b, // color 2
		objcolor.r, objcolor.g, objcolor.b, // color 3

		objcolor.r, objcolor.g, objcolor.b, // color 3
		objcolor.r, objcolor.g, objcolor.b, // color 4
		objcolor.r, objcolor.g, objcolor.b, // color 1
	};

	GLfloat normal_buffer_data [] = {
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 
		0.0f, 1.0f, 0.0f, 

		0.0f, 1.0f, 0.0f, 
		0.0f, 1.0f, 0.0f, 
		0.0f, 1.0f, 0.0f, 

		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,

		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,

		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,

		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,

		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f, 
	};
	// create3DObject creates and returns a handle to a VAO that can be used later
	cuboid = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data, color_buffer_data, normal_buffer_data, GL_FILL);
	Object2D obj = {};
	obj.objectvao = cuboid;
	obj.x = x;
	obj.y = y;
	obj.z = z;
	obj.height = height;
	obj.width = width;
	obj.depth = depth;
	obj.anglex = anglex;
	obj.anglez = anglez;
	obj.objcolor = objcolor;
	obj.active = 1;
	return obj;
	
}
void initObjects(){
	//Create Map
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 15; j++){
			if(level1[i][j]){
				if(level1[i][j] == 5)
					tiles1[i][j] = createCuboid(tilecolor[level1[i][j]], 0, 0, (j - 7) * tileside, -3 * tiledepth/2.0, (i - 5) * tileside, tiledepth, tileside - 5.0, tileside - 5.0);
				else if(level1[i][j] == 4){
					tiles1[i][j] = createCuboid(tilecolor[level1[i][j]], 0, 0, (j - 7) * tileside, 0.0, (i - 5) * tileside, tiledepth, tileside - 3.0, tileside - 3.0);					
				}
				else	
				tiles1[i][j] = createCuboid(tilecolor[level1[i][j]], 0, 0, (j - 7) * tileside, -tiledepth/2.0, (i - 5) * tileside, tiledepth, tileside - 1.0, tileside - 1.0);
				base1[i][j] = createCuboid(black, 0, 0, (j - 7) * tileside, -tiledepth - 1.0, (i - 5) * tileside, 1.0, tileside, tileside);
			}
			if(level2[i][j]){
				if(level2[i][j] == 5)
					tiles2[i][j] = createCuboid(tilecolor[level2[i][j]], 0, 0, (j - 7) * tileside, -3 * tiledepth/2.0, (i - 5) * tileside, tiledepth, tileside - 5.0, tileside - 5.0);
				else if(level2[i][j] == 4){
					tiles2[i][j] = createCuboid(tilecolor[level2[i][j]], 0, 0, (j - 7) * tileside, 0.0, (i - 5) * tileside, tiledepth, tileside - 3.0, tileside - 3.0);					
				}
				else	
				tiles2[i][j] = createCuboid(tilecolor[level2[i][j]], 0, 0, (j - 7) * tileside, -tiledepth/2.0, (i - 5) * tileside, tiledepth, tileside - 1.0, tileside - 1.0);
				base2[i][j] = createCuboid(black, 0, 0, (j - 7) * tileside, -tiledepth - 1.0, (i - 5) * tileside, 1.0, tileside, tileside);
			}
			if(level3[i][j]){
				if(level3[i][j] == 5)
					tiles3[i][j] = createCuboid(tilecolor[level3[i][j]], 0, 0, (j - 7) * tileside, -3 * tiledepth/2.0, (i - 5) * tileside, tiledepth, tileside - 5.0, tileside - 5.0);
				else if(level3[i][j] == 4){
					tiles3[i][j] = createCuboid(tilecolor[level3[i][j]], 0, 0, (j - 7) * tileside, 0.0, (i - 5) * tileside, tiledepth, tileside - 3.0, tileside - 3.0);					
				}
				else	
				tiles3[i][j] = createCuboid(tilecolor[level3[i][j]], 0, 0, (j - 7) * tileside, -tiledepth/2.0, (i - 5) * tileside, tiledepth, tileside - 1.0, tileside - 1.0);
				base3[i][j] = createCuboid(black, 0, 0, (j - 7) * tileside, -tiledepth - 1.0, (i - 5) * tileside, 1.0, tileside, tileside);
			}

		}
	}
	//Create Block
	block = createCuboid(red, 90.0, 90.0, 0.0, 1.0, 3.0, 2.0 * tileside, tileside, tileside);
	display["topright"] = createCuboid (black, 0.0, 0.0, 7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["topleft"] = createCuboid (black, 0.0, 0.0, -7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["top"] = createCuboid (black, 0.0, 0.0, 0, 15.0, 0.0, 5.0, 20.0, 0.0);
	display["middle"] = createCuboid (black, 0.0, 0.0, 0, 0, 0.0, 5.0, 20.0, 0.0);
	display["botright"] = createCuboid (black, 0.0, 0.0, 7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["botleft"] = createCuboid (black, 0.0, 0.0, -7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["bottom"] = createCuboid (black, 0.0, 0.0, 0, -15.0, 0.0, 5.0, 20.0, 0.0);
	//Display tens
	display["topright1"] = createCuboid (black, 0.0, 0.0, 7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["topleft1"] = createCuboid (black, 0.0, 0.0, -7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["top1"] = createCuboid (black, 0.0, 0.0, 0, 15.0, 0.0, 5.0, 20.0, 0.0);
	display["middle1"] = createCuboid (black, 0.0, 0.0, 0, 0, 0.0, 5.0, 20.0, 0.0);
	display["botright1"] = createCuboid (black, 0.0, 0.0, 7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["botleft1"] = createCuboid (black, 0.0, 0.0, -7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["bottom1"] = createCuboid (black, 0.0, 0.0, 0, -15.0, 0.0, 5.0, 20.0, 0.0);
	//Display hundreds
	display["topright2"] = createCuboid (black, 0.0, 0.0, 7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["topleft2"] = createCuboid (black, 0.0, 0.0, -7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["top2"] = createCuboid (black, 0.0, 0.0, 0, 15.0, 0.0, 5.0, 20.0, 0.0);
	display["middle2"] = createCuboid (black, 0.0, 0.0, 0, 0, 0.0, 5.0, 20.0, 0.0);
	display["botright2"] = createCuboid (black, 0.0, 0.0, 7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["botleft2"] = createCuboid (black, 0.0, 0.0, -7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["bottom2"] = createCuboid (black, 0.0, 0.0, 0, -15.0, 0.0, 5.0, 20.0, 0.0);

	display["topright3"] = createCuboid (black, 0.0, 0.0, 7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["topleft3"] = createCuboid (black, 0.0, 0.0, -7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["top3"] = createCuboid (black, 0.0, 0.0, 0, 15.0, 0.0, 5.0, 20.0, 0.0);
	display["middle3"] = createCuboid (black, 0.0, 0.0, 0, 0, 0.0, 5.0, 20.0, 0.0);
	display["botright3"] = createCuboid (black, 0.0, 0.0, 7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["botleft3"] = createCuboid (black, 0.0, 0.0, -7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["bottom3"] = createCuboid (black, 0.0, 0.0, 0, -15.0, 0.0, 5.0, 20.0, 0.0);
	//Display tens
	display["topright4"] = createCuboid (black, 0.0, 0.0, 7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["topleft4"] = createCuboid (black, 0.0, 0.0, -7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["top4"] = createCuboid (black, 0.0, 0.0, 0, 15.0, 0.0, 5.0, 20.0, 0.0);
	display["middle4"] = createCuboid (black, 0.0, 0.0, 0, 0, 0.0, 5.0, 20.0, 0.0);
	display["botright4"] = createCuboid (black, 0.0, 0.0, 7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["botleft4"] = createCuboid (black, 0.0, 0.0, -7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["bottom4"] = createCuboid (black, 0.0, 0.0, 0, -15.0, 0.0, 5.0, 20.0, 0.0);
	//Display hundreds
	display["topright5"] = createCuboid (black, 0.0, 0.0, 7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["topleft5"] = createCuboid (black, 0.0, 0.0, -7.5, 7.5, 0.0, 20.0, 5.0, 0.0);
	display["top5"] = createCuboid (black, 0.0, 0.0, 0, 15.0, 0.0, 5.0, 20.0, 0.0);
	display["middle5"] = createCuboid (black, 0.0, 0.0, 0, 0, 0.0, 5.0, 20.0, 0.0);
	display["botright5"] = createCuboid (black, 0.0, 0.0, 7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["botleft5"] = createCuboid (black, 0.0, 0.0, -7.5, -7.5, 0.0, 20.0, 5.0, 0.0);
	display["bottom5"] = createCuboid (black, 0.0, 0.0, 0, -15.0, 0.0, 5.0, 20.0, 0.0);

	scamN = createCuboid (black, 0.0, 0.0, 0, 0.0, 0.0, 38.0, 5.0, 0.0);
}
