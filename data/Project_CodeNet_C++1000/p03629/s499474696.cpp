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
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

constexpr int alph = 26;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(n);
	int cnt = 1;
	int ap = 0, mask = (1 << alph) - 1;
	for (int i = n - 1; i >= 0; i--) {
		int c = s[i] - 'a';
		ap |= (1 << c);
		if (ap == mask) {
			cnt++; ap = 0;
		}
		a[i] = cnt;
	}
	a.pb(0);
	int sz = a[0] - 1;
	int ng = 0; int u = alph; int idx = 0;
	string ans = "";
	rep(i, n) {
		if (a[i + 1] > sz) ng |= (1 << (s[i] - 'a'));
		else {
			while (i < n - 1 && a[i + 1] == sz) {
				int c = s[i] - 'a';
				if (!(ng&(1 << c)) && chmin(u, c)) idx = i;
				i++;
			}
			if (u != alph) {
				//cerr << '!' << idx << '\n';
				ans += s[idx]; sz--;
				i = idx; ng = 0; u = alph;
			}
		}
	}
	//rep(i, n) cerr << a[i] << '\n';
	rep(i, alph) {
		if (!(ng&(1 << i))) {
			ans += (char)'a' + i;
			break;
		}
	}
	cout << ans << '\n';
}