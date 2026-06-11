#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int a;
    cin >> a;
    mp[a]++;
  }
  bool ans = true;
  int k = 0;
  for(auto v : mp) k = max(k, v.first);
  for(int i = k; i >= (k + 1) / 2; i--) {
    int num = k % 2 ? 2 : 1;
    if(mp[i] < num)
      ans = false;
    else
      mp[i] -= num;
  }
  for(auto v : mp)
    if(v.first <= (k + 1) / 2 && v.second > 0) ans = false;
  cout << (ans ? "Possible" : "Impossible") << endl;
}