/*
          ,     \    /      ,
         / \    )\__/(     / \
        /   \  (_\  /_)   /   \
   ____/_____\__\@  @/___/_____\____
  |             |\../|              |
  |              \VV/               |
  |        ------hoi-------         |
  |_________________________________|
   |    /\ /      \\       \ /\    |
   |  /   V        ))       V   \  |
   |/     `       //        '     \|
   `              V                '
*/

#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define pb push_back
#define f first
#define se second
#define mp make_pair
#define Speedforce boost();

using namespace std;

void boost(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int N = 1e6;
const int inf = 1e9 + 7;

int n, k, ans = 1e9;
vector <int> g[N];
int cur;

void dfs1(int v, int pr = -1, int len = 0){
    if(len > k / 2){
        cur ++;
    }
    for(int i = 0;i < g[v].size();i ++){
        int to = g[v][i];
        if(to != pr){
            dfs1(to, v, len + 1);
        }
    }
}

void dfs2(int v){
    for(int i = 0;i < g[v].size();i ++){
        cur = 0;
        int to = g[v][i];
        dfs1(v, to);
        dfs1(to, v);
        ans = min(cur, ans);
    }
}

int main() {
    Speedforce
    cin >> n >> k;
    for(int i = 1;i < n;i ++){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    if(k & 1){
        for(int i = 1;i <= n;i ++){
            dfs2(i);
        }
    }
    else{
        for(int i = 1;i <= n;i ++){
            cur = 0;
            dfs1(i);
            ans = min(ans, cur);
        }
    }
    cout << ans;
}