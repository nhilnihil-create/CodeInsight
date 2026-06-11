#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> routes(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    routes[x - 1] = routes[x - 1] + 1;
    routes[y - 1] = routes[y - 1] + 1;
  }

  for (int i = 0; i < N; i++) {
    cout << routes[i] << endl;
  }
}