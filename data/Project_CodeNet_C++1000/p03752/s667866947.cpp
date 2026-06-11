#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

int n, k;
vector<ll> vs;

vector<ll> memo;

ll dfs(int index, ll height, int color) {
	if (index == n) {
		if (color < k) return INF;
		return 0;
	}
	ll a = INF;
	if (height < vs[index]) {
		a = min(a, dfs(index + 1, vs[index], color + 1));
	}
	else {
		a = min(a, dfs(index + 1, height, color));		
		ll add = height + 1 - vs[index];
		a = min(a, dfs(index + 1, height+1, color+1) + add);
	}
	memo[index] = a;
	return a;
}

int main() {
	cin >> n >> k;
	vs.resize(n);
	memo.resize(n);
	rep(i, n) cin >> vs[i];
	ll lower = dfs(0, 0, 0);
	cout << lower << endl;
	return 0;
}
