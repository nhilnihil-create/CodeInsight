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
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

inline void solve(){ 
    string a,b;
    cin>>a>>b;
    int l=sz(a),ll=sz(b);
    for (int i=0;i<l;i++){
        if (i==ll){
            cout << a[i];
        }
        else cout <<a[i]<<b[i];
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
