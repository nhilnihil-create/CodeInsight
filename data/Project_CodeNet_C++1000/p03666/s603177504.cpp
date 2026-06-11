#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	ll a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	ll g = b - a;

	bool ok = false;
	rep(i, n)if (c * i - d * (n - 1 - i) <= g && g <= d * i - c * (n - 1 - i))ok = true;
	
	cout << (ok ? "YES" : "NO") << endl;

}