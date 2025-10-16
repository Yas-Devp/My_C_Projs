#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

int main(){
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* window = SDL_CreateWindow("rotating squre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	
	SDL_Texture* squareTex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 100, 100);
	SDL_SetRenderTarget(renderer, squareTex);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	
	SDL_SetRenderTarget(renderer, NULL);
	
	SDL_Rect dst = {270, 190, 100, 100};
	
	float angle = 0.0f;
	bool running = true;
	SDL_Event event;
	
	while(running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				running = false;
			}
		}
		
		angle -= 1.0f;
		if(angle <= -360.0f) angle = 0.0f;
		
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		
		SDL_RenderCopyEx(renderer, squareTex, NULL, &dst, angle, NULL, SDL_FLIP_NONE);
		
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	
	}
	
	SDL_DestroyTexture(squareTex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
