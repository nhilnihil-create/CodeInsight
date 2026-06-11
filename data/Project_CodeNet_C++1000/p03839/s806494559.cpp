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
	int N, K;
	cin >> N >> K;
	vector<ll> a(N);
	for(auto i = 0; i < N; ++i)
	{
		cin >> a[i];
	}

	vector<ll> sum(N + 1);
	vector<ll> sumPlus(N + 1);
	for (auto i = 0; i < N; ++i)
	{
		sum[i + 1] = sum[i] + a[i];
		sumPlus[i + 1] = sumPlus[i];
		if (a[i] > 0)
		{
			sumPlus[i + 1] += a[i];
		}
	}

	auto ans = 0ll;
	for (auto i = 0; i <= N - K; ++i)
	{
		auto temp = sumPlus[i] + sumPlus[N] - sumPlus[i + K];
		auto temp2 = sum[i + K] - sum[i];
		if (temp2 > 0)
		{
			temp += temp2;
		}
		ans = max(temp, ans);
	}
	cout << ans << endl;

	return 0;
}