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
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

inline void solve(){
    int n; cin>>n; 
    vi a(n);
    for (int &i: a) cin>>i;
    int p=0,ne=0,s=0;
    for (int i=0;i<n;i++){
        s += a[i];
        if (i&1){
            if (s>=0){
                p += s+1;
                s = -1;
            }
        }
        else {
            if (s<=0){
                p += abs(s)+1;
                s=1;
            }
        }
    }
    s=0;
    for (int i=0;i<n;i++){
        s += a[i];
        if (i%2==0){
            if (s>=0){
                ne += s+1;
                s=-1;
            }
        }
        else {
            if (s<=0){
                ne += abs(s)+1;
                s=1;
            }
        }
    }
    cout << min(p,ne) << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
