#include <iostream>
#include <vector>
#include <queue>
#include <string>

int R = 0;
int C = 0;
std::vector<std::vector<int>> Maze;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
	std::cin >> R;
	std::cin >> C;
	Maze.resize(R);

	for (int i = 0; i < R; ++i)
	{
		Maze[i].resize(C);

		std::string Row;
		std::cin >> Row;
		
		for (int j = 0; j < C; ++j)
		{
			Maze[i][j] = Row[j] - '0';
		}
	}

	std::queue<std::pair<int, int>> Point2D;
	std::vector<std::vector<int>> Dist2D;
	Dist2D.resize(R);
	for (int i = 0; i < R; ++i)
	{
		Dist2D[i].resize(C);
		for (int j = 0; j < C; ++j)
		{
			Dist2D[i][j] = -1;
		}
	}

	Point2D.push({0, 0});
	Dist2D[0][0] = 1;

	while (!Point2D.empty())
	{
		auto Point = Point2D.front();
		Point2D.pop();
		
		for (int k = 0; k < 4; ++k)
		{
			int nx = Point.first + dx[k];
			int ny = Point.second + dy[k];

			if (0 <= nx && nx < R && 0 <= ny && ny < C)
			{
				if (Dist2D[nx][ny] != -1)
				{
					continue;
				}

				if (Maze[nx][ny] == 0)
				{
					continue;
				}

				Dist2D[nx][ny] = Dist2D[Point.first][Point.second] + 1;
				Point2D.push({ nx, ny });
			}
		}
	}

	std::cout << Dist2D[R - 1][C - 1];
}