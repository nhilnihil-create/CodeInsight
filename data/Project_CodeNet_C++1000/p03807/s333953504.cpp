#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    ans = (ans + A % 2) % 2;
  }
  if (ans) cout << "NO" << endl;
  else cout << "YES" << endl;
}