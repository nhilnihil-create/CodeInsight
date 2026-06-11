#include <bits/stdc++.h>
using namespace std;
int main() {
  int N ,K;
  int a = 0;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (0 < x < K) {
      if (x - 0 < K - x) {a += (x - 0) * 2; continue;}
      else {a += (K - x) * 2; continue;}
    }
    if (0 < K < x) {a += (K - x);}}
  cout << a << endl;
}