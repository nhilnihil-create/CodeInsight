#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstring>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<double, double >pd;
typedef pair<string, string> sP;
typedef pair<ll, pair<ll, ll>> PP;


const ll mod = 1e4;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const double eps = 1e-10;
const double PI = 3.14159265358979323846;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };

#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second

ll n, p[200010], cnt, l, t, x[200010];
vector<ll>place;


int main() {
	cin >> n >> l >> t;
	for (int i = 0;i < n;i++) {
		cin >> x[i] >> p[i];
	}

	for (int i = 0;i < n;i++) {//最終的な蟻の位置を求める
		if (p[i] == 1) {
			place.eb((x[i] + t) % l);
		}
		else {
			place.eb((x[i] - t + l * (ll)1e8) % l);
		}
	}
	sort(ALL(place));

	for (int i = 0;i < n;i++) {
		if (p[i] == 1) {
			cnt += (x[i] + t) / l;
		}
		else {
			cnt += (x[i] - t  - (l - 1)) / l;
		}
	}
	
	ll it1 = (cnt+n) % n;
	for (int i = it1;i < it1 + n;i++) {
		cout << place[(i + n) % n] << endl;
	}
	return 0;
}
