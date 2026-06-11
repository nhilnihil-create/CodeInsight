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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = 998244353;
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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n; int a[100000];
int gcd(int x,int y) {
	if (x < y)swap(x, y);
	while (y) {
		int r = x % y; x = y; y = r;
	}
	return x;
}
bool tra() {
	int cnt = 0;
	rep(i, n) {
		if (a[i] % 2 == 0)cnt++;
	}
	if (cnt % 2)return true;
	else if (cnt != n - 1)return false;
	else {
		rep(i, n) {
			if (a[i] % 2) {
				if (a[i] == 1)return false;
				a[i]--;
			}
		}
		int g = a[0];
		Rep(i, 1, n) {
			g = gcd(g,a[i]);
		}
		rep(i, n) {
			a[i] /= g;
		}
		return !tra();
	}
}
int main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	if (tra())cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}