#include "GL.h"


GLuint programID;
glm::mat4 VP;
glm::mat4 MVP;
GLMatrices Matrices;
GLint model;
static void error_callback(int error, const char* description)
{
	//fprintf(stderr, "Error: %s\n", description);
}

void quit(GLFWwindow *window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
//    exit(EXIT_SUCCESS);
}
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path) {

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if(VertexShaderStream.is_open())
	{
		std::string Line = "";
		while(getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if(FragmentShaderStream.is_open()){
		std::string Line = "";
		while(getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("\n\n\n\nCompiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> VertexShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);

	// Link the program
	fprintf(stdout, "Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) );
	glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
	fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}
GLFWwindow* initGLFW (int width, int height)
{
		GLFWwindow* window; // window desciptor/handle

		glfwSetErrorCallback(error_callback);
		if (!glfwInit()) {
//        exit(EXIT_FAILURE);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(width, height, "Bloxorz", NULL, NULL);

		if (!window) {
			glfwTerminate();
//        exit(EXIT_FAILURE);
		}

		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
		glfwSwapInterval( 1 );

		/* --- register callbacks with GLFW --- */

		/* Register function to handle window resizes */
		/* With Retina display on Mac OS X GLFW's FramebufferSize
		 is different from WindowSize */
		glfwSetFramebufferSizeCallback(window, reshapeWindow);
		glfwSetWindowSizeCallback(window, reshapeWindow);

		/* Register function to handle window close */
		glfwSetWindowCloseCallback(window, quit);

		/* Register function to handle keyboard input */
		glfwSetKeyCallback(window, keyboard);      // general keyboard input
		glfwSetCharCallback(window, keyboardChar);  // simpler specific character handling

		/* Register function to handle mouse click */
		glfwSetMouseButtonCallback(window, mouseButton);  // mouse button clicks
		glfwSetScrollCallback(window, mousescroll);
		return window;
	}

void initGL (GLFWwindow* window, int width, int height)
{
	//Initialize objects
	initObjects();
	// Create and compile our GLSL program from the shaders
	programID = LoadShaders( "Sample_GL.vert", "Sample_GL.frag" );
	// Get a handle for our "MVP" uniform
	model = glGetUniformLocation(programID, "model");
	Matrices.MatrixID = glGetUniformLocation(programID, "MVP");
	GLint lightPosLoc1 = glGetUniformLocation(programID, "lightPos1");
	glUniform3f(lightPosLoc1, 0.0, 720.0, .0);
	GLint lightPosLoc2 = glGetUniformLocation(programID, "lightPos2");
	glUniform3f(lightPosLoc2, 0.0, 700.0, 0.0);
	//glUniform3f(lightPosLoc2, 0.0, 0.0, 0.0);

	reshapeWindow (window, width, height);
		// Background color of the scene
	glClearColor (1.0f, 1.0f, 1.0f, 0.0f); // R, G, B, A
	glClearDepth (1.0f);

	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LEQUAL);

	cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
	cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
	cout << "VERSION: " << glGetString(GL_VERSION) << endl;
	cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}
void reshapeWindow (GLFWwindow* window, int width, int height)
{
	int fbwidth = width, fbheight = height;
	/* With Retina display on Mac OS X, GLFW's FramebufferSize
	 is different from WindowSize */
	glfwGetFramebufferSize(window, &fbwidth, &fbheight);

	GLfloat fov = 20.0f;

// sets the viewport of openGL renderer
	glViewport (0, 0, (GLsizei) fbwidth, (GLsizei) fbheight);

// set the projection matrix as perspective
	//glMatrixMode (GL_PROJECTION);
	//glLoadIdentity ();
	//gluPerspective (fov, (GLfloat) fbwidth / (GLfloat) fbheight, 0.1, 500.0); 
// Store the projection matrix in a variable for future use
	// Perspective projection for 3D views
	Matrices.projection = glm::perspective (fov, (GLfloat) fbwidth / (GLfloat) fbheight, 0.1f, 500.0f);

	// Ortho projection for 2D views
	//Matrices.projection = glm::ortho(-400.0f, 400.0f, -300.0f, 300.0f, 0.1f, 500.0f);
}