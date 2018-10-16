#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
#include <cstdlib>
#include <irrKlang/irrKlang.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace irrklang;

extern float camera_horizontal_angle, up_horizontal_angle;
extern float camera_vertical_angle, up_vertical_angle;
extern float r;
extern float eyex, eyey, eyez, tarx, tary, tarz;
extern int camera_view;
extern int curdir;
extern int movefront;
extern int moveback;
extern int moveright;
extern int moveleft;
extern int fallright;
extern int fallleft;
extern int fallback;
extern int fallfront;
extern int leftclicked;
extern int levelover;
extern double curmousex;
extern double curmousey;
extern ISoundEngine *SoundEngine;

void moveRight();
void moveLeft();
void moveFront();
void moveBack();
void mouseClicked(GLFWwindow* window);
void mouseReleases(GLFWwindow* window);
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods);
void keyboardChar (GLFWwindow* window, unsigned int key);
void mousescroll(GLFWwindow* window, double dx, double dy);
void mouseButton (GLFWwindow* window, int button, int action, int mods);

