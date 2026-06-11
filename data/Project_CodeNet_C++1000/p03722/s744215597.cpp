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
	lint N, M;

	cin >> N >> M;
	vector<lint> node(N, -INF64);

	vector<vector<pair<int, lint>>> root(N, vector<pair<int, lint>>());

	for (int i = 0; i < M; i++)
	{
		int a, b;
		lint c;
		cin >> a >> b >> c;
		root[a - 1].push_back(make_pair(b - 1, c));
	}
	node[0] = 0;

	for (int i = 0; i < 2 * N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (auto n : root[j])
			{
				if (node[n.first] == -INF64 || node[n.first] < node[j] + n.second)
				{
					node[n.first] = node[j] + n.second;
					if (N < i && n.first == N - 1)
					{
						cout << "inf" << endl;
						return;
					}
				}
			}
		}
	}
	cout << node[N - 1] << endl;

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