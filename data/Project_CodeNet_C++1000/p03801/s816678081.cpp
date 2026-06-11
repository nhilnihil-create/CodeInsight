#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){

  
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  vector < pair < ll, ll > > a(n);
  vector < int > b(n);

  ll ma = 0;

  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
    b[i] = ma;
    ma = max(ma, a[i].first);
  }

  vector < ll > ans(n);

  sort(a.begin(), a.end(), [](pair <ll, ll> x, pair <ll, ll> y) {
    return x.first > y.first || (x.first == y.first && x.second < y.second);
  });

  ll cnt = 0;

  for (int i = 0; i < n;) {
    int j = i;
    ll ret = 0;
    ll tem = cnt;

    while (j < n && a[j].first >= b[a[i].second] && a[j].second >= a[i].second) {
      cnt++;
      ret += a[j].first - b[a[i].second];
      j++;
    }


    ans[a[i].second] = ret + tem * (a[i].first - b[a[i].second]);
    i = j;
  }

  for (auto i : ans)
    cout << i << '\n';

  return 0;

}
