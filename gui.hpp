#pragma once 
#include <stdio.h>
#include <iostream>
#include "linked_list.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"

//::::: D A T A ::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#define     WIDTH       1024
#define     HEIGHT      WIDTH/4*3
#define     NODE_SIZE   64
#define     MAX_NODES   WIDTH/NODE_SIZE
#define     WIDTH_POS   WIDTH/2
#define     HEIGHT_POS  HEIGHT/2

const char* TITLE = "Amazing Linked List";	
//node path
const char* RED_NODE_PATH =	"/home/jius/Desktop/SDL-linked-list/bmp/red_node.bmp";
const char* GREEN_NODE_PATH ="/home/jius/Desktop/SDL-linked-list/bmp/green_node.bmp";
const char* GREY_NODE_PATH ="/home/jius/Desktop/SDL-linked-list/bmp/grey_node.bmp";
const char* ORANGE_NODE_PATH ="/home/jius/Desktop/SDL-linked-list/bmp/orange_node.bmp";
const char* PURPLE_NODE_PATH ="/home/jius/Desktop/project-1/bmp/purple_node.bmp";
const char* BACKGROUND_PATH ="/home/jius/Desktop/SDL-linked-list/bmp/background_node.bmp";

SDL_Renderer *rend = NULL;
SDL_Window *win = NULL;

//node surfaces
SDL_Surface *red_surface = NULL;
SDL_Surface *green_surface = NULL;
SDL_Surface *grey_surface = NULL;
SDL_Surface *orange_surface = NULL;
SDL_Surface *purple_surface = NULL;
SDL_Surface *background_surface = NULL;
SDL_Surface *node_surface = NULL;   //generic

//node texture
SDL_Texture *red_texture = NULL;
SDL_Texture *green_texture = NULL;
SDL_Texture *grey_texture = NULL;
SDL_Texture *orange_texture = NULL;
SDL_Texture *purple_texture = NULL;
SDL_Texture *background_texture = NULL;
SDL_Texture *node_texture = NULL;    //generic

//Rect
SDL_Rect node, background;

enum nodeColor{
	RED,
	GREEN,
    GREY,
	ORANGE ,
	PURPLE,
};

//:::: F U N C T I O N S ::::::::::::::::::::::::::::::::::::::::::::::

bool init();
void close();
bool loadMedia(SDL_Surface *surf, const char *img_path);

bool createRenderer();
bool createTexture(SDL_Renderer *rend, SDL_Surface *surf);

bool drawNode(SDL_Rect node, nodeColor color);

