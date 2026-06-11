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
	int N, Ma, Mb;
	int ans = INF32;
	vector<int> data(400401, INF32);
	cin >> N >> Ma >> Mb;

	data[0] = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		for (int j = 400400; a + 1000 * b <= j; j--)
		{
			if (data[j - a - 1000 * b] != INF32)
			{
				data[j] = min(data[j], data[j - a - 1000 * b] + c);
			}
		}
	}

	for (int i = Ma + Mb * 1000; i <= 400400; i += Ma + Mb * 1000)
	{
		//cout << i << " " << data[i] << endl;
		ans = min(ans, data[i]);
	}

	if (ans == INF32)
	{
		cout << -1 << endl;
	}
	else
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