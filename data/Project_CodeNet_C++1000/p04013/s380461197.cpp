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
	int N, A;
	cin >> N >> A;

	vector<vector<lint>> DP(50 * 50 * 2 + 1 + 1, vector<lint>(50 + 1, 0));

	lint midium = 50 * 50 + 1;

	DP[midium][0] = 1;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		lint set = tmp - A;
		for (int j = 0; j < midium * 2; j++)
		{

			if (j - set < 0 || midium * 2 <= j - set)
				DP[j][i + 1] = DP[j][i];
			else
				DP[j][i + 1] = DP[j][i] + DP[j - set][i];
				}
	}

	cout << DP[midium][N] - 1 << endl;
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