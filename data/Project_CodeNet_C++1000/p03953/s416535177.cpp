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
//int p = 998244353;
long long p = 1000000007;
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


#define T vel
T mul(T &a,T &b) {//calcureate a(b(x))
	int sz = a.size();
	vel c(sz);
	rep(i, sz) { c[i] = a[b[i]]; }
	return c;
}
T rui1(T &a, int n) {
	if (n == 1) { return a; }
	T x = rui1(a, n / 2);
	x = mul(x, x);
	if (n % 2 == 1) { x = mul(x, a); }
	return x;
}

signed main(){
	int n; cin >> n;
	vel x(n);
	rep(i, n) { cin >> x[i]; }
	int m, k; cin >> m >> k;
	vel per(n - 1);
	rep(i, n - 1) { per[i] = i; }
	rep(i, m) {
		int a; cin >> a;
		swap(per[a - 2], per[a - 1]);
	}
	per = rui1(per, k);
	int back = x[0];
	cout << back << endl;
	rep(i, n - 1) {
		back += (x[per[i]+1] - x[per[i]]);
		cout << back << endl;
	}
	return 0;
}