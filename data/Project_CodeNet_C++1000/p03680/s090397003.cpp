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

bool vis[100005];

inline void solve(){
    int n,ans=0; cin>>n; 
    int a[n+1],idx=1;
    for (int i=1;i<=n;i++) {
        cin>>a[i]; 
    }
    bool ok=false;
    while (true){
        ans++;
        if (vis[a[idx]]) break;
        if (a[idx]==2) { ok=true; break; }
        vis[a[idx]]=true;
        idx=a[idx]; 
    }
    if (ok) cout << ans << endl;
    else cout << -1 << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
