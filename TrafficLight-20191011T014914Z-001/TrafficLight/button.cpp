#include<stdio.h>
#include<stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "main.h"
#include "roadled.h"

#define Button_on     0
#define Button_off    1


int button_state = Button_off;
SDL_Event e;


#if 0
const int BUTTON_WIDTH = 100;
const int BUTTON_HEIGHT = 100;
const int TOTAL_BUTTONS = 4;


enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};



SDL_Rect gSpriteClips;
LButton gButtons;
LTexture gButtonSpriteSheetTexture;




bool loadMedia1()
{
	//Loading success flag
	bool success = true;

	//Load sprites
	if( !loadMedia( "../picture/button_off.png" ) )
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
	else
	{
		//Set sprites
            gSpriteClips.x = 350;
			gSpriteClips.y = 150;
			gSpriteClips.w = 100;
			gSpriteClips.h = 100;

            gButtons.setPosition( 540, 380 );

	}

	return success;
}

bool loadMedia2()
{
	//Loading success flag
	bool success = true;

	//Load sprites
	if( !loadMedia( "../picture/button_on.png" ) )
	{
		printf( "Failed to load button sprite texture!\n" );
		success = false;
	}
	else
	{

            gSpriteClips.x = 350;
			gSpriteClips.y = 150;
			gSpriteClips.w = 100;
			gSpriteClips.h = 100;

            gButtons.setPosition( 540, 380 );

	}

	return success;
}


int getbutton(void)
{
	while( SDL_PollEvent( &e ) != 0 )
	{

    if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState( &x, &y );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}

		//Mouse is outside button
		if( !inside )
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch( e.type )
			{
				case SDL_MOUSEMOTION:
			//	mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

				case SDL_MOUSEBUTTONDOWN:
			//	mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                printf("BUTTON_SPRITE_MOUSE_OVER_MOTION");
                loadMedia2();
				break;

				case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                loadMedia1();
				break;
			}
		}
	}
#endif

#if 0
int getbutton(void)
{
    while( SDL_PollEvent( &e ) != 0 )
    {
        if(e.type == SDL_QUIT){
			update_quit_state(true);
		}
		else if(e.type == SDL_KEYDOWN)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_UP:
					button_state = Button_on;
				break;
				case SDLK_DOWN:
					button_state = Button_off;
				break;
				default:
				break;
			}
		}


	}
	return button_state;
}

#endif

#if 1

#define mPositionx 540
#define mPositiony 380
#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 100



int getbutton(void)
{
    while( SDL_PollEvent( &e ) != 0 )
    {
        if(e.type == SDL_QUIT){
			update_quit_state(true);
		}
		else if(e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
		{
    		int x, y;
            SDL_GetMouseState( &x, &y );

            //Check if mouse is in button
            bool inside = true;

            //Mouse is left of the button
            if( x < mPositionx )
            {
                inside = false;
            }
            //Mouse is right of the button
            else if( x > mPositionx + BUTTON_WIDTH )
            {
                inside = false;
            }
            //Mouse above the button
            else if( y < mPositiony )
            {
                inside = false;
            }
            //Mouse below the button
            else if( y > mPositiony + BUTTON_HEIGHT )
            {
                inside = false;
            }

            //Mouse is outside button
            if( !inside )
            {

            }
            //Mouse is inside button
            else
            {
    			switch(e.type)
    			{
    				case SDL_MOUSEMOTION:

                    break;

                    case SDL_MOUSEBUTTONDOWN:
                       //
                    loadMediaB("../picture/button_on.png");
                    button_state = Button_on;
                    break;

                    case SDL_MOUSEBUTTONUP:
                        //
                    loadMediaB("../picture/button_off.png");
                    button_state = Button_off;
                    break;
			}
		}
	}
        }
	return button_state;
}
#endif

