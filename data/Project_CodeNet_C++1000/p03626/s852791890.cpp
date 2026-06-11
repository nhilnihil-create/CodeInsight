#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((lint)1000000007)

using namespace std;

void execute()
{
	int N;
	string A, B;
	int start;
	bool same;
	lint ans;
	cin >> N;
	cin >> A >> B;

	if (A[0] == B[0])
	{
		same = true;
		start = 1;
		ans = 3;
	}
	else
	{
		same = false;
		start = 2;
		ans = 6;
	}

	for (int i = start; i < N;)
	{
		if (A[i] == B[i])
		{
			if (same)
			{
				ans *= 2;
			}
			else
			{
				ans *= 1;
			}
			same = true;
			i += 1;
		}
		else
		{
			if (same)
			{
				ans *= 2;
			}
			else
			{
				ans *= 3;
			}
			same = false;
			i += 2;
		}
		ans %= INV;
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