#include "bits/stdc++.h"
using namespace std;
#define int long long
#define double long double
#define low lower_bound
#define upp upper_bound
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define Rep(i,n) for (int i = (int)(n); i >= 0; i--)
#define all(vec) vec.begin(), vec.end()
#define rever(vec) reverse(all(vec));
#define cend printf("\n");
#define prique(T) priority_queue<T, vector<T>, greater<T>>
#define prique2(T) priority_queue<T>
struct edge { int to, cost; };
using P = pair<int, int>;
using PP = pair<P, int>;
const int mod2 = 998244353;
const int mod = (int)1e9 + 7, inf = (int)1e16;

int modpow(int x, int n) {
	int ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans *= x;
			if (mod <= ans) ans %= mod;
		}
		x *= x;
		if (mod <= x) x %= mod;
		n >>= 1;
	}
	return ans;
}

int fact[1000000];
void f_init(int n) {
	if (1000000 <= n) return;
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= n; ++i) {
		fact[i] *= fact[i - 1];
		if (mod <= fact[i]) fact[i] %= mod;
	}
	return;
}

int comb(int n, int r) {
	if (n < r) return 0;
	int ans = fact[n] * modpow(fact[n - r], mod - 2) % mod * modpow(fact[r], mod - 2);
	if (ans < 0) return ans + mod;
	return ans;
}

int perm(int n, int r) {
	if (n < r) return 0;
	if (n - r < r) r = n - r;
	int ans= fact[n] * modpow(fact[n - r], mod - 2) % mod;
	if (ans < 0) return ans + mod;
	return ans;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

bool pri(int p) {
	for (int i = 2; i * i <= p; ++i) if (p % i == 0) return false;
	return p > 1;
}

map<int, int>factring(int n) {
	map<int, int>ans;
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			n /= i;
			++ans[i];
		}
	}
	if (n != 1) ++ans[n];
	return ans;
}

P operator+(const P& a, const P& b) {
	return P(a.first + b.first, a.second + b.second);
}
P operator-(const P& a, const P& b) {
	return P(a.first - b.first, a.second - b.second);
}

string S,T;
int q,n,m;
P s[100010],t[100010];
signed main() {
	cin>>S>>T>>q;
	n=S.size(),m=T.size();
	rep(i,n) {
		if(S[i]=='A') {
			s[i+1].first++;
		}
		else {
			s[i+1].second++;
		}
		s[i+1]=s[i+1]+s[i];
	}
	rep(i,m) {
		if(T[i]=='A') {
			t[i+1].first++;
		}
		else {
			t[i+1].second++;
		}
		t[i+1]=t[i+1]+t[i];
	}
	rep(i,q) {
		int a,b,c,d;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		int cnta=(s[b].first-s[a-1].first)-(t[d].first-t[c-1].first);
		int cntb=(s[b].second-s[a-1].second)-(t[d].second-t[c-1].second);
		if((cnta-cntb)%3==0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}
