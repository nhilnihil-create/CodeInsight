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
    int n;
    cin>>n;
    set <int> s;
    while (n--){
      int in; cin>>in;
      s.insert(in);
    }
    int l=(int)s.size();
    if ((n-l)&1)l--;
    cout << l << endl; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
