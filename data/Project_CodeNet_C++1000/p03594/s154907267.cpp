#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
typedef complex<double> com;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int h, w, d;
	cin >> h >> w >> d;
	for (int i = 3; i < 1000; i += 2) while (d%i == 0) d /= i;
	d *= 2;
	rep(i, h) {
		rep(j, w) {
			if ((i + j) % d < d / 2 && ((i - j) % d + d) % d < d / 2) cout << 'R';
			else if ((i + j) % d < d / 2 && ((i - j) % d + d) % d >= d / 2) cout << 'Y';
			else if ((i + j) % d >= d / 2 && ((i - j) % d + d) % d < d / 2) cout << 'G';
			else cout << 'B';
		}
		cout << endl;
	}
}