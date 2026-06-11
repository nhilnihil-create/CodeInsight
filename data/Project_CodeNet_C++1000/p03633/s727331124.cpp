#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define INFLL (1LL << 60)
#define INF (1 << 30)
using namespace std;
typedef long long ll;

template<class T> inline void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> inline void chmax(T& a, T b) { if (a < b) a = b; }

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main()
{
	int N; cin >> N;
	ll ans = 1;
	rep(i, N) {
		ll T; cin >> T;
		ans = lcm(ans, T);
	}
	cout << ans << endl;
	return 0;
}
