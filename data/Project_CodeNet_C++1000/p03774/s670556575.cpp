#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pp> V(N), P(M);
  for (int i=0; i<N; i++) {
    cin >> V[i].first >> V[i].second;
  }
  for (int i=0; i<M; i++) {
    cin >> P[i].first >> P[i].second;
  }
  
  int INF=1000000000, m, mv;
  for (int i=0; i<N; i++) {
    mv=INF;
    for (int j=0; j<M; j++) {
      if (mv>abs(V[i].first-P[j].first)+abs(V[i].second-P[j].second)) {
        mv=abs(V[i].first-P[j].first)+abs(V[i].second-P[j].second);
        m=j+1;
      }
    }
    cout << m << endl;
  }
  
}
