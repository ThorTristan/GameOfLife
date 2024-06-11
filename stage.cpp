#include "common.h"

#include "draw.h"
#include "stage.h"

extern App app;


const int CELL_SIZE = SCREEN_HEIGHT / 20;


int countNeighbours(const std::vector<std::vector<int>>& matrix, int row, int col) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	int neighbour_counter = 0;

	int neighborDeltas[8][2] = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{ 0, -1},          { 0, 1},
		{ 1, -1}, { 1, 0}, { 1, 1}
	};

	for (int i = 0; i < 8; ++i) {
		int newRow = row + neighborDeltas[i][0];
		int newCol = col + neighborDeltas[i][1];

		// Check if the neighboring position is within the bounds of the matrix
		if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
			if (matrix[newRow][newCol] == 1) {
				neighbour_counter++;
			}
		}
	}

	return neighbour_counter;
}

void drawCubes(const std::vector<std::vector<int>>& matrix)
{
	int rows = matrix.size();
	int cols = matrix[0].size();

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (matrix[i][j] == 1) {
				SDL_Rect fillRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
				SDL_SetRenderDrawColor(app.renderer, 0x00, 0xFF, 0x00, 0xFF); // Green color
				SDL_RenderFillRect(app.renderer, &fillRect);
			}
		}
	}


}

void logic(std::vector<std::vector<int>>& matrix)
{
	int rows = matrix.size();
	int cols = matrix[0].size();


	std::vector<std::vector<int>> nextMatrix(rows, std::vector<int>(cols, 0));


	for (int i = 0; i < rows; ++ i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int neighbours = countNeighbours(matrix, i, j);

			if (matrix[i][j] == 1)
			{
				if (neighbours == 2 || neighbours == 3)
				{
					nextMatrix[i][j] = 1;
				}
				else
				{
					nextMatrix[i][j] = 0;
				}
			}
			else
			{
				if (neighbours == 3)
				{
					nextMatrix[i][j] = 1;
				}
				else
				{
					nextMatrix[i][j] = 0;
				}
			}

		}
	}

	matrix = nextMatrix;


}



