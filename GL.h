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
#include "objects.h"
#include "inputhandle.h"
using namespace std;

struct GLMatrices {
	glm::mat4 projection;					
	glm::mat4 model;
	glm::mat4 view;
	GLuint MatrixID;
};

typedef struct GLMatrices GLMatrices;
extern GLMatrices Matrices;
extern GLint model;
extern GLuint programID;
extern glm::mat4 VP;
extern glm::mat4 MVP;
static void error_callback(int error, const char* description);
void quit(GLFWwindow *window);
GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
GLFWwindow* initGLFW (int width, int height);
void initGL (GLFWwindow* window, int width, int height);
void reshapeWindow (GLFWwindow* window, int width, int height);
