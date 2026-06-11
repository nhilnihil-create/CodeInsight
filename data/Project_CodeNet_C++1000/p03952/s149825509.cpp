#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, x;
  cin >> N >> x;
  if (x == 1 || x == 2 * N - 1) {
    cout << "No" << endl;
    return 0;
  }
  vector<int> ans(2 * N - 1);
  for (int i = 0; i < 2 * N - 1; i++)
    ans[i] = ((x - N) + i + 2 * N - 1) % (2 * N - 1) + 1;

  cout << "Yes" << endl;
  for (int a : ans) {
    cout << a << endl;
  }
}