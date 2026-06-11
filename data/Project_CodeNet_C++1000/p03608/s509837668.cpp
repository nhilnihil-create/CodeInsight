#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define LIMIT(d_in, d_min, d_max) max(d_min, min(d_max, d_in))
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

void execute()
{
	int N, M, R;
	int ans = INF32;
	cin >> N >> M >> R;

	vector<int> target(R);
	vector<vector<int>> grid(N, vector<int>(N, INF32));

	for (int i = 0; i < R; i++)
	{
		cin >> target[i];
		target[i]--;
	}

	sort(all(target));

	for (int i = 0; i < M; i++)
	{
		int from, to, dis;
		cin >> from >> to >> dis;
		from--;
		to--;
		grid[from][to] = dis;
		grid[to][from] = dis;
	}

	for (int i = 0; i < N; i++)
	{
		grid[i][i] = 0;
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
			}
		}
	}

	do
	{
		int sum_dis = 0;

		for (int i = 0; i + 1 < R; i++)
		{
			sum_dis += grid[target[i]][target[i + 1]];
		}

		ans = min(ans, sum_dis);

	} while (next_permutation(all(target)));
	cout << ans << endl;
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