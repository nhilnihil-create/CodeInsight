#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N; i++){
    int A, B;
    cin >> A >> B;
    sum = sum + B - A + 1;
  }
  cout << sum;
}

