/*.....Bismillahir Rahmanir Rahim.....*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define mod 998244353
#define int long long
#define ld long double
#define pb push_back
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define pii pair<int, int>
#define  vi  vector<int> 
using namespace std;
typedef pair<int, pair<int, int>> pi;

void solve()
{
	int  n, a, b, ans = 0 ; 
	cin >> n >> a >> b ; 
	int x[n+1];
	for (int i=1;i<=n;i++) cin >> x[i] ; 
	for (int  i=2;i<=n;i++) {
		if ((x[i]-x[i-1])*a>b) ans += b;
		else ans += a*(x[i]-x[i-1]);
	}
	cout << ans << endl; 
}

signed main()
{
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
	return 0;
}
/*
7 1 100
40 43 45 105 108 115 124

7 1 2
24 35 40 68 72 99 103

*/