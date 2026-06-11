#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N;
  M = N % 10;
  N /= 10;
  if (N == 9 || M == 9)
    cout << "Yes" << endl;
  else cout << "No" << endl;
}