#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int w, h;
  cin >> w >> h;
  
  vector<ll> p(w), q(h);
  for (int i = 0; i < w; i++) cin >> p.at(i);
  for (int i = 0; i < h; i++) cin >> q.at(i);
  
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());
  
  p.emplace_back(1e9);
  q.emplace_back(1e9);
  
  int itp = 0, itq = 0;
  ll ans = 0;
  while (itp < w || itq < h) {
    if (p.at(itp) < q.at(itq)) {
      ans += p.at(itp) * (h + 1 - itq);
      itp++;
    }
    else {
      ans += q.at(itq) * (w + 1 - itp);
      itq++;
    }
  }
  
  cout << ans << '\n';
}