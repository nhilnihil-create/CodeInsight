#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  std::vector<int> v(n);
  rep(i,n) cin >> v.at(i);
  sort(v.begin(), v.end(), greater<int>());
  int total = accumulate(v.begin(), v.begin() + k, 0);
  cout << total << endl;
}
