#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  int N, K;
  cin >> N >> K;
  int l[N];
  rep(i, N) cin >> l[i];
  sort(l, l + N, greater<int>());
  int sum = 0;
  rep(i, K) sum +=l[i];
  cout << sum << endl;
}
    