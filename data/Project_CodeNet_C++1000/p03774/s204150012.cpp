#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int N, M;
pii A[55];
pii B[55];

int dist(int a, int b, int x, int y) {
  return abs(a - x) + abs(b - y);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  for(int i = 1; i <= M; i++) {
    cin >> B[i].first >> B[i].second;
  }
  for(int j = 1; j <= N; j++) {
    int best = 1e9, bestid = 0;
    for(int i = 1; i <= M; i++) {
      if(dist(A[j].first, A[j].second, B[i].first, B[i].second) < best) {
        best = dist(A[j].first, A[j].second, B[i].first, B[i].second);
        bestid = i;
      }
    }
    cout << bestid << "\n";
  }
}