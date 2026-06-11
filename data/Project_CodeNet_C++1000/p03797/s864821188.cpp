#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  ll N, M;
  cin >> N >> M;
  
  if (M <= 2 * N) {
    cout << M / 2 << endl;
  } else {
    cout << N + (M - 2 * N) / 4 << endl;
  }
  
}