#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int tmp;
    cin >> tmp;
    mp[tmp]++;
  }
  int count = 0;
  for (auto i : mp) {
    if (i.second % 2 == 1) count++;
  }
  cout << count << endl;
  return 0;
}