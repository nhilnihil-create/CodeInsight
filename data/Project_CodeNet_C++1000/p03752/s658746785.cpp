#include<iostream>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  long min_cost = (1L<<60);
  for (int b = 0; b < (1<<N); b++) {
    long cost = 0;
    int max_h = 0;
    int color_num = 0;
    int B[N]; for (int i = 0; i < N; i++) B[i] = A[i];
    for (int i = 0; i < N; i++) {
      if (b & (1<<i)) {
        cost += max(0, max_h + 1 - B[i]);
        B[i] = max(B[i], max_h + 1);
        if (B[i] > max_h) color_num++;
      }
      max_h = max(max_h, B[i]);
    }
    if (color_num >= K) min_cost = min(min_cost, cost);
  }
  cout << min_cost << endl;
}