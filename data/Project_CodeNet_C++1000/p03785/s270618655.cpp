#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long  ll;

int main()
{
	ll N, C, K;
	cin >> N >> C >> K;
	vector<ll> t(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> t[i];
	}
	sort(t.begin(), t.end());
	ll i = 0;
	ll res = 0;
	while (i < N)
	{
		res++;
		ll start = i;
		while (i < N && t[i] - t[start] <= K && i - start < C) i++;
	}
	cout << res << endl;
	return 0;
}