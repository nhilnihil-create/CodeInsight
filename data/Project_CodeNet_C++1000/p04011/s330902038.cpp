#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,X,Y;
  cin >> N >> K >> X >> Y;
  int total_cost = 0;

  for(int i=0; i < N; i++) {
    if (i < K) {
      total_cost += X;
    } else {
      total_cost += Y;
    }
  }
  cout << total_cost << endl;
}