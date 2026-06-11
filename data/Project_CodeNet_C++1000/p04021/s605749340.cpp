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

ll N;
vector<ll> A, B;

int main(int argc, char **argv)
{
	cin >> N;
	A.resize(N);
	REP(i, N) cin >> A[i];
	B = A;
	sort(ALL(B));

	map<ll, ll> m;
	REP(i, N)
		m[B[i]] = i;

	ll res{0};
	REP(i, N)
	{
		if (i % 2 != m[A[i]] % 2) 
			++res;
	}

	std::cout << res/2 << std::endl;
}
