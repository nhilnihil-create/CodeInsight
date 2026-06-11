#include<bits/stdc++.h>
using namespace std;

using T = tuple<int, int, int>;

int main() {
  int N;
  cin >> N;

  set<T> left, right;
  vector<int> ans(N*N + 1);
  for(auto i=1; i<=N; ++i) {
    int x;
    cin >> x;
    ans[x] = i;
    left.emplace(x-1, i-1, i);
    right.emplace(x+1, (N-1)-(i-1), i);
  }

  auto ng = []() {
    cout << "No" << endl;
    exit(0);
  };

  for(auto i=1; i<=N*N; ++i) if(!ans[i]) {
    while(!left.empty()) {
      int x, n, a;
      tie(x, n, a) = *begin(left);
      left.erase(begin(left));
      if(n == 0) continue;
      if(x < i) ng();
      ans[i] = a;
      left.emplace(x, n-1, a);
      break;
    }
    while(!right.empty()) {
      if(ans[i]) break;
      int x, n, a;
      tie(x, n, a) = *begin(right);
      right.erase(begin(right));
      if(n == 0) continue;
      if(i < x) ng();
      ans[i] = a;
      right.emplace(x, n-1, a);
      break;
    }
    if(!ans[i]) ng();
  }

  cout << "Yes" << endl;
  for(auto i=1; i<=N*N; ++i) cout << (i!=1 ? " " : "") << ans[i];
  cout << endl;
}
