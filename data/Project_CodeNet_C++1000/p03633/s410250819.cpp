#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

long long lcm(long long a, long long b)
{
	return a/gcd(a, b) * b;
}


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N; cin >> N;
	vector<ll> T(N); REP(i, N) cin >> T[i];

	ll res{T[0]};
	REP(i, N-1) res = lcm(res, T[i+1]);
	std::cout << res << std::endl;
	return 0;
}
