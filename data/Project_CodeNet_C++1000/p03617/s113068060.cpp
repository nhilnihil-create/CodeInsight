#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int Q, H, S, D, N;
	cin >> Q >> H >> S >> D >> N;
	int mn1 = min({Q*4, H*2, S});
	int mn2 = min({Q*8, H*4, S*2, D});
	ll sum = (ll)N/2 * mn2;
	sum +=  (ll)N%2 * mn1;
	cout << sum << endl;
}

