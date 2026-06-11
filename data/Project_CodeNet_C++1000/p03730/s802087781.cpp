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
    map <int,bool>mp;
    int a,b,c; 
    cin>>a>>b>>c;
    int s=a;
    for (int i=a;i;i+=a){
        s=i;
        if (s%b==c) break;
        if (mp[s%b]){
            cout << "NO" << endl;
            return ;
        }
        mp[s%b] = true;
    }
    cout << "YES" << endl;
    
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
