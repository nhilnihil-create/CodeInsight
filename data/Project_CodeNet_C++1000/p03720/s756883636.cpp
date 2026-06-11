#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int n, m;
int f[maxn];
int main() {
  cin>>n>>m;
  for (int i=1; i<=m; i++) {
    int u,v;
    cin>>u>>v;
    f[u]++;
    f[v]++;
  }
  
  for (int i=1; i<=n; i++) {
    cout<<f[i]<<"\n";
  }
  return 0;
  
}