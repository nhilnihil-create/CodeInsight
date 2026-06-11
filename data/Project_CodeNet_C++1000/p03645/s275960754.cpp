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

int n,m; 
vector <int> g[200005];
int  boat[200005] ; 
bool  vis[200005] , ok=false; 

void bfs(){ 
    queue <int> q;
    q.push(1);
    while (q.size()){
        int u=q.front();
        q.pop(); 
        vis[u] = true ; 
        for (auto &it: g[u]){
            boat[it]=min(boat[it],boat[u]+1);
            if (!vis[it]) q.push(it);
        }
    }
} 
 
signed main() 
{ 
    cin>>n>>m; 
    for (int i=0;i<m;i++){ 
        int u,v; 
        cin>>u>>v; 
        g[u].pb(v); 
        g[v].pb(u); 
    } 
    for (int i=2;i<=n;i++) boat[i] = 1000000000 ; 
    boat[0]=boat[1]=0; 
    bfs();
    if (boat[n]==2) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
/*
5 5
1 3
4 5
2 3
2 4
1 4
    1 -> 3
    1 -> 4 -> 5
    2 -> 3
    2 -> 4
*/
