#include "common.h"

#include "draw.h"

extern App app;

void prepareScene(void)
{
	SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_BLEND);

	SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0);
	SDL_RenderClear(app.renderer);

	
	
	
	

	SDL_SetRenderDrawColor(app.renderer, 0x00, 0xFF, 0x00, 64);
	//Vertical lines
	for (int i = 0; i < SCREEN_WIDTH; i += gridSize)
	{
		SDL_RenderDrawLine(app.renderer, i, 0, i, SCREEN_HEIGHT);
	}

	//Horizontal lines
	for (int i = 0; i < SCREEN_HEIGHT; i += gridSize)
	{
		SDL_RenderDrawLine(app.renderer, 0, i, SCREEN_WIDTH, i);
	}




	


}

void presentScene(void)
{
	SDL_RenderPresent(app.renderer);
}
