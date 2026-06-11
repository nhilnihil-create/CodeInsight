#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n);
  vector<ll> no = {-1};
  vector<ll> sub = {0};
  ll keep = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    if (a.at(i) > keep) {
      no.emplace_back(i);
      sub.emplace_back(a.at(i));
      keep = a.at(i);
    }
  }
  
  vector<ll> all(no.size()), rem(no.size());
  for (int i = 0; i < n; i++) {
    ll it = lower_bound(sub.begin(), sub.end(), a.at(i)) - sub.begin();
    all.at(it - 1)++;
    rem.at(it) += a.at(i) - sub.at(it - 1);
  }
  
  for (int i = no.size() - 2; i >= 0; i--) all.at(i) += all.at(i + 1);
  
  vector<ll> ans(n);
  for (int i = 1; i < no.size(); i++) {
    ans.at(no.at(i)) = all.at(i) * (sub.at(i) - sub.at(i - 1)) + rem.at(i);
  }
  
  for (int i = 0; i < n; i++) cout << ans.at(i) << '\n';
}