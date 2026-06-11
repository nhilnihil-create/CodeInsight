#include <bits/stdc++.h>
using namespace std;

vector<int> g[100009];
int dfs(int cur) {
  vector<int> num;
  for (int to: g[cur]) {
    num.push_back(dfs(to));
  }
  sort(num.begin(), num.end());
  int ans = 0;
  for (int n: num) {
    ans += max(n - ans, 0) + 1;
  }
  return ans;
}
int main() {
  int n;
  cin>>n;
  for (int i=1; i<n; i++) {
    int a;
    cin>>a;
    --a;
    g[a].push_back(i);
  }
  cout<<dfs(0)<<endl;
}