#include<bits/stdc++.h>
using namespace std;

int w, h, n;

void fill(vector<vector<int>> &maze, int x, int y, int a)
{
	if (a == 1)
	{
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (j < x)
					maze[i][j] = 1;
	}
	else if (a == 2)
	{
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (j >= x)
					maze[i][j] = 1;
	}
	else if (a == 3)
	{
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (i < y)
					maze[i][j] = 1;
	}
	else 
	{
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (i >= y)
					maze[i][j] = 1;
	}
}

int main()
{
	cin >> w >> h >> n;
	vector<vector<int>> maze(h, vector<int>(w, 0));
	for (int i = 0; i < n; ++i)
	{
		int x, y, a; cin >> x >> y >> a;
		fill(maze, x, y, a);
	}
	int ans = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (!maze[i][j])
				ans++;
	cout << ans << endl;
}

