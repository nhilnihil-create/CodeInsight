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
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
struct block {
	int a, b, c, d;
};
block b[100000];
void solve() {
	int n, h;
	cin >> n >> h;
	rep(i, n) {
		cin >> b[i].a >> b[i].b >> b[i].c >> b[i].d;

	}

}
bool hantei() {
	int n; ll a, b, c, d; cin >> n >> a >> b >> c >> d;
	if (a > b)b = 2 * a - b;
	ll dif = b - a;
	int le = 0;
	int ri = n-1;
	while (ri - le > 1) {
		int mid = (ri + le) / 2;
		ll ma = d * mid - c * (n-1 - mid);
		ll mi = c * mid - d * (n - 1 - mid);
		if (mi <= dif && dif <= ma)return true;
		else if (dif < mi)ri = mid;
		else le = mid;
	}
	return false;
}
int main() {
	if (hantei())cout << "YES" << endl;
	else cout << "NO" << endl;
	//stop
	return 0;
}
