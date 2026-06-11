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
	lint A, B;
	cin >> N >> A >> B;

	vector<lint> data(N);
	lint ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> data[i];
	}

	for (int i = 1; i < N; i++)
	{
		ans += min(A * (data[i] - data[i - 1]), B);
	}

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