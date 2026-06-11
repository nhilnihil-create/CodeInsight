#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i=0;i<n;i++)

int main() {
  string a;
  cin >> a;
  vector<vector<int>> al(26);
  rep(i, a.size()) al[a[i]-'a'].emplace_back(i);
  ll b = 0;
  rep(i, al.size()) {
    ll s = al[i].size();
    b += s * (s - 1) / 2;
  }
  ll as = a.size();
  ll total = as * (as - 1) / 2;
  cout << total - b + 1 << endl;
}
