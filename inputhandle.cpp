#include "inputhandle.h"
#include "objects.h"

float camera_horizontal_angle = -10.0;
float camera_vertical_angle = 50.0;
float up_vertical_angle = camera_vertical_angle;
float up_horizontal_angle = camera_horizontal_angle;
int camera_view = 1;
float r = 300.0;
float eyex = 0;
float eyey = 0;
float eyez = 0;
float tarx = 0;
float tary = 0;
float tarz = 0;
double curmousex, curmousey;
int levelover = 0;
int curdir = 0;
int movefront = 0;
int moveleft = 0;
int moveright = 0;
int moveback = 0;
int fallright = 0;
int fallleft = 0;
int fallback = 0;
int fallfront = 0;
int leftclicked = 0;
ISoundEngine *SoundEngine = createIrrKlangDevice();

void moveRight()
{
	moveright = 0;
	if(blockstate == 0){
		block.anglex = 0.0;
		block.x += 1.5;
		block.y = 0.5;
		blockstate = 1;
		if(block.x > 15.0){
			fallright = 1;
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
		}
		else if(activetiles[(int)block.z][(int)(block.x + 0.5)] == 0){
			fallright = 1;
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
		}
	}
	else if(blockstate == 2){
		block.x += 1.0;
		if(block.x > 15.0)
			fallright = 1;
		else if(activetiles[(int)(block.z + 0.5)][(int)(block.x)] == 0 &&
			activetiles[(int)(block.z - 0.5)][(int)(block.x)] == 0){
			fallright = 1;
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
		}
		else if(activetiles[(int)(block.z + 0.5)][(int)(block.x)] == 0){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallback = 1;
		}
		else if(activetiles[(int)(block.z - 0.5)][(int)(block.x)] == 0){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallfront = 1;
		}
	}
	else if(blockstate == 1){
		block.anglex = 90.0;
		block.x += 1.5;
		block.y = 1.0;
		blockstate = 0;	
		if(block.x > 15.0){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallright = 1;
		}
		else if(activetiles[(int)block.z][(int)(block.x)] == 0) {
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallright = 1;
		}

		else if(tilemap[(int)block.z][(int)(block.x)] == 5){
			fallright = 1;
			levelover = 1;
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 2){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallright = 1;
			activetiles[(int)block.z][(int)(block.x)] = 0;
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 4){
			activetiles[(int)block.z][(int)(block.x)] *= -1;
			if(curlevel == 1){
				activetiles[5][12] = 1 - activetiles[5][12];
				activetiles[6][12] = 1 - activetiles[6][12];
				activetiles[5][13] = 1 - activetiles[5][13];
			}
			else if(curlevel == 2){
				activetiles[6][8] = 1 - activetiles[6][8];
				activetiles[7][8] = 1 - activetiles[7][8];
			}
			else if(curlevel == 3){
				activetiles[1][5] = 1 - activetiles[1][5];
				activetiles[2][5] = 1 - activetiles[2][5];	
			}
		}
	}
	block.active = 1;
}
void moveLeft()
{
	moveleft = 0;
	if(blockstate == 0){
		block.anglex = 0.0;
		block.x -= 1.5;
		block.y = 0.5;
		blockstate = 1;
		if(block.x < 0.0){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallleft = 1;
		}
		else if(activetiles[(int)block.z][(int)(block.x - 0.5)] == 0){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallleft = 1;
		}
	}
	else if(blockstate == 2){
		block.x -= 1.0;
		if(block.x < 0.0)
			fallleft = 1;
		else if(activetiles[(int)(block.z + 0.5)][(int)(block.x)] == 0 &&
			activetiles[(int)(block.z - 0.5)][(int)(block.x)] == 0){
			fallleft = 1;
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
		}
		else if(activetiles[(int)(block.z + 0.5)][(int)(block.x)] == 0){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallback = 1;
		}
		else if(activetiles[(int)(block.z - 0.5)][(int)(block.x)] == 0){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallfront = 1;
		}
	}
	else if(blockstate == 1){
		block.anglex = 90.0;
		block.x -= 1.5;
		block.y = 1.0;
		blockstate = 0;
		if(block.x < 0.0)
			fallleft = 1;
		else if(activetiles[(int)block.z][(int)(block.x)] == 0){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallleft = 1;	
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 5){
			fallleft = 1;
			levelover = 1;
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 2){
			SoundEngine->play2D("./Sounds/Fall.mp3", false);
			fallleft = 1;
			activetiles[(int)block.z][(int)(block.x)] = 0;
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 4){
			activetiles[(int)block.z][(int)(block.x)] *= -1;
			if(curlevel == 1){
				activetiles[5][12] = 1 - activetiles[5][12];
				activetiles[6][12] = 1 - activetiles[6][12];
				activetiles[5][13] = 1 - activetiles[5][13];
			}
			else if(curlevel == 2){
				activetiles[6][8] = 1 - activetiles[6][8];
				activetiles[7][8] = 1 - activetiles[7][8];
			}
			else if(curlevel == 3){
				activetiles[1][5] = 1 - activetiles[1][5];
				activetiles[2][5] = 1 - activetiles[2][5];	
			}
		}

	}
	block.active = 1;
}
void moveFront()
{
	movefront = 0;
	if(blockstate == 0){
		block.anglez = 0.0;
		block.z -= 1.5;
		block.y = 0.5;
		blockstate = 2;
		if(block.z < 0.0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallfront = 1;
		}
		else if(activetiles[(int)(block.z - 0.5)][(int)(block.x)] == 0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallfront = 1;
		}
	}
	else if(blockstate == 1){
		block.z -= 1.0;
		if(block.z < 0.0)
			fallfront = 1;
		else if(activetiles[(int)(block.z)][(int)(block.x + 0.5)] == 0 &&
			activetiles[(int)(block.z)][(int)(block.x - 0.5)] == 0){
			fallleft = 1;
			SoundEngine->play2D("./Fall.mp3", false);
		}
		else if(activetiles[(int)(block.z)][(int)(block.x + 0.5)] == 0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallright = 1;
		}
		else if(activetiles[(int)(block.z)][(int)(block.x - 0.5)] == 0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallleft = 1;
		}
	}
	else if(blockstate == 2){
		block.anglez = 90.0;
		block.z -= 1.5;
		block.y = 1.0;
		blockstate = 0;
		if(block.z < 0.0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallfront = 1;
		}
		else if(activetiles[(int)block.z][(int)(block.x)] == 0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallfront = 1;	
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 5){
			fallfront = 1;
			levelover = 1;
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 2){
			SoundEngine->play2D("./Fall.mp3", false);
			fallfront = 1;
			activetiles[(int)block.z][(int)(block.x)] = 0;
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 4){
			activetiles[(int)block.z][(int)(block.x)] *= -1;
			if(curlevel == 1){
				activetiles[5][12] = 1 - activetiles[5][12];
				activetiles[6][12] = 1 - activetiles[6][12];
				activetiles[5][13] = 1 - activetiles[5][13];
			}
			else if(curlevel == 2){
				activetiles[6][8] = 1 - activetiles[6][8];
				activetiles[7][8] = 1 - activetiles[7][8];
			}
			else if(curlevel == 3){
				activetiles[1][5] = 1 - activetiles[1][5];
				activetiles[2][5] = 1 - activetiles[2][5];	
			}
		}
	}
	block.active = 1;
}
void moveBack()
{
	moveback = 0;
	if(blockstate == 0){
		block.anglez = 0.0;
		block.z += 1.5;
		block.y = 0.5;
		blockstate = 2;
		if(block.z > 10.0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallback = 1;
		}
		else if(activetiles[(int)(block.z + 0.5)][(int)(block.x)] == 0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallback = 1;
		}
	}
	else if(blockstate == 1){
		block.z += 1.0;
		if(block.z > 10.0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallback = 1;
		}
		else if(activetiles[(int)(block.z)][(int)(block.x + 0.5)] == 0 &&
			activetiles[(int)(block.z)][(int)(block.x - 0.5)] == 0){
			fallback = 1;
			SoundEngine->play2D("./Fall.mp3", false);
		}
		else if(activetiles[(int)(block.z)][(int)(block.x + 0.5)] == 0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallright = 1;
		}
		else if(activetiles[(int)(block.z)][(int)(block.x - 0.5)] == 0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallleft = 1;
		}
	}
	else if(blockstate == 2){
		block.anglez = 90.0;
		block.z += 1.5;
		block.y = 1.0;
		blockstate = 0;
		if(block.z > 10.0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallback = 1;
		}
		else if(activetiles[(int)block.z][(int)(block.x)] == 0){
			SoundEngine->play2D("./Fall.mp3", false);
			fallback = 1;
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 5){
			fallback = 1;
			levelover = 1;
		}
		else if(tilemap[(int)block.z][(int)(block.x)] == 2){
			SoundEngine->play2D("./Fall.mp3", false);
			fallback = 1;
			activetiles[(int)block.z][(int)(block.x)] = 0;
		}	
		else if(tilemap[(int)block.z][(int)(block.x)] == 4){
			activetiles[(int)block.z][(int)(block.x)] *= -1;
			if(curlevel == 1){
				activetiles[5][12] = 1 - activetiles[5][12];
				activetiles[6][12] = 1 - activetiles[6][12];
				activetiles[5][13] = 1 - activetiles[5][13];
			}
			else if(curlevel == 2){
				activetiles[6][8] = 1 - activetiles[6][8];
				activetiles[7][8] = 1 - activetiles[7][8];
			}
			else if(curlevel == 3){
				activetiles[1][5] = 1 - activetiles[1][5];
				activetiles[2][5] = 1 - activetiles[2][5];	
			}
		}
	}
	block.active = 1;
}
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
	 // Function is called first on GLFW_PRESS.
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	if (action == GLFW_RELEASE) {
		switch (key) {
			case GLFW_KEY_1:
			camera_view = 1;
			r = 300.0;
			camera_horizontal_angle = -10.0;
			camera_vertical_angle = 50.0;
			eyex = eyey = eyez = 0;
			tarx = tary = tarz = 0;
			up_horizontal_angle = camera_horizontal_angle;
			up_vertical_angle = camera_vertical_angle;
			break;
			case GLFW_KEY_2:
			camera_view = 2;
			r = 300.0;
			camera_horizontal_angle = 0;
			camera_vertical_angle = 90.0;
			eyex = eyey = eyez = 0;
			tarx = tary = tarz = 0;
			up_horizontal_angle = camera_horizontal_angle;
			up_vertical_angle = camera_vertical_angle;
			break;
			case GLFW_KEY_3:
			camera_view = 3;
			r = 0.0;
			eyex = (block.x - 7.0) * tileside;
			eyez = (block.z - 5.0) * tileside;
			eyey = (block.y + 2) * tileside;
			tarx = eyex + 100.0;
			tary = eyey - 50.0;
			tarz = eyez; 
			up_vertical_angle = 0.0;
			break;
			case GLFW_KEY_4:
			camera_view = 4;
			r = 300.0;
			camera_horizontal_angle = -10.0;
			camera_vertical_angle = 50.0;
			eyex = eyey = eyez = 0;
			tarx = tary = tarz = 0;
			up_horizontal_angle = camera_horizontal_angle;
			up_vertical_angle = camera_vertical_angle;
			break;
			case GLFW_KEY_5:
			camera_view = 5;
			r = 0.0;
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
			
			up_vertical_angle = 0.0;
			break;
			case GLFW_KEY_UP:
			if(block.active){
				curdir = 0;
				block.active = 0;
				movefront = 1;
			}
			break;
			case GLFW_KEY_DOWN:
			if(block.active){
				curdir = 3;
				block.active = 0;
				moveback = 1;
			}
			break;
			case GLFW_KEY_RIGHT:
			if(block.active){
				curdir = 2;
				block.active = 0;
				moveright = 1;
			}
			break;
			case GLFW_KEY_LEFT:
			if(block.active){
				curdir = 1;
				block.active = 0;
				moveleft = 1;
			}
			break;
			default:
			break;
		}
	}
	else if (action == GLFW_PRESS) {
		switch (key) {
			case GLFW_KEY_ESCAPE:
			break;
			default:
			break;
		}
	}
}

/* Executed for character input (like in text boxes) */
void keyboardChar (GLFWwindow* window, unsigned int key)
{
	switch (key) {
		case 'Q':
		case 'q':
		break;
		default:
		break;
	}
}

void mousescroll(GLFWwindow* window, double dx, double dy)
{
	if(camera_view == 4){
		if(dy > 0 && r < 400.0)
		r += 10.0;
		
		else if (dy < 0)
		r -= 10.0;
	}
}
/* Executed when a mouse button is pressed/released */
void mouseClicked(GLFWwindow* window)
{
	leftclicked = 1;
	glfwGetCursorPos(window, &curmousex, &curmousey);
	curmousex -= 400.0;
	curmousey = 300.0 - curmousey;
}
void mouseReleased(GLFWwindow* window)
{
	leftclicked = 0;
}
void mouseButton (GLFWwindow* window, int button, int action, int mods)
{
	switch (button) {
		case GLFW_MOUSE_BUTTON_LEFT:
		if (action == GLFW_PRESS){
			mouseClicked(window);
		}
		if (action == GLFW_RELEASE){
			mouseReleased(window);
		}
		break;
		case GLFW_MOUSE_BUTTON_RIGHT:
		if (action == GLFW_PRESS){
		}
		if (action == GLFW_RELEASE){
		}
		break;
		default:
		break;
	}
}