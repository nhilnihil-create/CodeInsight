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
    int r,c; cin>>r>>c; 
    string s; 
    for (int i=0;i<=c+1;i++) cout << "#";
    cout << endl;
    while (r--){
      cin>>s;
      cout << "#";
      for (int i=0;i<c;i++) cout << s[i];
      cout << "#"<<endl;
    }
    for (int i=0;i<=c+1;i++) cout << "#";
    cout << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
