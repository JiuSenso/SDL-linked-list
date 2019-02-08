/*concept: draw a linked list with SDL.
Implement insertItem(), detachItem(), and other functions
with a simple gui.
*/

#include "gui.hpp"
#include "linked_list.h"

bool running;

int main(int argc, char *argv[]) {

    // create window
	if (!init()) {
		std::cout << "Init() Error." << std::endl;
		close();
	}

	// create renderer
	if (!createRenderer()) {
		std::cout << "createRender() Error." << std::endl;
		close();
	}

    // create nodes and background surfaces
	red_surface = SDL_GetWindowSurface(win);
	green_surface = SDL_GetWindowSurface(win);
	grey_surface = SDL_GetWindowSurface(win);
    background_surface = SDL_GetWindowSurface(win);

	// load nodes and background media
	red_surface = IMG_Load(RED_NODE_PATH);
	if (red_surface == NULL) {
		std::cout << "SDL 4a# red_surface loading error\n" << SDL_GetError() << IMG_GetError();
		return 1;
	}

	green_surface = IMG_Load(GREEN_NODE_PATH);
	if (green_surface == NULL) {
		std::cout << "SDL 4a# green_surface loading error\n" << SDL_GetError() << IMG_GetError();
		return 1;
	}

	grey_surface = IMG_Load(GREY_NODE_PATH);
	if (grey_surface == NULL) {
		std::cout << "SDL 4a# grey_surface loading error\n" << SDL_GetError() << IMG_GetError();
		return 1;
	}

	background_surface = IMG_Load(BACKGROUND_PATH);
	if (background_surface == NULL) {
		std::cout << "SDL 4a# background_surface loading error\n" << SDL_GetError() << IMG_GetError();
		return 1;
	}

	// create node and background textdure
    // ( fix: use the createTexture() in gui.cpp to do this )
	red_texture = SDL_CreateTextureFromSurface(rend, red_surface);
	green_texture = SDL_CreateTextureFromSurface(rend, green_surface);
	grey_texture = SDL_CreateTextureFromSurface(rend, grey_surface);
	background_texture = SDL_CreateTextureFromSurface(rend, background_surface);


	// create 5 nodes list
  	ListHead head;
 	List_init(&head);
  	for (int i=0; i<5; ++i){
    	IntListItem* new_element= (IntListItem*)
      	malloc(sizeof(IntListItem));
    	if (! new_element) {
      		printf("out of memory\n");
      		break;
    	}
    	new_element->list.prev=0;
    	new_element->list.next=0;
    	new_element->info=i;
    	ListItem* result = List_insert(&head, head.last, (ListItem*)new_element);
    	assert(result);
 	}


    // draw linked list nodes
	drawLinkedList(head, RED);


	running = true;
	// main loop

	
}
