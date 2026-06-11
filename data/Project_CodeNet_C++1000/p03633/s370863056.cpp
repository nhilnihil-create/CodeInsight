#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<time.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
#define INF (1<<30)
#define INFLL (1LL << 60)
#define MOD 1000000007
#define rep(i, n) for(int i=0; i<(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }

ll gcd(ll a, ll b) {
	while (b) {
		a -= a / b * b;
		swap(a, b);
	}
	return a;
}
//最小公倍数
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}


int main()
{
	int N; cin >> N;
	vector<ll> T(N);
	rep(i, N) cin >> T[i];
	ll ans = 1;
	rep(i, N) {
		ans = lcm(ans, T[i]);
	}
	cout << ans << endl;
	return 0;
}
