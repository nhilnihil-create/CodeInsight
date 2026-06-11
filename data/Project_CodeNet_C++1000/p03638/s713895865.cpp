#include <bits/stdc++.h>
using namespace std;

int H, W, N, A, now = 0;

int makeNumber() {
  if (!A) {
    cin >> A;
    now++;
  }
  A--;
  return now;
}

void makeVector(int n) {
  vector<int> V(W);
  for (int i = 0; i < W; i++) V.at(i) = makeNumber();
  if (n % 2) reverse(V.begin(), V.end());
  for (int i = 0; i < W; i++) {
    if (i != 0) cout << " ";
    cout << V.at(i);
  }
  cout << "\n";
}

int main() {
  cin >> H >> W >> N;
  for (int i = 0; i < H; i++) makeVector(i);
}