#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX;
const ll MOD = 998244353;

ll c[112345];
ll A[112345];
bool used[112345];
int root=-1;
bool dfs(const vector<vint>& g,int u){
  used[u] = true;
  ll sum = 0;
  ll maxc = 0;
  for(int v:g[u]){
    if(used[v]) continue;
    if(!dfs(g,v)) return false;
    sum += c[v];
    maxc = max(maxc,c[v]);
  }
  if(u==root){
    cerr << "!!!!!!!!" << endl;
    debug(sum);
    return A[u]==sum;
  }
  if(g[u].size()==1){
    c[u] = A[u];
    return true;
  }
  ll T = c[u] = 2*A[u]-sum;
  if(T<0 || sum < T) return false;
  ll L = (sum-T)/2;
  /*
  debug(u);
  debug(sum);
  debug(T);
  debug(L);
  */
  return L<=min(sum-maxc,sum/2);
}

int main() {
  int N;cin >> N;
  repeat(i,N) cin >> A[i];
  vector<vint> g(N);
  repeat(i,N-1){
    int a,b;cin >> a >> b;a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  repeat(i,N){
    if(root<0&&g[i].size()==1){
      root = i;
    }
  }
  cout << (dfs(g,root)? "YES":"NO") << endl;
  return 0;
}
