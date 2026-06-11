#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int N;
  cin >> N;
  ll A[N],B[N];
  ll num = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  for (int i = N-1; i >= 0; i--) {
    num += (B[i] - ((num + A[i]) % B[i])) % B[i];
  }
  cout << num << endl;
  return 0;
}