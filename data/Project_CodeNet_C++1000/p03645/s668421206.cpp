#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a; i<n; i++)
using namespace std;;
 
int main() {
  int N,M; cin >> N >> M;
  vector<bool> firstS(N+1,false);
  vector<bool> secondS(N+1,false);
  
  rep(i,0,M) {
    int x,y; cin >> x >> y;
    if (x == 1) firstS[y] = true;
    if (y == N) secondS[x] = true;
  }
  
  rep(i,1,N+1) {
    if (firstS[i] && secondS[i]) {
      cout << "POSSIBLE" << endl; return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}