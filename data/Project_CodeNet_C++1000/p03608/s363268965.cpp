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
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

int n,m,r;
int dis[205][205];

signed main()
{
    for (int i=0;i<=201;i++){
      for (int j=0;j<=201;j++){
        dis[i][j] = 1e9 ;
      }
    }
    cin >> n >> m >> r ; 
    vi a(r);
    for (int &it: a) cin >> it ; 
    for (int i=1;i<=m;i++){
        int  x, y, c ; 
        cin >> x >> y >> c ; 
        dis[x][y] = dis[y][x] = min(dis[x][y], c) ; 
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                dis[i][j] = min( dis[i][j], dis[i][k]+dis[k][j] ) ; 
            }
        }
    }
    int ans = 1e9 ; 
    sort(all(a));
    do {
        int sum = 0;
        for (int i=1;i<r;i++){
            sum += dis[a[i]][a[i-1]];
        }
        ans = min(ans, sum) ; 
    }
    while (next_permutation(a.begin(),a.end()));
    co ( ans ) ; 
    return 0;
}
