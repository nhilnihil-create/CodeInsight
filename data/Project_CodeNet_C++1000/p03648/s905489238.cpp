#include <bits/stdc++.h>
using namespace std;

//const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll k;
  cin >> k;
  cout << 50 << endl;
  ll a[50];
  for (int i = 0; i < 50; i++) {
    a[i] = i+k/50;
  }
  for (int i = 0; i < k%50; i++) {
    a[49-i]++;
  }
  for (int i = 0; i < 50; i++) {
    cout << a[i];
    if (i != 49) cout << " ";
    else cout << endl;
  }
  return 0;
}
