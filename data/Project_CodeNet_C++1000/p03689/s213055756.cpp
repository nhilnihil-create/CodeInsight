#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll m[501][501];
int main() {
	int h, w, a, b; cin >> h >> w >> a >> b;
	rep1(i, h) {
		rep1(j, w) {
			m[i][j] = 4000;
		}
	}
	for (int i = a; i <= h; i += a) {
		for (int j = b; j <= w; j += b) {
			m[i][j] = -4000 * (a * b - 1) - 1;
		}
	}
	ll sum = 0;
	rep1(i, h) {
		rep1(j, w) {
			sum += m[i][j];
		}
	}
	if (sum > 0) {
		cout << "Yes" << endl;
		rep1(i, h) {
			rep1(j, w) {
				if (j > 1)cout << " ";
				cout << m[i][j];
			}
			cout << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
