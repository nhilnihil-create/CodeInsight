/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
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
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

int  n,k; 
int a[52];
int dp[2][52];

int fun(int idx,int sum){
    if (idx>n ) return (sum%2==k); 
    if (dp[sum][idx] != -1) return dp[sum][idx];
    return  dp[sum][idx] = fun(idx+1,sum%2) + fun(idx+1,(sum+a[idx])%2) ; 
}


inline void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    cout << fun(1,0) << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
