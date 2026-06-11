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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll b1[1 << 18], b2[1 << 18]; int n,m;
void add(int a, int b, ll w) {
	for (int i = a; i < m+1; i |= i + 1)b1[i] += -a * w;
	for (int i = b; i < m+1; i |= i + 1)b1[i] += b * w;
	for (int i = a; i < m+1; i |= i + 1)b2[i] += w;
	for (int i = b; i < m+1; i |= i + 1)b2[i] += -w;
}
ll sum0(int a) {
	ll ret = 0;
	for (int i = a - 1; i >= 0; i = (i &(i + 1)) - 1)ret += b1[i];
	for (int i = a - 1; i >= 0; i = (i &(i + 1)) - 1)ret += a*b2[i];
	return ret;
}
ll sum(int a, int b) {
	return sum0(b) - sum0(a);
}
struct miyage { int from, to; };
bool comp(miyage a, miyage b) {
	if (a.to - a.from < b.to - b.from)return true;
	else return false;
}
miyage x[300000];
int main() {
	cin >> n >> m;
	rep(i, n) {
		int l, r; cin >> l >> r;
		x[i] = { l,r };
	}
	sort(x, x + n, comp);
	int now = 0;
	int cnt = n;
	rep1(i, m) {
		int out = cnt;
		for (int j = 0; j <= m; j+=i) {
			out += sum(j,j+1);
		}
		cout << out << endl;
		while (now < n&&x[now].to - x[now].from + 1 <= i) {
			add(x[now].from, x[now].to+1, 1);
			now++; cnt--;
		}
	}
	return 0;
}