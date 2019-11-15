/*   2019/10/23 : Initial version, put an image on the screen
	2019/10/24: Add SDL_ConvertSurface function to Optimized Surface Loading and Soft Stretching



*/


#include<SDL.h>
#include<stdio.h>
#include<string>

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



bool init();

bool loadMedia();

void close();


SDL_Window* gwindow = NULL;

SDL_Surface* gscreenSurface = NULL;

SDL_Surface* gcurrentsurfaces = NULL;

SDL_Surface* gkeypresssurfaces[KEY_PRESS_SURFACE_TOTAL];



SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if(loadedSurface == NULL){
		printf("Unable to load image %s! SDL Error: %s\n",path.c_str(),SDL_GetError());
	}
	else{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gscreenSurface->format, 0);
		if(optimizedSurface == NULL){
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}



bool init()
{
	bool success = true;


	if(SDL_Init(SDL_INIT_VIDEO)<0){
		printf("SDL could not initialize SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else{
		gwindow = SDL_CreateWindow("Hello world!",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gwindow == NULL){
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());	
			success = false;
		}
		else{
			gscreenSurface = SDL_GetWindowSurface(gwindow);
			success = true;			
		}

	}

	return success;
}


bool loadMedia()
{
	bool success = true;

	gkeypresssurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("../picture/press.bmp");
	if(gkeypresssurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL){
		printf("Unable to load image! \n");
		success = false;
	}

	gkeypresssurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("../picture/up.bmp");
	if(gkeypresssurfaces[KEY_PRESS_SURFACE_UP] == NULL){
		printf("Unable to load image! \n");
		success = false;
	}

	gkeypresssurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("../picture/down.bmp");
	if(gkeypresssurfaces[KEY_PRESS_SURFACE_DOWN] == NULL){
		printf("Unable to load image! \n");
		success = false;
	}

	gkeypresssurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("../picture/left.bmp");
	if(gkeypresssurfaces[KEY_PRESS_SURFACE_LEFT] == NULL){
		printf("Unable to load image! \n");
		success = false;
	}

	gkeypresssurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("../picture/right.bmp");
	if(gkeypresssurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL){
		printf("Unable to load image! \n");
		success = false;
	}

	return success;
}

void close()
{
	SDL_FreeSurface(gcurrentsurfaces);
	gcurrentsurfaces = NULL;

	SDL_DestroyWindow(gwindow);
	gwindow = NULL;

	SDL_Quit();
}


	
int main(int argc, char* args[])
{
	if(!init()){
		printf("Failed to initialize!\n");
		
	}
	else{
		if(!loadMedia()){
			printf("Failed to load media!\n");
			
		}
		else{
			bool quit = false;

			SDL_Event e;

			gcurrentsurfaces = gkeypresssurfaces[KEY_PRESS_SURFACE_DEFAULT];
			while(!quit){
				while(SDL_PollEvent(&e)!=0){
					if(e.type == SDL_QUIT){
						quit = true;
					}
					else if(e.type == SDL_KEYDOWN){
						switch(e.key.keysym.sym){
							case SDLK_UP:
							gcurrentsurfaces = gkeypresssurfaces[KEY_PRESS_SURFACE_UP];
							break;

							case SDLK_DOWN:
							gcurrentsurfaces = gkeypresssurfaces[KEY_PRESS_SURFACE_DOWN];
							break;

							case SDLK_LEFT:
							gcurrentsurfaces = gkeypresssurfaces[KEY_PRESS_SURFACE_LEFT];
							break;

							case SDLK_RIGHT:
							gcurrentsurfaces = gkeypresssurfaces[KEY_PRESS_SURFACE_RIGHT];
							break;

							default:
							gcurrentsurfaces = gkeypresssurfaces[KEY_PRESS_SURFACE_DEFAULT];
							break;						
						}
					}
						
				}

				
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;
				SDL_BlitSurface(gcurrentsurfaces, NULL, gscreenSurface, &stretchRect);
				SDL_UpdateWindowSurface(gwindow);
			}
			
		}
	}
	close();
	return 0;
}








