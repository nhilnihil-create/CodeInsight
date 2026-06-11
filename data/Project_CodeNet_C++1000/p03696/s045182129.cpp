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
    int len; cin>>len;
    string  s; cin >> s;
    int  f=0,se=0;
    for (int i=0;i<len;i++){
        if (s[i]==')') {
            if (f) f--;
            else se++;
        }
        else f++;
    } 
    for (int i=0;i<se;i++) cout << "(";
    cout << s;
    for (int i=0;i<f;i++) cout << ")";
    cout << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
