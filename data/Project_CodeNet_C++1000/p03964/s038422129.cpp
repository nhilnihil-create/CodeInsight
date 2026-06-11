#include <bits/stdc++.h>
typedef long long lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()

using namespace std;

void execute()
{
	int N;
	lint ans_a = 1, ans_b = 1;
	lint max_a = 1, max_b = 1;
	lint mul;
	lint a, b;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		max_a = max(a, ans_a);
		max_b = max(b, ans_b);
		mul = max((max_a - 1 + a) / a, (max_b - 1 + b) / b);
		ans_a = a * mul;
		ans_b = b * mul;
	}
	cout << ans_a + ans_b << endl;
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