#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	int H, W, N;
	cin >> H >> W >> N;
	vector<int> arrow_x = {1, 0, -1, 0};
	vector<int> arrow_y = {0, 1, 0, -1};
	int arrow = 0;
	vector<vector<int>> map(H, vector<int>(W, 0));

	int current_x = -1;
	int current_y = 0;

	for (int i = 0; i < N; i++)
	{
		int color;
		cin >> color;

		for (; color;)
		{
			int next_x = current_x + arrow_x[arrow];
			int next_y = current_y + arrow_y[arrow];

			if (next_x < 0 || W <= next_x || next_y < 0 || H <= next_y)
			{
				arrow = (arrow + 1) % 4;
				continue;
			}

			if (map[next_y][next_x] != 0)
			{
				arrow = (arrow + 1) % 4;
				continue;
			}

			map[next_y][next_x] = i + 1;
			current_x = next_x;
			current_y = next_y;
			color--;
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}