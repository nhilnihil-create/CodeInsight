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
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

int color[9];

inline void solve(){
    int n,a,ans=0,other=0; cin>>n; 
    while (n--){
        cin >> a;
        if (a>=3200) other++; 
        else if (a>=2800) color[8]=1; 
        else if (a>=2400) color[7]=1; 
        else if (a>=2000) color[6]=1; 
        else if (a>=1600) color[5]=1; 
        else if (a>=1200) color[4]=1; 
        else if (a>=800) color[3]=1; 
        else if (a>=400) color[2]=1; 
        else color[1]=1; 
    }
    for (int i=1;i<=8;i++)
        if (color[i]) ans++;
    cout << max(ans,1LL) << " " << ans+other<<endl;
    return;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
