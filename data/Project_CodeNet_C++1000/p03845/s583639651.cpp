#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int N, S=0;
  cin >> N;
  vector<int> T(N);
  for (int i=0; i<N; i++) {
    cin >> T[i];
    S+=T[i];
  }
  int M;
  cin >> M;
  int p, x, m=0;
  for (int i=0; i<M; i++) {
    cin >> p >> x;
    cout << S-T[p-1]+x << endl;
  }
}