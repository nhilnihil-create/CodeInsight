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
    int x1,y1,x2,y2; 
    cin>>x1>>y1>>x2>>y2;
    int r=x2-x1,u=y2-y1,l=r,d=u;
    for (int i=0;i<r;i++) cout << 'R';
    for (int i=0;i<u;i++) cout << 'U';
    for (int i=0;i<l;i++) cout << 'L';
    for (int i=0;i<d;i++) cout << 'D';
    cout << 'D';
    for (int i=0;i<=r;i++) cout << 'R';
    for (int i=0;i<=u;i++) cout << 'U';
    cout << 'L';
    cout << 'U';
    for (int i=0;i<=l;i++) cout << 'L';
    for (int i=0;i<=d;i++) cout << 'D';
    cout << 'R' << endl;

}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
