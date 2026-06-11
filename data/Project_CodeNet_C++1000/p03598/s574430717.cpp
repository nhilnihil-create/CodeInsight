#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int sum = 0;
  for (int i = 0; i < N; i++){
    int x;
    cin >> x;
    if (x <= K / 2){
      sum = sum + 2 * x;
    }
    else {
      sum = sum + 2 * (K - x);
    }
  }
  cout << sum << endl;
}

