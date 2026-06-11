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

bool fl[100005];
inline void solve(){
    int n,op,ans=0; cin>>n>>op; 
    vi box(n+1,1);
    fl[1]=true;
    while (op-->0){
        int a,b;
        cin>>a>>b;
        if (box[a]>0){
            box[a]--; box[b]++;
            if (fl[a]){
                if (box[a]==0) fl[a]=false;
                fl[b]=true;
            }
        }
    }
    for (int i=1;i<=n;i++)
        if (fl[i]==true) ans++;
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
