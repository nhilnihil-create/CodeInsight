#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int p[N];
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    p[i]--;
  }
  int plus[N];
  for (int i = 0; i < N; i++) {
    plus[p[i]] = i;
  }
  ll a[N];
  ll b[N];
  a[0] = 0;
  b[0] = plus[0];
  for (int i = 1; i < N; i++) {
    a[i] = a[i-1] + 1;
    b[i] = plus[i] - a[i];
    if (a[i-1] < a[i] && b[i-1] > b[i]) {
      
    } else {
      b[i] = b[i-1] - 1;
      a[i] = plus[i] - b[i];
    }
  }
  ll big = 500000000;
  for (int i = 0; i < N; i++) {
    cout << a[i] + big << " ";
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    cout << b[i] + big << " ";
  }
  cout << endl;
  return 0;
}