#include "bits/stdc++.h"
using namespace std;

const int maxn = 200005;
using ll = long long;

vector<int> edges[maxn];

int main(int argc, char const *argv[])
{
//  freopen("in.txt", "r", stdin);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> v[26];
  for(int i = 0; i < n; i++){
    v[s[i] - 'a'].push_back(i);
  }
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ll val = lower_bound(v[s[i] - 'a'].begin(), v[s[i] - 'a'].end(), i) - v[s[i] - 'a'].begin();
    val = (n - 1 - i) - (v[s[i] - 'a'].size() - 1 - val);
    ans += val;
  }
  cout << ans + 1 << endl;

  return 0;
}