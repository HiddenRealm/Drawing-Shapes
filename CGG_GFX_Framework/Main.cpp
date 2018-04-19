#include <cmath>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "CGG_Main.h"



int main(int argc, char *argv[])
{
	// Variables for storing window dimensions
	int windowWidth = 640;
	int windowHeight = 480;

	// Call CGG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if( !CGG::Init( windowWidth, windowHeight ) )
	{
		// We must check if something went wrong
		// (this is very unlikely)
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGBA, numbers are from 0 to 255
	CGG::SetBackground( 0,0,0 );

	//Setting One time Coords
	int L_X = 15, L_Y = 10;
	int MS_X = 150, MS_Y = 100;
	int MC_X = 150, MC_Y = 130, MC_R = 25;
	int MSS_X = MS_X, MSS_Y = MS_Y;

	// Preparing a colour to draw
	srand(time(NULL));
	
	//Picking Colours
	//Line
	int L_red = 0;
	int L_green = 0;
	int L_blue = 250;
	//Square
	int S_red = rand() %255;
	int S_green = rand() %255;
	int S_blue = rand() %255;
	//3D Square
	int SS_red = rand() %255;
	int SS_green = rand() %255;
	int SS_blue = rand() %255;
	//Triangle
	int T_red = rand() %255;
	int T_green = rand() %255;
	int T_blue = rand() %255;
	//Circle
	int C_red = rand() %255;
	int C_green = rand() %255;
	int C_blue = rand() %255;
	//Elipse
	int E_red = rand() %255;
	int E_green = rand() %255;
	int E_blue = rand() %255;
	//Contorted Circle
	int MC_red = rand() %255;
	int MC_green = rand() %255;
	int MC_blue = rand() %255;


	//While Loop Start
	float timer = 0.0f;
	while(CGG::ProcessFrame())
	{
		timer += 1.0f / 60.0f;
		CGG::SetBackground( 0,0,0 );

		//Setting Coords that need to be reset
		int S_X = 15, S_Y = 70;
		int FS_X = 15, FS_Y = 280;
		int SS_X = 30, SS_Y = 265;
		int SL_BL_X = 15, SL_BL_Y = 330;
		int SL_BR_X = 65, SL_BR_Y = 330;
		int SL_TL_X = 15, SL_TL_Y = 280;
		int SL_TR_X = 65, SL_TR_Y = 280;
		float T_X = 40, T_Y = 130;
		int C_X = 0, C_Y = 0, C_H = 40, C_K = 220, C_R = 25;
		int E_X = 0, E_Y = 0, E_H = 1, E_K = 2, E_R = 25;
		
		//Moving Square Colours
		int MS_red = rand() %255;
		int MS_green = rand() %255;
		int MS_blue = rand() %255;

		//Drawing the Line
		for (int i = 0; i < 50; i++)
			{
				CGG::DrawPixel( L_X, L_Y, L_red, L_green, L_blue );
				L_X++;
				L_Y++;
				L_green = L_green + 5;
				L_blue = L_blue - 5;
			}
		L_X = 15;
		L_Y = 10;

		//Drawing the Square
		for (int j = 0; j < 50; j++)
			{
				for (int i = 0; i < 50; i++)
					{
						CGG::DrawPixel( S_X, S_Y, S_red, S_green, S_blue );
						S_Y++;
					}
				S_X++;
				S_Y = 70;
			}

		//Drawing the Triangle
		for (int i = 0; i < 35; i++)
			{
				CGG::DrawPixel( T_X, T_Y, T_red, T_green, T_blue );
				T_X = T_X + 1;
				T_Y = T_Y + 1.5;
			}
		for (int i = 0; i < 70; i++)
			{
				CGG::DrawPixel( T_X, T_Y, T_red, T_green, T_blue );
				T_X = T_X - 1;
			}
		for (int i = 0; i < 35; i++)
			{
				CGG::DrawPixel( T_X, T_Y, T_red, T_green, T_blue );
				T_X = T_X + 1;
				T_Y = T_Y - 1.5;
			}

		//Drawing the Circle
		for (int i = 0; i <= 360; i = i++)
			{
				C_X = C_H + C_R*cos(i);
				C_Y = C_K + C_R*sin(i);
				CGG::DrawPixel( C_X, C_Y, C_red, C_green, C_blue );
			}

		//Drawing the 3D Sqaure
		//First Square
		for (int i = 0; i < 50; i++)
			{
				CGG::DrawPixel( FS_X, FS_Y, SS_red, SS_green, SS_blue );
				CGG::DrawPixel( FS_X, FS_Y + 50, SS_red, SS_green, SS_blue );
				FS_X++;
			}
		for (int i = 0; i < 50; i++)
			{
				CGG::DrawPixel( FS_X, FS_Y, SS_red, SS_green, SS_blue );
				CGG::DrawPixel( FS_X - 50, FS_Y, SS_red, SS_green, SS_blue );
				FS_Y++;
			}

		//Second Square
		for (int i = 0; i < 50; i++)
			{
				CGG::DrawPixel( SS_X, SS_Y, SS_red, SS_green, SS_blue );
				CGG::DrawPixel( SS_X, SS_Y + 50, SS_red, SS_green, SS_blue );
				SS_X++;
			}
		for (int i = 0; i < 50; i++)
			{
				CGG::DrawPixel( SS_X, SS_Y, SS_red, SS_green, SS_blue );
				CGG::DrawPixel( SS_X - 50, SS_Y, SS_red, SS_green, SS_blue );
				SS_Y++;
			}

		//Lines Inbetween
		//Bottom Left Line
		for (int i = 0; i < 15; i++)
			{
				CGG::DrawPixel( SL_BL_X, SL_BL_Y, SS_red, SS_green, SS_blue );
				SL_BL_X++;
				SL_BL_Y--;
			}
		//Bottom Right Line
		for (int i = 0; i < 15; i++)
			{
				CGG::DrawPixel( SL_BR_X, SL_BR_Y, SS_red, SS_green, SS_blue );
				SL_BR_X++;
				SL_BR_Y--;
			}
		//Top Left Line
		for (int i = 0; i < 15; i++)
			{
				CGG::DrawPixel( SL_TL_X, SL_TL_Y, SS_red, SS_green, SS_blue );
				SL_TL_X++;
				SL_TL_Y--;
			}
		//Top Right Line
		for (int i = 0; i < 15; i++)
			{
				CGG::DrawPixel( SL_TR_X, SL_TR_Y, SS_red, SS_green, SS_blue );
				SL_TR_X++;
				SL_TR_Y--;
			}

		//Drawing the Elipse
		for (int i = 0; i <= 360; i = i++)
			{
				E_X = E_H * E_R*cos(i);
				E_Y = E_K * E_R*sin(i);
				CGG::DrawPixel( E_X + 45, E_Y + 390, E_red, E_green, E_blue );
			}

		//Drawing the Contorted Circle
		for (int i = 0; i <= 360; i = i++)
			{
				MC_X = MC_X + MC_R*cos(i);
				MC_Y = MC_Y + MC_R*sin(i);
				CGG::DrawPixel( MC_X + 130, MC_Y + 30, MC_red, MC_green, MC_blue );
			}

		//Drawing the Moved Square
		MSS_X = (windowWidth / 2) + (int)(sin(timer) * 100.0f);;
		MSS_Y = (windowHeight / 2) + (int)(sin(timer) * 100.0f);;

		for (int i = 0; i < 50; i++)
			{
				CGG::DrawPixel( MSS_X - 50, MSS_Y, MS_red, MS_green, MS_blue );
				CGG::DrawPixel( MSS_X - 50, MSS_Y + 50, MS_red, MS_green, MS_blue );
				MSS_X++;
			}
		MSS_X = MSS_X - 50;

		for (int i = 0; i < 50; i++)
			{
				CGG::DrawPixel( MSS_X, MSS_Y, MS_red, MS_green, MS_blue );
				CGG::DrawPixel( MSS_X - 50, MSS_Y, MS_red, MS_green, MS_blue );
				MSS_Y++;
			} 
		MSS_Y = MSS_Y - 50;
	}
}
