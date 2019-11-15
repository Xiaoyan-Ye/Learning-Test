#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "led.h"
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 600;

//Starts up SDL and creates window

SDL_Rect renderQuad;

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
//SDL_Surface* gScreenSurface = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gTexture = NULL;


//Current displayed PNG image


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
	    SetgCountdownClips();
	    //Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		//Create window
		gWindow = SDL_CreateWindow( "Traffic Light", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{

        //Create renderer for window
             gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
             if( gRenderer == NULL )
             {
                 printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                 success = false;
             }
             else
             {
                 //Initialize renderer color
                 SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    			//Initialize PNG loading
    			int imgFlags = IMG_INIT_PNG;
    			if( !( IMG_Init( imgFlags ) & imgFlags ) )
    			{
    				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
    				success = false;
    			}
                }
			/*else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface( gWindow );
			}*/
		}
	}

	return success;
}

#if 0
bool loadMedia( std::string path )
{
	SDL_Surface* gPNGSurface = NULL;
	//Loading success flag
	bool success = true;

	//Load PNG surface
	gPNGSurface = loadSurface( path.c_str() );
	if( gPNGSurface == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}

	SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );

	//Update the surface
	SDL_UpdateWindowSurface( gWindow );

	SDL_FreeSurface( gPNGSurface );
	gPNGSurface = NULL;
	return success;
}


SDL_Point mPosition;
SDL_Rect renderQuad = { 540, 380, 100, 100 };
#endif



SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
IMG_GetError() );
	}
	else
	{
	    renderQuad = { 0, 0, loadedSurface->w, loadedSurface->h };
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(),
SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

bool loadMedia(std::string path)
{
	//Loading success flag
	bool success = true;

	//Load texture
	gTexture = loadTexture( path.c_str() );
	if( gTexture == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = false;
	}

    //Top left corner viewport
				SDL_Rect topLeftViewport;
				topLeftViewport.x = 0;
				topLeftViewport.y = 0;
				topLeftViewport.w = SCREEN_WIDTH;
				topLeftViewport.h = 300;
				SDL_RenderSetViewport( gRenderer, &topLeftViewport );


                   SDL_Rect gSpriteClips;
                   gSpriteClips.x = 0;
                gSpriteClips.y = 95;
                gSpriteClips.w = 1000;
                gSpriteClips.h = 1000;

				//Render texture to screen
				SDL_RenderCopy( gRenderer, gTexture, &gSpriteClips,&renderQuad );
                //Update screen
				SDL_RenderPresent( gRenderer );

	//Nothing to load
	return success;
}



bool loadMediaB(std::string path)
{
	//Loading success flag
	bool success = true;


	//Load texture
	gTexture = loadTexture( path.c_str() );
	if( gTexture == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = false;
	}

    //Top left corner viewport
				SDL_Rect topLeftViewport;
				topLeftViewport.x = 0;
				topLeftViewport.y = 300;
				topLeftViewport.w = SCREEN_WIDTH;
				topLeftViewport.h = 180;
				SDL_RenderSetViewport( gRenderer, &topLeftViewport );


               // SDL_RenderCopyEx( gRenderer, gTexture, &topLeftViewport, &renderQuad,
               // NULL, NULL,SDL_FLIP_NONE );
               SDL_Rect gSpriteClips;
               gSpriteClips.x = 0;
			gSpriteClips.y = 150;
			gSpriteClips.w = 640;
			gSpriteClips.h = 340;

				//Render texture to screen
				SDL_RenderCopy( gRenderer, gTexture, &gSpriteClips,&renderQuad );
                //Update screen
				SDL_RenderPresent( gRenderer );

	//Nothing to load
	return success;
}

#if 0
bool loadMedia( std::string path )
{
	SDL_Surface* gPNGSurface = NULL;
	//Loading success flag
	bool success = true;

	//Load PNG surface
	gPNGSurface = loadSurface( path.c_str() );
	if( gPNGSurface == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}

	SDL_BlitSurface( gPNGSurface, NULL, gScreenSurface, NULL );

	//Update the surface
	SDL_UpdateWindowSurface( gWindow );

	SDL_FreeSurface( gPNGSurface );
	gPNGSurface = NULL;
	return success;
}

#endif

void close()
{
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

#if 0
SDL_Surface* loadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

#endif

