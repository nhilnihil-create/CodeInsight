#include <bits/stdc++.h>
using namespace std;

#define int long long

int N, K;
vector<int> G[100001];
int ans = 0;

int dfs(int v, bool f) {  
  if ( G[v].size() == 0 ) return 1;
  int ma = (int)0;  
  for ( int u : G[v] ) {
    if ( u == v ) continue;    
    if ( v ) ma = max(ma, dfs(u, false)+1);
    if ( !v ) ma = max(ma, dfs(u, true)+1);    
  }

  if ( ma >= K ) {
    if ( v && !f ) ans++;
    // cout << v << " " << ma << endl;
    return 0;    
  } else {
    return ma;    
  }
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> K;

  int not1 = 0;
  vector<int> A(N);  
  for ( int i = 0; i < N; i++ ) {
    int a;
    cin >> a;
    a--;    
    A[i] = a;    
    if ( a ) not1++;
    if ( i == 0 ) {
      if ( a ) ans++;      
    } else {
      G[a].push_back(i);
    }
  }

  if ( K == 1 ) {
    cout << not1 << endl;    
  } else {
    dfs(0, true);    
    cout << ans << endl;    
  }
  
  return 0;
}
