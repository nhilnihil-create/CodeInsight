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
    vi cnt(26,0);
    string  s; cin >> s;
    int ans=100;
    for (int i=0;i<sz(s);i++) cnt[s[i]-'a']++; 
    for (int i=25;i>=0;i--){
        int cur=0;
        char ch=i+'a';
        for (int j=0,t=0;j<sz(s);j++){
            if (s[j] == ch) t=0;
            else t++;
            cur = max(cur,t);
        }
        ans = min(ans,cur);
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
/*
    serval -> srraa -> rrra -> rrr;
*/
