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
P x[100000];
ll cnt[100000];
bool comp(P a, P b) {
	if (a.second != b.second)return a.second > b.second;
	return a.first < b.first;
}
int main() {
	int n; cin >> n;
	rep(i, n) {
		int a; cin >> a;
		x[i] = { i,a };
	}
	sort(x, x + n, comp);
	int num = 1; int ind = x[0].first; ll sto = x[0].second;
	rep1(i, n - 1) {
		cnt[ind] += num * (sto - x[i].second);
		num++;
		sto = x[i].second;
		ind = min(ind, x[i].first);
	}
	cnt[ind] += num * sto;
	rep(i, n) {
		cout << cnt[i] << endl;
	}
	return 0;
}