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
    int x,y,gx,gy;
    cin>>x>>y>>gx>>gy;
    string s;
    for (int i=y;i<gy;i++) s+= (char)'U';
    for (int i=x;i<gx;i++) s+= (char)'R';
    for (int i=gy;i>y;i--) s += (char)'D';
    for (int i=gx;i>x;i--) s += (char)'L';
    s += (char)'L';

    for (int i=y;i<=gy;i++) s+= (char)'U';
    for (int i=x;i<=gx;i++) s+= (char)'R';
    s += (char)'D'; s += (char)'R'; 
    for (int i=gy;i>=y;i--) s += (char)'D';
    for (int i=gx;i>=x;i--) s += (char)'L';
    s += (char)'U';
    cout << s << endl; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
