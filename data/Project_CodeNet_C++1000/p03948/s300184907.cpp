#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<iomanip>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
const int mx = 3e6+1e3; //check the limits, dummy
typedef pair<int, int> pa;
const double PI = acos(-1);
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
bool isprime(int n) { if (n <= 1)return 0; for (int i = 2; i * i <= n; i++)if (n % i == 0)return 0; return 1; }
#define swa(a,b) a^=b^=a^=b
#define re(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define rb(i,a,b) for(ll i=(a),_=(b);i>=_;i--)
#define clr(a,b) memset(a, b, sizeof(a))
#define lowbit(x) ((x)&(x-1))
#define mkp make_pair
//inline ll qpow(ll a, ll b) { return b ? ((b & 1) ? a * qpow(a * a % mod, b >> 1) % mod : qpow(a * a % mod, b >> 1)) % mod : 1; }
//inline ll qpow(ll a, ll b, ll c) { return b ? ((b & 1) ? a * qpow(a * a % c, b >> 1) % c : qpow(a * a % c, b >> 1)) % c : 1; }
void ca(int kase, int ans) { cout << "Case #" << kase << ": " << ans << endl; }
void sc(int& x) { scanf("%d", &x); }void sc(int64_t& x) { scanf("%lld", &x); }void sc(double& x) { scanf("%lf", &x); }void sc(char& x) { scanf(" %c", &x); }void sc(char* x) { scanf("%s", x); }
int n, m, t, k;
int a[mx],mp[mx], sum, b,cnt=1,ans[mx],q[mx];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int maxx = -inf, temp = -inf;
	for (int i = n; i >= 1; i--) {
		temp = max(temp, a[i]);//最大的价格
		maxx = max(maxx, temp - a[i]);//最大的贸易差
	}

	temp = -inf;
	int res = 0;
	for (int i = n; i >= 1; i--) {
		temp = max(temp, a[i]);
		if (maxx == temp - a[i])
			res++;
	}
	printf("%d\n", res);
	return 0;
}