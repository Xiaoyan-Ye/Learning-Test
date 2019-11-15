#include<stdio.h>
#include<stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "main.h"
#include "roadled.h"


#define CountdownWide 170;
#define CountdownHight 140;


extern SDL_Renderer* gRenderer;
extern SDL_Texture* gTexture;
extern SDL_Rect renderQuad;


SDL_Rect gCountdownClips[10];  //[10][10]
SDL_Rect gLightClips[5];

SDL_Rect CountRenderQuad = {0,400,440,200};
SDL_Rect CountRenderQuad1 = {0,0,180,200};
SDL_Rect CountRenderQuad2 = {180,0,180,200};


void SetgCountdownClips()
{
    gCountdownClips[0].x = 80;
    gCountdownClips[0].y = 0;
    gCountdownClips[0].w = CountdownWide;
    gCountdownClips[0].h = CountdownHight;

    gCountdownClips[1].x = 260;
    gCountdownClips[1].y = 0;
    gCountdownClips[1].w = CountdownWide;
    gCountdownClips[1].h = CountdownHight;

    gCountdownClips[2].x = 80;
    gCountdownClips[2].y = 220;
    gCountdownClips[2].w = CountdownWide;
    gCountdownClips[2].h = CountdownHight;

    gCountdownClips[3].x = 260;
    gCountdownClips[3].y = 220;
    gCountdownClips[3].w = CountdownWide;
    gCountdownClips[3].h = CountdownHight;

    gCountdownClips[4].x = 80;
    gCountdownClips[4].y = 440;
    gCountdownClips[4].w = CountdownWide;
    gCountdownClips[4].h = CountdownHight;

    gCountdownClips[5].x = 260;
    gCountdownClips[5].y = 440;
    gCountdownClips[5].w = CountdownWide;
    gCountdownClips[5].h = CountdownHight;

    gCountdownClips[6].x = 80;
    gCountdownClips[6].y = 660;
    gCountdownClips[6].w = CountdownWide;
    gCountdownClips[6].h = CountdownHight;

    gCountdownClips[7].x = 260;
    gCountdownClips[7].y = 660;
    gCountdownClips[7].w = CountdownWide;
    gCountdownClips[7].h = CountdownHight;

    gCountdownClips[8].x = 80;
    gCountdownClips[8].y = 880;
    gCountdownClips[8].w = CountdownWide;
    gCountdownClips[8].h = CountdownHight;

    gCountdownClips[9].x = 260;
    gCountdownClips[9].y = 880;
    gCountdownClips[9].w = CountdownWide;
    gCountdownClips[9].h = CountdownHight;


}


#if 0
SDL_Rect gCountdownClips[10][10] = {
    {80,0,180,200},
    {260,0,180,200},
    {80,200,180,200},
    {260,200,180,200},
    {80,400,180,200},
    {260,400,180,200},
    {80,600,180,200},
    {260,600,180,200},
    {80,800,180,200},
    {260,800,180,200},
        {80,0,180,200},
        {260,0,180,200},
        {80,200,180,200},
        {260,200,180,200},
        {80,400,180,200},
        {260,400,180,200},
        {80,600,180,200},
        {260,600,180,200},
        {80,800,180,200},
        {260,800,180,200}
};

#endif

//gCountdownClips[0][0] = {80,0,180,200};


SDL_Renderer* gRendererA = NULL;
SDL_Texture* gTextureA = NULL;


SDL_Texture* loadTextureA( std::string path )
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


bool loadMediaA()
{
	//Loading success flag
	bool success = true;


	//Load texture
	gTexture = loadTextureA( "../picture/countdown.png" );
	if( gTexture == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = false;
	}
	return success;
}



bool show_countdown(SDL_Rect clip0, SDL_Rect clip1)
{
    bool sucess = true;

    loadMediaA();

    SDL_RenderSetViewport( gRenderer, &CountRenderQuad );
    SDL_RenderCopy( gRenderer, gTexture, &clip0, &CountRenderQuad1 );
    SDL_RenderCopy( gRenderer, gTexture, &clip1, &CountRenderQuad2 );
    SDL_RenderPresent( gRenderer );

    return sucess;
}



