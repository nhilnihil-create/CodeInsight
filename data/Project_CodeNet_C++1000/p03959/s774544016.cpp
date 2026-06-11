#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
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

	auto prev = 0ll;
	vector<ll> h(N, INT_MAX);
	vector<ll> T(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> T[i];
		if (T[i] > prev)
		{
			h[i] = 0;
		}
		else
		{
			h[i] = min(h[i], T[i]);
		}
		prev = T[i];
	}

	vector<ll> A(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	prev = 0;
	for (auto i = N - 1; i >= 0; --i)
	{
		if (A[i] > prev)
		{
			if (h[i] == 0)
			{
				if (A[i] != T[i])
				{
					h[i] = -1;
				}
			}
			else
			{
				if (A[i] <= T[i])
				{
					h[i] = 0;
				}
				else
				{
					h[i] = -1;
				}
			}
		}
		else
		{
			h[i] = min(h[i], A[i]);
		}
		prev = A[i];
	}

	auto result = 1ll;
	auto mod = (ll)1e9 + 7;
	for (auto i = 0; i < N; ++i)
	{
		if (h[i] < 0)
		{
			result = 0;
			break;
		}
		else if (h[i] == 0)
		{
			continue;
		}

		result = (result * h[i]) % mod;
	}

	cout << result << endl;

	return 0;
}