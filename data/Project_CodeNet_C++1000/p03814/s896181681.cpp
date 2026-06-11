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
#define   ld long double
#define   pb push_back
#define  sz(x)  (int)x.size()
#define  ff first
#define  ss second
#define  pii  pair<int,int>
using namespace std;

inline void solve(){ 
    map <char,int> mp;
    string s;
    cin>>s;
    int ans;
    for (int i=0;i<(int)s.size();i++){
        if (s[i]=='A'){
            if (mp[s[i]]) continue;
            else mp[s[i]]=i+1;
        }
        if (s[i]=='Z'){
            if (mp['A']) ans=i+2-mp['A'];
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
