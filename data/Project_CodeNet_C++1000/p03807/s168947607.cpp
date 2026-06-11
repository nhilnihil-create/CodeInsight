#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  ll odd = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] % 2 == 1) {
      odd++;
    }
  }
  if (odd % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}