#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(N), c(M), d(M), distance(N, 2000000000), point(N);
  for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
  for (int i = 0; i < M; i++) cin >> c[i] >> d[i];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int tmp = abs(a[i]-c[j]) + abs(b[i]-d[j]);
      if (distance[i] > tmp) {
        distance[i] = tmp;
        point[i] = j+1;
      }
    }
  }
  for (int i = 0; i < N; i++) cout << point[i] << endl;
}
