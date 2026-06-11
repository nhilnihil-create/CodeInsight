#include <iostream>
using namespace std;
using ll = long long;
ll N, A, B, C, D; 

int main() {
  cin >> N >> A >> B >> C >> D;
  for(int P = 0; P < N; ++P) {
    int M = N - 1 - P;
    if(P * C - M * D <= B - A && B - A <= P * D - M * C) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
  return 0;
}