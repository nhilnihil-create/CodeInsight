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
    int n,m;
    cin>>n>>m;
    int a[n],b[n],ci[m],cj[m];
    for (int i=0;i<n;i++) cin>>a[i]>>b[i];
    for (int i=0;i<m;i++) cin>>ci[i]>>cj[i];
    for (int i=0;i<n;i++){
        int d=100000000000,ith,ii=100000000000;
        for (int j=0;j<m;j++){
            int h= abs(a[i]-ci[j])+abs(b[i]-cj[j]);
            if (h<=d){
                if (h<d){
                    d=h; ith=j+1; ii = abs(a[i]);
                }
                else {
                    int dd=abs(a[i]);
                    if (dd<ii){
                        ii=dd;
                        ith=j+1;
                    }
                }
            }
        }
        cout << ith << endl;
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
