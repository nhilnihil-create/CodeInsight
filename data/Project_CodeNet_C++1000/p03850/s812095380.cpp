#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int N, A[100000];
  char op[100000];

  cin >> N;
  cin >> A[0];
  for(int i = 1; i < N; i++) {
    cin >> op[i] >> A[i];
  }

  int64 all = A[0];
  for(int i = 1; i < N; i++) {
    if(op[i] == '+') all += A[i];
    else all -= A[i];
  }

  int64 cost = 0, ans = all, add = 0;
  for(int i = N - 1; i > 0; i--) {
    if(op[i] == '+') {
      cost += 2 * A[i];
    } else {
      ans = max(ans, all + add - cost);
      add += 2 * A[i];
      cost = 0;
    }
  }

  cout << ans << endl;
}