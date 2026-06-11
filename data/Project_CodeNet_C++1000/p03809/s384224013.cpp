#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define ff first
#define ss second
#define mp make_pair

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define MOD 1000000007LL
#define N 100005

vector<int> adj[N];
ll val[N];

void dfs(int v, int p){
   if(p && adj[v].size() == 1) return;

   long long s = 0, big = 0;
   for(int x : adj[v]){
      if(x == p) continue;
      dfs(x, v);
      s += val[x];
      big = max(big, val[x]);
   }
   ll a, b, mx;
   mx = min(s / 2, s - big);
   a = s - val[v];
   b = val[v] - a;
   if(a < 0 || b < 0 || a > mx){
      cout<<"NO";
      exit(0);
   }

   val[v] = b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
   int n;
   cin>>n;

   for(int i = 1; i <= n; i++){
      cin>>val[i];
   }
   for(int i = 1; i < n; i++){
      int v, u;
      cin>>v>>u;
      adj[v].pb(u);
      adj[u].pb(v);
   }
   if(n == 2){
      cout<< (val[1] == val[2] ? "YES" : "NO");
      return 0;
   }

   int t = 1;
   while(adj[t].size() == 1) t++;

   dfs(t, 0);
   if(!val[t])cout<<"YES";
   else cout<<"NO";
}
