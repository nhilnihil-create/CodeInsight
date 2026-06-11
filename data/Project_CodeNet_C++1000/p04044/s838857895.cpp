#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  int N, L;
  cin >> N >> L;
  vector<string> V(N);
  for (int i=0; i<N; i++) {
    cin >> V[i];
  }
  sort(V.begin(), V.end());
  for (int i=0; i<N; i++) {
    cout << V[i];
  }
  cout << endl;
}