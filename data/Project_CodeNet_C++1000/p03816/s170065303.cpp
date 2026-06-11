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
	int N;
	set<int> data;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		data.insert(tmp);
	}

	int ans = data.size() - ((data.size() & 1) ? 0 : 1);

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