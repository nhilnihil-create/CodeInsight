#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	vector<ll> T(N);
	vector<ll> A(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> T[i];
	}
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	auto ans = 1ll;
	auto mod = (ll)1e9 + 7;
	for (auto i = 0; i < N; ++i)
	{
		if (i == 0 || T[i - 1] < T[i])
		{
			if (T[i] > A[i])
			{
				ans = 0;
				break;
			}
		}
		else if (i == N - 1 || A[i] > A[i + 1])
		{
			if (T[i] < A[i])
			{
				ans = 0;
				break;
			}
		}
		else
		{
			ans = ans * min(T[i], A[i]) % mod;
		}
	}
	cout << ans << endl;

	return 0;
}