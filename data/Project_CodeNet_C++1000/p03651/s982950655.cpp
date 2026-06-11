#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int gcd(int i, int j) {
	if (i < j)swap(i, j);
	if (i % j)return gcd(j, i % j);
	else return j;
}

int main() {

	int n, k;
	cin >> n >> k;
	vi a(n);
	int mx = 0;
	rep(i, n) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	int g=a[0];
	rep(i, n)g = gcd(g, a[i]);
	

	bool ok = true;
	if (mx < k)ok = false;
	if (g > 1 && k % g)ok = false;

	if (ok)cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;

}