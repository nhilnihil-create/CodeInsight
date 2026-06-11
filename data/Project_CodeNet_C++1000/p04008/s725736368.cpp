#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma comment(linker, "/STACK:2000000")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'
using ll = long long;
#define int ll
using db = long double;
using ii = pair<int, int>;

const int N = 2e5 + 5, LG = 19, MOD = 1e9+7;
const int SQ =320;
const long double EPS = 1e-7;
vector<int> adj[100005];
int n, p, k, ans = 0;
int dfs(int node){
  int mx = 0;
  for(auto child : adj[node]){
    int x = dfs(child) + 1;
    if(x == k + (node == 1)){
      ans++;
    } else mx=max(mx,x);
  }
  return mx;
}
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  cin >> n >> k;

  f(i,1,n+1){
    cin >> p;
    if(i==1)ans+=p!=1;
    else adj[p].pb(i);
  }

  dfs(1);
  cout<<ans<<'\n';

  return 0;
}
