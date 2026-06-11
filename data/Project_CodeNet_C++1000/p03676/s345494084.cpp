// Dont hack this or I hack ur mama
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#define ll long long 
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
using namespace std;

////////////// END OF TEMPLATE
const int nmax = 100005;
const ll mod = 1000000007;
ll inv[nmax],fact[nmax],ifact[nmax],x[nmax];
void precompute()
{
	inv[1] = 1;
	fact[1] = 1;
	fact[0] = 1;
	ifact[0] = 1;
	ifact[1] = 1;
	x[1] = 1;

	for(int i = 2 ; i < nmax; ++i)
	{
		inv[i] = ((mod - mod/i) * inv[mod%i] )% mod;
		fact[i] = (fact[i-1] * i) % mod;
		ifact[i] = (ifact[i-1] * inv[i]) % mod;
		x[i]=x[i-1]^i;
	}
}
ll calc(int n, int m)
{
	if(m > n)
		return 0LL;
	//cout << fact[n] << ' '<< ifact[m] << ' '<< ifact[n-m] << endl;
	return (fact[n] * (ifact[m] * ifact[n-m] % mod)) % mod;
}
int n;
int a[nmax];
void read()
{
	precompute();
	//ut << calc(32,5) << endl;
	cin >> n;
	for(int i = 0; i <= n; ++i)
	{
		cin >> a[i];
		x[n] ^= a[i];

	}
	vector < int > v;
	for(int i = 0 ; i<=n;++i)
		if(a[i] == x[n])
			v.push_back(i);
	int d = v[1]-v[0];
	cout << n << endl;
	for(int i = 2; i<=n+1; ++i)
		//cout << calc(n+1,i) << ' ' << calc(n-d,i-1) << ' ' << (calc(n+1,i) - calc(n-d,i-1) + mod) %mod << endl; 
	cout << (calc(n+1,i) - calc(n-d,i-1) + mod)%mod << endl;
}
void solve()
{
	
}
int main()
{
	std::ios::sync_with_stdio(false);
	read();
	solve();
	return 0;
}
