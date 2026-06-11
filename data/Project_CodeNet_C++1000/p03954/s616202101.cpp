#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include<unordered_set>
using namespace std;
long long p  = 998244353;
//long long p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<int,pin>
#define V vector
#define Endl endl
#define veb vector<bool>
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) lower_bound(h.begin(),h.end(),val)-h.begin()
#define upper(h,val) upper_bound(h.begin(),h.end(),val)-h.begin()
int max_kai = 150000;
vel kai(max_kai, 1);
vel inv_kai;
int rui(int a, int n) {
	if (n == 0) { return 1; }
	int x = rui(a, n / 2);
	x *= x; x %= p;
	if (n % 2 == 1) { x *= a; x %= p; }
	return x;
}
int inv(int a) { return rui(a, p - 2); }
void make_kai() {
	for (int i = 1; i < max_kai; i++) { kai[i] = kai[i - 1] * i; kai[i] %= p; }
	inv_kai = kai;
	rep(i, max_kai) { inv_kai[i] = inv(kai[i]); }
}
int nCr(int n, int r) {
	int a = kai[n] * inv_kai[r]; a %= p;
	a *= inv_kai[n - r]; a %= p;
	return a;
}
vel pa;
int root(int x) {
	if (pa[x] == -1) { return x; }
	int ans = root(pa[x]); pa[x] = ans;
	return ans;
}
void marge(int x, int y) {
	x = root(x);
	y = root(y);
	if (x != y) {pa[x] = y;}
}
#define end_s(a) cout <<a<<endl;return 0
int sol(int val, vel &a) {
	int m = a.size();
	vel b(m + 2);
	b[0] = a[0]; b[m + 1] = a[m - 1];
	rep(i, m) { b[i + 1] = a[i]; }
	m += 2;
	rep(i,m){
		if (b[i] <= val) { b[i] = 0; }
		else { b[i] = 1; }
	}
	int n = m / 2;
	if (b[n - 1] == b[n] || b[n + 1] == b[n]) { return b[n]; }
	pin lef;
	rep(i, n) {
		if (b[i] == b[i + 1]) { lef = mkp(i, b[i]); }
	}
	pin ri;
	for (int i = m - 1; i > n; i--) {
		if (b[i] == b[i - 1]) { ri = mkp(i, b[i]); }
	}
	if (lef.first + ri.first >= 2 * n) { return lef.second; }
	else { return ri.second; }
}
signed main(){
	int n; cin >> n;
	vel a(2 * n - 1);
	rep(i, 2 * n - 1) { cin >> a[i]; }
	int ng = 0; int ok = 2 * n;//(ng,ok]
	while (ok - ng > 1) {
		int mid = (ok + ng) / 2;
		int fl = sol(mid, a);//解がmid以下か
		if (fl==0) { ok = mid; }
		else { ng = mid; }
	}
	cout << ok << endl;
	return 0;
}