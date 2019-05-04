
#include "gui.hpp"


bool init(){

	//Initialization flag
	bool success = true;

	//Start SDL _________________________________________________________
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		std::cout << "SDL 1# initializing error\n" << SDL_GetError() << std::endl;
		success = false; return success;
	}
	else {
		//Create window
		win = SDL_CreateWindow(TITLE, WIDTH_POS, HEIGHT_POS, WIDTH, HEIGHT, 0);

		if (win == NULL) {
			std::cout << "SDL 2# creating windows error\n" << SDL_GetError() << std::endl;
			success = false;
		}
	}

	node.h = NODE_SIZE;
	node.w = NODE_SIZE;
	node.x = 0;
	node.y = HEIGHT/2;

	return success;
}

/*
void close(){

	//Destroy texture;
	SDL_DestroyTexture(node_texture);
	node_texture = NULL;

	//Destroy renderer
	SDL_DestroyRenderer(rend);
	rend = NULL;

	//Deallocate surface
	SDL_FreeSurface(node_surface);
	node_surface = NULL;

	//Destroy window
	SDL_DestroyWindow(win);
	win = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
*/

bool createRenderer() {
	bool success = true;

	// create a renderer: setup graphic harware
	Uint32 render_flag = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	rend = SDL_CreateRenderer(win, -1, render_flag); //associa questo renderer a win
	if (!rend) {
		std::cout << "SDL 3a# create robot renderer error\n" << SDL_GetError();
		success = false;
	}

	SDL_SetRenderDrawColor(rend, 29, 152, 149, 255);
	SDL_RenderClear(rend);
	return success;
}

bool createTexture(SDL_Renderer *rend, SDL_Surface *surf) {
	bool success = true;

	//load image data into the graphic hardware's memory
	node_texture = SDL_CreateTextureFromSurface(rend, surf);

	if (!node_texture) {
		std::cout << "SDL 5# texture creation error\n" << SDL_GetError() << IMG_GetError();
		success = false;
	}

	return success;
}

bool drawLinkedList(ListHead* head, nodeColor color){
	int dist = WIDTH/head->size;
	SDL_Texture* node_texture = NULL;
	SDL_Rect aux_rect = node;

	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, background_texture, NULL, NULL);
	for (int i=0; i<head->size; i++) {	
		switch (color){
			case RED : node_texture = red_texture;
			case GREEN : node_texture = green_texture;
			case GREY : node_texture = grey_texture;
			default : 
				printf("Error in drawNode(): unknown color.");
				return false;
		}
		aux_rect.x = dist*(i+1);
		SDL_RenderCopy(rend, node_texture, NULL, &aux_rect);
	}
	SDL_RenderPresent(rend);
    return true;
}
