#include "common.h"

#include "draw.h"
#include "init.h"
#include "input.h"
#include "main.h"
#include "stage.h"


App app;

static void capFrameRate(long* then, float* remainder);

void initializeGrid(std::vector<std::vector<int>>& matrix)
{
    // glider guns
    matrix[5][1] = 1;
    matrix[5][2] = 1;
    matrix[6][1] = 1;
    matrix[6][2] = 1;

    matrix[3][13] = 1;
    matrix[3][14] = 1;
    matrix[4][12] = 1;
    matrix[4][16] = 1;
    matrix[5][11] = 1;
    matrix[5][17] = 1;
    matrix[6][11] = 1;
    matrix[6][15] = 1;
    matrix[6][17] = 1;
    matrix[6][18] = 1;
    matrix[7][11] = 1;
    matrix[7][17] = 1;
    matrix[8][12] = 1;
    matrix[8][16] = 1;
    matrix[9][13] = 1;
    matrix[9][14] = 1;

    matrix[1][25] = 1;
    matrix[2][23] = 1;
    matrix[2][25] = 1;
    matrix[3][21] = 1;
    matrix[3][22] = 1;
    matrix[4][21] = 1;
    matrix[4][22] = 1;
    matrix[5][21] = 1;
    matrix[5][22] = 1;
    matrix[6][23] = 1;
    matrix[6][25] = 1;
    matrix[7][25] = 1;

    matrix[3][35] = 1;
    matrix[3][36] = 1;
    matrix[4][35] = 1;
    matrix[4][36] = 1;
    

    /* pulsar
    matrix[2][4] = 1;
    matrix[2][5] = 1;
    matrix[2][6] = 1;
    matrix[2][10] = 1;
    matrix[2][11] = 1;
    matrix[2][12] = 1;

    matrix[4][2] = 1;
    matrix[4][7] = 1;
    matrix[4][9] = 1;
    matrix[4][14] = 1;

    matrix[5][2] = 1;
    matrix[5][7] = 1;
    matrix[5][9] = 1;
    matrix[5][14] = 1;

    matrix[6][2] = 1;
    matrix[6][7] = 1;
    matrix[6][9] = 1;
    matrix[6][14] = 1;

    matrix[7][4] = 1;
    matrix[7][5] = 1;
    matrix[7][6] = 1;
    matrix[7][10] = 1;
    matrix[7][11] = 1;
    matrix[7][12] = 1;

    matrix[9][4] = 1;
    matrix[9][5] = 1;
    matrix[9][6] = 1;
    matrix[9][10] = 1;
    matrix[9][11] = 1;
    matrix[9][12] = 1;

    matrix[10][2] = 1;
    matrix[10][7] = 1;
    matrix[10][9] = 1;
    matrix[10][14] = 1;

    matrix[11][2] = 1;
    matrix[11][7] = 1;
    matrix[11][9] = 1;
    matrix[11][14] = 1;

    matrix[12][2] = 1;
    matrix[12][7] = 1;
    matrix[12][9] = 1;
    matrix[12][14] = 1;

    matrix[14][4] = 1;
    matrix[14][5] = 1;
    matrix[14][6] = 1;
    matrix[14][10] = 1;
    matrix[14][11] = 1;
    matrix[14][12] = 1;

    */





}


int main(int argc, char* argv[])
{

	long  then;
	float remainder;


	memset(&app, 0, sizeof(App));

	initSDL();

	atexit(cleanup);

	int rows = 40;
	int cols = 70;

	std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
	initializeGrid(matrix);

	then = SDL_GetTicks();

	remainder = 0;

	while (1)
	{
		prepareScene();

		doInput();
		logic(matrix);

		drawCubes(matrix);

		presentScene();


		capFrameRate(&then, &remainder);
	}

	return 0;
}

static void capFrameRate(long* then, float* remainder)
{
	long wait, frameTime;

	wait = 100 + *remainder;

	*remainder -= (int)*remainder;

	frameTime = SDL_GetTicks() - *then;

	wait -= frameTime;

	if (wait < 1)
	{
		wait = 1;
	}

	SDL_Delay(wait);

	*remainder += 0.667;

	*then = SDL_GetTicks();
}
