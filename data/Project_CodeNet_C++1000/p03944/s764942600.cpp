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

inline void solve(){
    int  w, h, n ; 
    cin >> w >> h >> n ; 
    int l=0,r=w,u=h,d=0;
    for (int i=0;i<n;i++){
        int x,y,a;
        cin>>x>>y>>a;
        if (a==1) l=max(l,x);
        if (a==2) r=min(r,x);
        if (a==3) d=max(d,y);
        if (a==4) u=min(u,y);
    }
    cout << (max(r-l,0LL)*max(u-d,0LL)) << endl; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
