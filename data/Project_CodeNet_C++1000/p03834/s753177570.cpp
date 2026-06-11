/*------------------------------------
.....Bismillahir Rahmanir Rahim.......
created by muslim.time: 2:24:23 pm....
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
    string s; cin>>s;
    string res;
    for (int i=0;i<19;i++){
        if (s[i]==',') {
            cout << res << " ";
            res="";
        }
        else res += s[i];
    }
    cout << res << endl; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
