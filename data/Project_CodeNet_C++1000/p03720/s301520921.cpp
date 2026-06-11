#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n, m, a, b;
  cin >> n >> m;
  vector<int> ans(n);
  rep(i, m) {
    cin >> a >> b;
    ans[a-1] += 1;
    ans[b-1] += 1;
  }
  rep(i, n) cout << ans[i] << endl;
}

