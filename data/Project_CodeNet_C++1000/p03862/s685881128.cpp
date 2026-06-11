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
#include <list>
#include <stack>
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
    int  n, x, ans = 0 ; 
    cin >> n >> x ; 
    vi a(n+1);
    for (int i=1;i<=n;i++) cin >> a[i] ; 
    int d= max(0LL,a[1]-x);
    a[1] -= d; ans += d ; 
    for (int i=2;i<=n;i++) {
        if (a[i-1]+a[i] >= x){
            d = max(0LL,a[i]+a[i-1]-x);
            a[i] -= d;
            ans += d ; 
        }
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
