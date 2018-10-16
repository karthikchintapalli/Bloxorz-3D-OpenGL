all: blocks

blocks: main.cpp objects.cpp inputhandle.cpp GL.cpp glad.c
	g++ -o blocks main.cpp objects.cpp inputhandle.cpp GL.cpp glad.c -framework OpenGL -lglfw -lirrklang -L./ -I./

clean:
	rm blocks
