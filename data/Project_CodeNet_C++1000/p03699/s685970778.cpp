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
    int n,s=0; cin>>n; 
    vi a(n);
    for (int &i: a){
        cin >> i;
        s += i;
    }
    sort(a.begin(), a.end());
    for (int i=0;i<n;i++){
        if (s%10){
            cout << s << endl;
            return;
        }
        if ((s-a[i])%10){
            cout << s-a[i] << endl;
            return;
        }
    }
    cout << 0 << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
