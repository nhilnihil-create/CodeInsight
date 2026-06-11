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
typedef tuple<ll, ll, ll> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	ll k;
	cin >> k;

	ll kk = k / 50;
	ll j = k % 50;

	V<ll> a(50, 49 + kk);

	rep(i, j)a[i] += 51 - j;
	rep(i, 50 - j)a[j + i] -= j;

	cout << 50 << endl;
	rep(i, 50) {
		cout << a[i];
		if (i < 49)cout << " ";
		else cout << endl;
	}

}