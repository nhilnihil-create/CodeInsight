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
#define int long long
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


signed main() {
	/*cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);*/

	bool flag = false;
	cout << "? " << 1000000000 << endl;
	char c;
	cin >> c;
	if (c == 'Y') flag = true;
	if (flag) {
		int check = 999999999;
		while (true) {
			cout << "? " << check << endl;
			char d;
			cin >> d;
			if (d == 'N') {
				cout << "! " << check + 1 << endl;
				return 0;
			}
			else if (d == 'Y'&&check == 9) {
				cout << "! " << 1 << endl;
				return 0;
			}
			check /= 10;
		}
	}
	else {
		int dig = 9;
		int check = 100000000;
		while (true) {
			cout << "? " << check << endl;
			char d;
			cin >> d;
			if (d == 'Y') break;
			else dig--;
			check /= 10;
		}
		int ok = 1;
		rep(_, dig - 1) ok *= 10;
		int ng = ok * 10;
		while (ng - ok > 1) {
			int mid = (ok + ng) / 2;
			cout << "? " << mid * 10 << endl;
			char d;
			cin >> d;
			if (d == 'N') ok = mid;
			else ng = mid;
		}
		cout << "! " << ng << endl;
	}
}