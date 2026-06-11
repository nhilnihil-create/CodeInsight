#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  ll ai, ao, at, aj, al, as, az; cin >> ai >> ao >> at >> aj >> al >> as >> az;

  ll cnt1 = 0, cnt2 = 0;
  cnt1 = ao + ai - ai % 2 + aj - aj % 2 + al - al % 2;
  ai--; aj--; al--;
  if(ai >=0 && aj >= 0 && al >= 0) cnt2 = ao + ai - ai % 2 + aj - aj % 2 + al - al % 2 + 3;

  cout << max(cnt1, cnt2) << endl;
}
