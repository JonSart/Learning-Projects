//Jonathan Simpson. 8/8/19. Create a set of grid tiles. Each grid tile needs to know if it has a neighbor to each of its sides, or if it does NOT have a neighbor to each side.
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

class GridTile
{
public:
	void SetDir(short int n, short int s, short int e, short int w);
	void SayDirections();

private:
	short int north = 0;	//0 = NO neighbor or connection in this direction.
	short int south = 0;	//1 = Has a connection or neighbor in this direction.
	short int east = 0;		//May want to add different types of connections later on. Hence, short int instead of bool 
	short int west = 0;

};

void GridTile::SetDir(short int n, short int s, short int e, short int w)
{
	north = n;
	south = s;
	east = e;
	west = w;
}

void GridTile::SayDirections()
{
	if (north == 1)
		cout << "N";
	if (south == 1)
		cout << "S";
	if (east == 1)
		cout << "E";
	if (west == 1)
		cout << "W";
	cout << " ";
}

class Board
{
public:
	Board();
	void Testing();

private:
	vector<vector<GridTile>> board;
	const int colSize = 12;
	const int rows = 7;

};

Board::Board()
{
	board.resize(rows, vector<GridTile>(colSize));			//Size our vector appropriately.

	for (int i = 0; i < rows; i++)							//Set the direction connections for each grid tile. 
	{
		
		for (int x = 0; x < colSize; x++)
		{
			if (i == 0)										//Top row
			{
				if (x == 0)								
					board[i][x].SetDir(0, 1, 1, 0);		//Top left corner. (South and east connections)
				if (x == colSize - 1)
					board[i][x].SetDir(0, 1, 0, 1);		//Top right corner (South & West.)
				if (x > 0 && x < colSize - 1)			
					board[i][x].SetDir(0, 1, 1, 1);		//Top middle tiles. (South, east, and west.)
			}

			if (i > 0 && i < rows - 1)						//Middle rows
			{
				if (x == 0)								//First tile in each middle row (North, south, and east. No west)
					board[i][x].SetDir(1, 1, 1, 0);			
				if (x == colSize - 1)					//Last tile in each middle row (North, south, and west. No east)
					board[i][x].SetDir(1, 1, 0, 1);
				if (x > 0 && x < colSize - 1)			//The middle tiles in each middle row (North, south, east, and west)
					board[i][x].SetDir(1, 1, 1, 1);
			}

			if (i == rows - 1)								//Bottom row
			{
				if (x == 0)								//Bottom left. (North, East)
					board[i][x].SetDir(1, 0, 1, 0);
				if (x == colSize - 1)					//Bottom right. (North, West)
					board[i][x].SetDir(1, 0, 0, 1);
				if (x > 0 && x < colSize - 1)			//Middle bottom. (North, East, West)
					board[i][x].SetDir(1, 0, 1, 1);
			}
			
		}
	}

}

void Board::Testing()	//Test our grid.
{
	for (int i = 0; i < rows; i++)
	{
		for (int x = 0; x < colSize; x++)
		{
			board[i][x].SayDirections();
			if (x == colSize - 1)
				cout << " \n";
		}
	}
}

int main()
{
	Board theBoard;
	theBoard.Testing();
}


