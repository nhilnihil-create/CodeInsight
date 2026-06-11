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
	int x; cin >> x;
	if (x == 1 || x == 2*n - 1) {
		cout << "No" << endl; return 0;
	}
	cout << "Yes" << endl;
	vel ans(2 * n - 1);
	ans[n - 2] = x - 1;
	ans[n - 1] = x;
	ans[n] = x + 1;
	vel list;
	for (int i = 1; i < 2 * n; i++){
		if (abs(i - x) > 1) { list.push_back(i); }
	}
	vel ex;
	for (int i = 0; i < 2 * n-1; i++) {
		if (abs(i - n+1) > 1) { ex.push_back(i); }
	}
	rep(i, 2 * n - 4) {
		ans[ex[i]] = list[i];
	}
	rep(i, 2 * n - 1) {
		cout << ans[i] << endl;
	}
	return 0;
}