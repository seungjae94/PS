#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct int2
{
	int x;
	int dist;

	bool operator<(const int2& Other) const
	{
		if (dist > Other.dist)
		{
			return true;
		}
		else if (dist < Other.dist)
		{
			return false;
		}
		return x > Other.x;
	}
};

std::vector<int> dists;
std::priority_queue<int2> queue;

int main()
{
	dists = std::vector<int>(200001, INT_MAX);

	// Me Other
	// 
	int Me, Other;
	std::cin >> Me >> Other;

	dists[Me] = 0;
	queue.push({ Me, dists[Me]});

	while (false == queue.empty())
	{
		int2 pair = queue.top();
		queue.pop();
		int dist = pair.dist;
		int x = pair.x;

		if (dist > dists[x])
		{
			continue;
		}

		if (x == Other)
		{
			std::cout << dist;
			return 0;
		}

		int nxs[3] = { 2 * x, x + 1, x - 1 };
		int ndists[3] = { dists[x], dists[x] + 1, dists[x] + 1 };

		for (int i = 0; i < 3; ++i)
		{
			int nx = nxs[i];
			int ndist = ndists[i];

			if (nx >= 0 && nx < dists.size() && ndist < dists[nx])
			{
				dists[nx] = ndist;
				queue.push({ nx, ndist });
			}
		}
	}
}