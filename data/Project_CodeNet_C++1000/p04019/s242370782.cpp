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

// string rotation...

inline void solve(){
    string str;
    cin>>str;
    int s=0,n=0,e=0,w=0;
    int len=sz(str) ; 
    for (int i=0;i<len;i++){
        if (str[i]=='N') n++;
        if (str[i]=='S') s++;
        if (str[i]=='E') e++;
        if (str[i]=='W') w++;
    }
    if ((s && !n) || (!s && n) || (e && !w) || (!e && w)) cout << "No" << endl;
    else cout << "Yes" << endl;
    
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
