#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int ans = 1000000000;
  for (int i = a.front(); i <= a.back(); i++) {
    int temp = 0;
    for (int j = 0; j < N; j++) {
      temp += (a[j] - i) * (a[j] - i);
    }
    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}