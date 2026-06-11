#include <bits/stdc++.h>
using namespace std;

int H, W, N, A, now = 0;

int f1() {
  if (!A) {
    cin >> A;
    now++;
  }
  A--;
  return now;
}

void f2(int i) {
  vector<int> V(W);
  for (int i = 0; i < W; i++) V.at(i) = f1();
  if (i % 2) reverse(V.begin(), V.end());
  for (int i = 0; i < W; i++) {
    if (i != 0) cout << " ";
    cout << V.at(i);
  }
  cout << "\n";
}

int main() {
  cin >> H >> W >> N;
  for (int i = 0; i < H; i++) f2(i);
}