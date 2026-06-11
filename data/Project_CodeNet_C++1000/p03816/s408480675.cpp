#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  map<int, int> A;

  rep(i, N) {
    int a; cin >> a;
    A[a]++;
  }

  int ans = 0;
  int two = 0;
  for(auto a : A) {
    if(a.second == 1) {
      ans++;
      continue;
    }

    if(a.second == 2) {
      two++;
      continue;
    }

    if(a.second % 2 == 1) {
      ans++;
      continue;
    }

    if(a.second % 2 == 0) {
      two++;
    }
  }

  ans += two % 2 == 0 ? two : two - 1;

  cout << ans << endl;
}
