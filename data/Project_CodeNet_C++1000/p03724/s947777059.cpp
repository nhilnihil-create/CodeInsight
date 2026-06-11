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
#include <list>
#include <stack>
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

signed main()
{
    int n,m;
    map <int,int> cnt;
    cin >>n >> m;
    for (int i=1;i<=m;i++){
        int a,b; cin >> a>>b;
        cnt[a]++,cnt[b]++;
    }
    bool ok=true;
    for (int i=1;i<=n;i++){
        if (cnt[i]&1) ok=false;
    }
    cout << ((ok)?"YES":"NO") << endl;
    return 0;
}
