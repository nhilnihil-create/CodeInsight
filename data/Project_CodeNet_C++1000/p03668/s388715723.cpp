#include <bits/stdc++.h>
using namespace std; 

const int N = 1e5; 

int n; 
vector<int> g[N + 2]; 
int SG[N + 2];
void dfs (int foo, int p) {
  SG[foo] = 0; 
  for (int bar : g[foo]) {
    if (bar == p) continue; 
    dfs(bar, foo); 
    SG[foo] ^= SG[bar] + 1; 
  }
} 
int main() {
  //freopen("in.inp", "r", stdin); freopen("in.out", "w", stdout); 
  
  scanf("%d", &n); 
  for (int ie = 1; ie < n; ie++) {
    int foo, bar; 
    scanf("%d %d", &foo, &bar); 
    g[foo].push_back(bar); 
    g[bar].push_back(foo); 
  }
  dfs(1, 0);
  if (SG[1] != 0) {
    printf("Alice\n"); 
  } else {
    printf("Bob\n"); 
  } 
}