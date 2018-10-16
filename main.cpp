#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
#include <cstdlib>
#include "objects.h"
#include "GL.h"
#include "inputhandle.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <irrKlang/irrKlang.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
//#pragma comment(lib, "irrKlang.lib")
using namespace std;
using namespace irrklang;
float angle = 0.0;
int moves = 0;
int timetaken = 0;
int changelevel = 1;
double changetime = 0.0;
int gameover = 0;
glm::mat4 T, Tinv, R;
double newmousex, newmousey;
void drawDig(int dig, int place, int component, int stage)
{
	float x, y;
	if(place == 0){
		if (component == 1){
			if(stage == 0){
				x = -310.0;
				y = 250.0;
			}
			else {
				x = -15.0;
				y = 0.0;
			}
		}
		else if(component == 0){
			if(stage == 0){
				x = 340.0;
				y = 250.0;
			}
			else {
				x = 75.0;
				y = 0.0;
			}
		}
	}
	else if(place == 1){
		if (component == 1){
			if(stage == 0){
				x = -340.0;
				y = 250.0;
			}
			else {
				x = -45.0;
				y = 0.0;
			}
		}
		else if(component == 0){
			if(stage == 0){
				x = 310.0;
				y = 250.0;
			}
			else {
				x = 45.0;
				y = 0.0;
			}
		}
	}
	else if(place == 2){
		if (component == 1){
			if(stage == 0){
				x = -370.0;
				y = 250.0;
			}
			else {
				x = -75.0;
				y = 0.0;
			}
		}
		else if(component == 0){
			if(stage == 0){
				x = 280.0;
				y = 250.0;
			}
			else {
				x = 15.0;
				y = 0.0;
			}
		}
	}
	if(dig == 0 || dig == 2 || dig == 3 || dig == 5 || dig == 6 || dig == 7 || dig == 8 || dig == 9 || dig == -2 || dig == -6){
		string name;
		if(component == 0){
			if(place == 0) name = "top";
			else if(place == 1) name = "top1";
			else if(place == 2) name = "top2";
		}
		else if(component == 1){
			if(place == 0) name = "top3";
			else if(place == 1) name = "top4";
			else if(place == 2) name = "top5";	
		}
		Matrices.model = glm::mat4(1.0f);
		glm::mat4 translateRectangle = glm::translate (glm::vec3(x + display[name].x, y + display[name].y, 0));        // glTranslatef
		Matrices.model *= (translateRectangle);

		MVP = VP * Matrices.model;
		glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(display[name].objectvao);
	}
	if(dig == 0 || dig == 1 || dig == 2 || dig == 3 || dig == 4 || dig == 7 || dig == 8 || dig == 9 || dig == -1 || dig == -5 || dig == -4){
		string name;
		if(component == 0){
			if(place == 0) name = "topright";
			else if(place == 1) name = "topright1";
			else if(place == 2) name = "topright2";
		}
		else if(component == 1){
			if(place == 0) name = "topright3";
			else if(place == 1) name = "topright4";
			else if(place == 2) name = "topright5";	
		}
		Matrices.model = glm::mat4(1.0f);
		glm::mat4 translateRectangle = glm::translate (glm::vec3(x + display[name].x, y + display[name].y, 0));        // glTranslatef
		Matrices.model *= (translateRectangle);

		MVP = VP * Matrices.model;
		glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(display[name].objectvao);
	}
	if(dig == 0 || dig == 4 || dig == 5 || dig == 6 || dig == 8 || dig == 9 || dig == -3 || dig == -2 || dig == -1 || dig == -6 || dig == -5 || dig == -4){
		string name;
		if(component == 0){
			if(place == 0) name = "topleft";
			else if(place == 1) name = "topleft1";
			else if(place == 2) name = "topleft2";
		}
		else if(component == 1){
			if(place == 0) name = "topleft3";
			else if(place == 1) name = "topleft4";
			else if(place == 2) name = "topleft5";	
		}
		Matrices.model = glm::mat4(1.0f);
		glm::mat4 translateRectangle = glm::translate (glm::vec3(x + display[name].x, y + display[name].y, 0));        // glTranslatef
		Matrices.model *= (translateRectangle);

		MVP = VP * Matrices.model;
		glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(display[name].objectvao);
	}
	if(dig == 2 || dig == 3 || dig == 4 || dig == 5 || dig == 6 || dig == 8 || dig == 9 || dig == -2 || dig == -6 || dig == -4){
		string name;
		if(component == 0){
			if(place == 0) name = "middle";
			else if(place == 1) name = "middle1";
			else if(place == 2) name = "middle2";
		}
		else if(component == 1){
			if(place == 0) name = "middle3";
			else if(place == 1) name = "middle4";
			else if(place == 2) name = "middle5";	
		}
		Matrices.model = glm::mat4(1.0f);
		glm::mat4 translateRectangle = glm::translate (glm::vec3(x + display[name].x, y + display[name].y, 0));        // glTranslatef
		Matrices.model *= (translateRectangle);

		MVP = VP * Matrices.model;
		glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(display[name].objectvao);
	}
	if(dig == 0 || dig == 1 || dig == 3 || dig == 4 || dig == 5 || dig == 6 || dig == 7 || dig == 8 || dig == 9 || dig == -1 || dig == -5 || dig == -4){
		string name;
		if(component == 0){
			if(place == 0) name = "botright";
			else if(place == 1) name = "botright1";
			else if(place == 2) name = "botright2";
		}
		else if(component == 1){
			if(place == 0) name = "botright3";
			else if(place == 1) name = "botright4";
			else if(place == 2) name = "botright5";	
		}
		Matrices.model = glm::mat4(1.0f);
		glm::mat4 translateRectangle = glm::translate (glm::vec3(x + display[name].x, y + display[name].y, 0));        // glTranslatef
		Matrices.model *= (translateRectangle);

		MVP = VP * Matrices.model;
		glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(display[name].objectvao);
	}
	if(dig == 0 || dig == 2 || dig == 6 || dig == 8 || dig == -1 || dig == -2 || dig == -3 || dig == -6 || dig == -4 || dig == -5){
		string name;
		if(component == 0){
			if(place == 0) name = "botleft";
			else if(place == 1) name = "botleft1";
			else if(place == 2) name = "botleft2";
		}
		else if(component == 1){
			if(place == 0) name = "botleft3";
			else if(place == 1) name = "botleft4";
			else if(place == 2) name = "botleft5";	
		}
		Matrices.model = glm::mat4(1.0f);
		glm::mat4 translateRectangle = glm::translate (glm::vec3(x + display[name].x, y + display[name].y, 0));        // glTranslatef
		Matrices.model *= (translateRectangle);

		MVP = VP * Matrices.model;
		glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(display[name].objectvao);
	}
	if(dig == 0 || dig == 2 || dig == 3 || dig == 5 || dig == 6 || dig == 8 || dig == 9 || dig == -1 || dig == -2 || dig == -3){
		string name;
		if(component == 0){
			if(place == 0) name = "bottom";
			else if(place == 1) name = "bottom1";
			else if(place == 2) name = "bottom2";
		}
		else if(component == 1){
			if(place == 0) name = "bottom3";
			else if(place == 1) name = "bottom4";
			else if(place == 2) name = "bottom5";	
		}
		Matrices.model = glm::mat4(1.0f);
		glm::mat4 translateRectangle = glm::translate (glm::vec3(x + display[name].x, y + display[name].y, 0));        // glTranslatef
		Matrices.model *= (translateRectangle);

		MVP = VP * Matrices.model;
		glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(display[name].objectvao);
	}
}
void draw (GLFWwindow* window)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram (programID);

	if(gameover){
		Matrices.view = glm::lookAt(glm::vec3(0, 0, 5.0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Rotating Camera for 3D
		Matrices.projection = glm::ortho(-400.0f, 400.0f, -300.0f, 300.0f, 0.1f, 500.0f);
		VP = Matrices.projection * Matrices.view;		
		drawDig(-6, 2, 1, 1);
		drawDig(1, 1, 1, 1);
		drawDig(-5, 0, 1, 1);
		drawDig(1, 2, 0, 1);
		drawDig(5, 1, 0, 1);
		drawDig(-4, 0, 0, 1);

		Matrices.model = glm::mat4(1.0f);
		glm::mat4 rotateRectangle = glm::rotate ((float)(20.0 * M_PI/180.0), glm::vec3(0, 0, 1));        // glTranslatef
		glm::mat4 translateRectangle = glm::translate (glm::vec3(-15.0, 0, 0));        // glTranslatef
		Matrices.model *= translateRectangle * rotateRectangle;

		MVP = VP * Matrices.model;
		glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(scamN.objectvao);

	}
	else if(changelevel){
		Matrices.view = glm::lookAt(glm::vec3(0, 0, 5.0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Rotating Camera for 3D
		Matrices.projection = glm::ortho(-400.0f, 400.0f, -300.0f, 300.0f, 0.1f, 500.0f);
		VP = Matrices.projection * Matrices.view;

		drawDig(-3, 2, 1, 1);
		drawDig(-2, 1, 1, 1);
		drawDig(-1, 0, 1, 1);
		drawDig(-2, 2, 0, 1);
		drawDig(-3, 1, 0, 1);
		drawDig(curlevel, 0, 0, 1);
	}
	else {
		if(camera_view == 3){
			eyex = (block.x - 7.0) * tileside;
			eyez = (block.z - 5.0) * tileside;
			eyey = (block.y + 2) * tileside;
			tarx = eyex + 100.0;
			tary = eyey - 50.0;
			tarz = eyez;
		}
		else if(camera_view == 4){
			if(leftclicked){
				glfwGetCursorPos(window, &newmousex, &newmousey);
				newmousex -= 400.0;
				newmousey = 300.0 - newmousey;
				if(newmousex > 0)
				camera_horizontal_angle = camera_horizontal_angle + (curmousey - newmousey) * 0.5;
				else 
				camera_horizontal_angle = camera_horizontal_angle - (curmousey - newmousey) * 0.5;
				up_horizontal_angle = camera_horizontal_angle;
				curmousey = newmousey;
				curmousex = newmousey; 
			}
		}
		else if(camera_view == 5) {
			eyex = (block.x - 7.0) * tileside;
			eyez = (block.z - 5.0) * tileside;
			eyey = (block.y) * tileside;
			tarx = eyex;
			tary = eyey;
			tarz = eyez; 
			if(curdir == 0) eyez += 100.0;
			else if(curdir == 1) eyex += 100.0;
			else if(curdir == 2) eyex -= 100.0;
			else if(curdir == 3) eyez -= 100.0;
		}
		glm::vec3 eye (r * sin(camera_horizontal_angle*M_PI/180.0f) 
				* cos(camera_vertical_angle*M_PI/180.0f) + eyex, 
				r * sin(camera_vertical_angle*M_PI/180.0f) + eyey, 
				r * cos(camera_horizontal_angle*M_PI/180.0f) 
				* cos(camera_vertical_angle*M_PI/180.0f) + eyez);
		glm::vec3 target (tarx, tary, tarz);
		glm::vec3 up (1 * -sin(up_horizontal_angle*M_PI/180.0f) 
				* sin(up_vertical_angle*M_PI/180.0f), 
				1 * cos(up_vertical_angle*M_PI/180.0f), 
				1 * -cos(up_horizontal_angle*M_PI/180.0f) 
				* sin(up_vertical_angle*M_PI/180.0f));
		Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
		Matrices.projection = glm::perspective (20.f, (GLfloat) 800 / (GLfloat) 600, 0.1f, 500.0f);
		// -----------------------------------------------------------------------
		VP = Matrices.projection * Matrices.view;

		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 15; j++){
				if(activetiles[i][j]){
					Matrices.model = glm::mat4(1.0f);
					glm::mat4 translateRectangle = glm::translate (glm::vec3(tiles[i][j].x, tiles[i][j].y, tiles[i][j].z));			
					Matrices.model *= translateRectangle;
					MVP = VP * Matrices.model;
					glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
					glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
					draw3DObject(tiles[i][j].objectvao);

					Matrices.model = glm::mat4(1.0f);
					translateRectangle = glm::translate (glm::vec3(base[i][j].x, base[i][j].y, base[i][j].z));			
					Matrices.model *= translateRectangle;
					MVP = VP * Matrices.model;
					glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
					glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
					draw3DObject(base[i][j].objectvao);
				}
			}
		}

		Matrices.model = glm::mat4(1.0f);
		glm::mat4 translateRectangle = glm::translate (glm::vec3((block.x - 7.0) * tileside, block.y * tileside, (block.z - 5.0) * tileside));			
		glm::mat4 rotateRectanglex = glm::rotate((float)((90.0 - block.anglex) * M_PI/180.0f), glm::vec3(0,0,1));
		glm::mat4 rotateRectanglez = glm::rotate((float)((90.0 - block.anglez) * M_PI/180.0f), glm::vec3(1,0,0));
		

		if(moveright){
			if(angle <= -90.0){
				angle = 0.0;
				moveRight();
				moves++;
				SoundEngine->play2D("./Sounds/move.wav", false);
			}
			else {
				float dx;
				if(blockstate == 0 || blockstate == 2) dx = 0.5;
				else dx = 1.0;
				T = glm::translate (glm::vec3((block.x - 7.0 + dx) * -tileside, 0, 0));
				Tinv = glm::translate (glm::vec3((block.x - 7.0 + dx) * tileside, 0, 0));
				angle -= 10.0;
				R = glm::rotate((float)((angle) * M_PI/180.0f), glm::vec3(0,0,1));
			}
			Matrices.model = Tinv * R * T * translateRectangle * rotateRectanglex * rotateRectanglez;
		}
		else if(moveleft){
			if(angle >= 90.0){
				angle = 0.0;
				moves++;
				moveLeft();
				SoundEngine->play2D("./Sounds/move.wav", false);
			}
			else {
				float dx;
				if(blockstate == 0 || blockstate == 2) dx = -0.5;
				else dx = -1.0;
				T = glm::translate (glm::vec3((block.x - 7.0 + dx) * -tileside, 0, 0));
				Tinv = glm::translate (glm::vec3((block.x - 7.0 + dx) * tileside, 0, 0));
				angle += 10.0;
				R = glm::rotate((float)((angle) * M_PI/180.0f), glm::vec3(0, 0, 1));
			}
			Matrices.model = Tinv * R * T * translateRectangle * rotateRectanglex * rotateRectanglez;
		}
		else if(movefront){
			if(angle <= -90.0){
				angle = 0.0;
				moves++;
				moveFront();
				SoundEngine->play2D("./Sounds/move.wav", false);
			}
			else {
				float dz;
				if(blockstate == 0 || blockstate == 1) dz = -0.5;
				else dz = -1.0;
				T = glm::translate (glm::vec3(0, 0, (block.z - 5.0 + dz) * -tileside));
				Tinv = glm::translate (glm::vec3(0, 0, (block.z - 5.0 + dz) * tileside));
				angle -= 10.0;
				R = glm::rotate((float)((angle) * M_PI/180.0f), glm::vec3(1, 0, 0));
			}
			Matrices.model = Tinv * R * T * translateRectangle * rotateRectanglex * rotateRectanglez;
		}
		else if(moveback){
			if(angle >= 90.0){
				angle = 0.0;
				moves++;
				moveBack();
				SoundEngine->play2D("./Sounds/move.wav", false);
			}
			else {
				float dz;
				if(blockstate == 0 || blockstate == 1) dz = 0.5;
				else dz = 1.0;
				T = glm::translate (glm::vec3(0, 0, (block.z - 5.0 + dz) * -tileside));
				Tinv = glm::translate (glm::vec3(0, 0, (block.z - 5.0 + dz) * tileside));
				angle += 10.0;
				R = glm::rotate((float)((angle) * M_PI/180.0f), glm::vec3(1, 0, 0));
			}
			Matrices.model = Tinv * R * T * translateRectangle * rotateRectanglex * rotateRectanglez;
		}
		else{
			glm::mat4 R90 = glm::rotate(0.0f, glm::vec3(1, 0, 0));
			glm::mat4 T1 = glm::translate (glm::vec3(0, 0, 0));
			glm::mat4 T1inv = glm::translate (glm::vec3(0, 0, 0));
			if(fallleft){
				block.active = 0;
				if(blockstate == 1){
					if(block.x + 0.5 >= 0.0){
						if(tilemap[(int)block.z][(int)(block.x + 0.5)] != 0){
							R90 = glm::rotate((float)(90.0 * M_PI/180.0f), glm::vec3(0, 0, 1));
							T1 = glm::translate (glm::vec3((block.x - 7.0) * -tileside, (block.y - 0.5) * -tileside, 0));
							T1inv = glm::translate (glm::vec3((block.x - 7.0) * tileside, (block.y - 0.5) * tileside, 0));
						}
					}
				}
				block.y -= 0.4;
			}
			else if(fallright){
				block.active = 0;
				if(blockstate == 1){
					if(block.x - 0.5 <= 15.0){
						if(tilemap[(int)block.z][(int)(block.x - 0.5)] != 0){
							R90 = glm::rotate((float)(-90.0 * M_PI/180.0f), glm::vec3(0, 0, 1));
							T1 = glm::translate (glm::vec3((block.x - 7.0) * -tileside, (block.y - 0.5) * -tileside, 0));
							T1inv = glm::translate (glm::vec3((block.x - 7.0) * tileside, (block.y - 0.5) * tileside, 0));
						}
					}
				}
				block.y -= 0.4;
			}
			else if(fallfront){
				block.active = 0;
				if(blockstate == 2){
					if(block.z + 0.5 >= 0.0){
						if(tilemap[(int)(block.z + 0.5)][(int)(block.x)] != 0){
							R90 = glm::rotate((float)(-90.0 * M_PI/180.0f), glm::vec3(1, 0, 0));
							T1 = glm::translate (glm::vec3(0, (block.y - 0.5) * -tileside, (block.z - 5.0) * -tileside));
							T1inv = glm::translate (glm::vec3(0, (block.y - 0.5) * tileside, (block.z - 5.0) * tileside));
						}
					}
				}
				block.y -= 0.4;
			}
			else if(fallback){
				block.active = 0;
				if(blockstate == 2){
					if(block.z - 0.5 <= 10.0){
						if(tilemap[(int)(block.z - 0.5)][(int)(block.x)] != 0){
							R90 = glm::rotate((float)(90.0 * M_PI/180.0f), glm::vec3(1, 0, 0));
							T1 = glm::translate (glm::vec3(0, (block.y - 0.5) * -tileside, (block.z - 5.0) * -tileside));
							T1inv = glm::translate (glm::vec3(0, (block.y - 0.5) * tileside, (block.z - 5.0) * tileside));
						}
					}
				}
				block.y -= 0.4;
			}
			if(block.y < - 20.0){
				if(levelover){
					changelevel = 1;
					changetime = glfwGetTime();
					curlevel++;
				}
				if(curlevel == 1){
					tilemap = level1;
					activetiles = active1;
					tiles = tiles1;
					base = base1;
					block.x = 0.0;
					block.z = 3.0;
				}
				if(curlevel == 2){
					tilemap = level2;
					activetiles = active2;
					tiles = tiles2;
					base = base2;
					block.x = 1.0;
					block.z = 6.0;
				}
				if(curlevel == 3){
					tilemap = level3;
					activetiles = active3;
					tiles = tiles3;
					base = base3;
					block.x = 0.0;
					block.z = 3.0;
				}
				if(curlevel == 4) gameover = 1;
				levelover = 0;
				blockstate = 0;
				block.y = 1.0;
				block.anglex = block.anglez = 90.0;
				block.active = 1;
				fallback = fallfront = fallright = fallleft = 0;
				curdir = 0;
				for(int i = 0; i < 10; i++){
					for(int j = 0; j < 15; j++){
						if(tilemap[i][j] == 2)
							activetiles[i][j] = 1;
						if(tilemap[i][j] == 4)
							activetiles[i][j] = -1;
						if(tilemap[i][j] == 3)
							activetiles[i][j] = 0;
					}
				}
			}
			Matrices.model *= T1inv * R90 * T1 * translateRectangle * rotateRectanglex * rotateRectanglez;
		}

		MVP = VP * Matrices.model;
		glUniformMatrix4fv(model, 1, GL_FALSE, &Matrices.model[0][0]);
		glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
		draw3DObject(block.objectvao);

		Matrices.view = glm::lookAt(glm::vec3(0, 0, 5.0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Rotating Camera for 3D
		Matrices.projection = glm::ortho(-400.0f, 400.0f, -300.0f, 300.0f, 0.1f, 500.0f);
		VP = Matrices.projection * Matrices.view;
		if(moves == 0) drawDig(0, 0, 0, 0);
		else {
			int score = moves;
			int place = 0;
			while(score){
				int dig = score % 10;
				drawDig(dig, place, 0, 0);
				score /= 10;
				place ++;
			}
		}
		if(timetaken == 0) drawDig(0, 0, 1, 0);
		else {
			int score = timetaken;
			int place = 0;
			while(score){
				int dig = score % 10;
				drawDig(dig, place, 1, 0);
				score /= 10;
				place ++;
			}
		}
	}

}
int main (int argc, char** argv)
{
	int width = 800;
	int height = 600;
	moves = 0;
	timetaken = 0;
	gameover = 0;
	GLFWwindow* window = initGLFW(width, height);

	initGL (window, width, height);
	SoundEngine->play2D("./Sounds/breakout.mp3", true);
	double last_update_time = glfwGetTime(), current_time;
		/* Draw in loop */
	while (!glfwWindowShouldClose(window)) {
		draw(window);
		glfwSwapBuffers(window);
		glfwPollEvents();
		// Control based on time (Time based transformation like 5 degrees rotation every 0.5s)
		current_time = glfwGetTime();
		if(current_time - last_update_time >= 1.0){
			timetaken ++;
			last_update_time = current_time;
		}
		if(current_time - changetime >= 2.0 && changelevel == 1){
			changelevel = 0;
		}
	}
	glfwTerminate();
//    exit(EXIT_SUCCESS);
}