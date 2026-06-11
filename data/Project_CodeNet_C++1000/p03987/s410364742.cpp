#include<algorithm>
#include<iostream>
#include<string.h>
#include<utility>
#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#pragma warning(disable:4244)
#define PI 3.1415926536
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll ll_inf = 9223372036854775807;
const int int_inf = 2147483647;
const short short_inf = 32767;
const char char_inf = 127;
ll GCD(ll a, ll b) { return a ? GCD(b, a % b) : a; }
inline ll read() {
	ll c = getchar(), Nig = 1, x = 0;
	while (!isdigit(c) && c != '-')c = getchar();
	if (c == '-')Nig = -1, c = getchar();
	while (isdigit(c))x = ((x << 1) + (x << 3)) + (c ^ '0'), c = getchar();
	return Nig * x;
}
inline void out(ll a)
{
	if (a < 0)putchar('-'), a = -a;
	if (a >= 10)out(a / 10);
	putchar(a % 10 + '0');
}
ll qpow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1)res = (res * x) % mod;
		x = (x * x) % mod; n >>= 1;
	}
	return res;
}
#define read read()
ll dp[250000][40];
ll save[250000];
ll n;
ll RMQ(ll s, ll v)
{
	ll k = (ll)(log(v - s + 1) * 1.0 / log(2.0));
	return save[dp[s][k]] < save[dp[v - ((ll)1 << k) + 1][k]] ? dp[s][k] : dp[v - ((ll)1 << k) + 1][k];
}
ll sum = 0;
bool judge(ll l, ll r)
{
	if (l == r)
	{
		sum += (ll)save[l];
		return 1;
	}
	return 0;
}
void dfs(ll L, ll R)
{
	if (judge(L, R))return;
	ll temp = RMQ(L, R);
	sum = sum + (ll)(temp - L + 1) * (R - temp + 1) * save[temp];
	if (L <= temp - 1)dfs(L, temp - 1);
	if (R >= temp + 1)dfs(temp + 1, R);
}
void ANS(int i, int j)
{
	dp[i][j] = save[dp[i][j - 1]] < save[dp[i + ((ll)1 << (j - 1))][j - 1]] ? dp[i][j - 1] : dp[i + ((ll)1 << (j - 1))][j - 1];
}
int main()
{
	n = read;
	for (ll i = 0; i < n; i++)save[i] = read;
	for (ll i = 0; i < n; i++)dp[i][0] = i;
	for (ll j = 1; ((ll)1 << j) <= n; j++)
		for (ll i = 0; i + ((ll)1 << j) - 1 < n; i++)ANS(i, j);
	dfs(0, n - 1);
	cout << sum << endl;
}