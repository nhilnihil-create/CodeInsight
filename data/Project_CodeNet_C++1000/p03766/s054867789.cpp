#include <bits/stdc++.h>
#define gcj "Case #"
#define adj_list vector<vi>
#define endl "\n"
#define INF_INT 2e9
#define INF_LL 2e18
#define matmax 25
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define pii pair<int, pair<int, int> >
#define pl pair<ll, ll>
#define pll pair<ll, pair<ll, ll> >
#define vi vector<int>
#define vl vector<ll>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long int ll;

ll pow1(ll a, ll b, ll m = mod)
{
	if (b == 0)
		return 1ll;
	else if (b == 1)
		return a;
	else
	{
		ll x = pow1(a, b/2, m);
		x *= x;
		x %= m;
		if (b%2)
		{
			x *= a;
			x %= m;
		}
		return x;
	}
}

template <class avgType>
avgType avg(avgType a, avgType b) {
	return (a + b)/2;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());

int randInt() {
	return rng() % INT_MAX;
}

ll randLL() {
	return rng64() % LLONG_MAX;
}

vector< int > hashmods = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093};

ll n, ans[1100000], sum[1100000];

int main() {
	fastio;
	cin>>n;

	ans[n] = n;
	sum[n] = n;
	for (int i = n-1; i >= 1; i--) {
		ans[i] = ans[i+1];

		ans[i] += ((n-1) * (n-1));
		int lef = min(n-1, n - (n - i - 1));

		ans[i] += sum[i+3];

		ans[i] += lef;

		ans[i] %= mod;
		sum[i] = (sum[i+1] + ans[i])%mod;
	}

	cout<<ans[1]<<endl;

	return 0;
}