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
#define   mod  998244353
#define   int  long long 
#define   ld long double
#define   pb push_back
#define   sz(x)  (int)x.size()
#define   ff first
#define   ss second
#define   pii  pair<int,int> 
#define   pb  push_back
#define   eb  emplace_back
using namespace std;

void solve(){
	int  n,k;
	cin >> n >> k ; 
	int ans=k;
	for (int i=1;i<n;i++) ans *= (k-1);
	cout << ans << endl; 
}

signed main()
{
	int  n=1; // cin >> n;
	while (n--) 
	solve();
    return 0;
}
/*
4 
10 30 40 20

*/