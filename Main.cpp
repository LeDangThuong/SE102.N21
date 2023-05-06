#include <iostream>
#include <SDL.h>
int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 600, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(30000);
	return 0;
}
