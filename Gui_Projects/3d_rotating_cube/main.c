#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

const float window_width = 640;
const float window_height = 400;
const float rotation_speed = 1.5;


void drawCube(float angle){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(angle, 1.0f, 1.0f, 1.0f);
	
	glBegin(GL_QUADS);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1, -1, 1);
	glVertex3f( 1, -1, 1);
	glVertex3f( 1,  1, 1);
	glVertex3f(-1,  1, 1);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1,  1, -1);
	glVertex3f( 1,  1, -1);
	glVertex3f( 1, -1, -1);
	
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1,  1, 1);
	glVertex3f(-1,  1, -1);
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f( 1, -1,-1);
	glVertex3f( 1,  1,-1);
	glVertex3f( 1,  1, 1);
	glVertex3f( 1, -1, 1);
	
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-1,  1,-1);
	glVertex3f(-1,  1, 1);
	glVertex3f( 1,  1, 1);
	glVertex3f( 1,  1,-1);
	
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-1, -1,-1);
	glVertex3f( 1, -1,-1);
	glVertex3f( 1, -1, 1);
	glVertex3f(-1, -1, 1);
	
	glEnd();
	glFlush();
	
}

int main(){
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("3d roating cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(window);
	
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, window_width / window_height , 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	
	float angle = 0;
	int running = 1;
	SDL_Event e;
	
	while(running){
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT){
				running = 0;
			}
			
		}
		
		drawCube(angle);
		SDL_GL_SwapWindow(window);
		angle += rotation_speed;
		SDL_Delay(16);
	}
	
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
