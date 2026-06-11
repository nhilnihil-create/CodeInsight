#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-6
#define MOD 1000000007

#define fi first
#define se second
#define pb push_back
#define ende '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mset(x, y) memset(&x, (y), sizeof(x))

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, T, t;
  cin >> n >> T >> t;
  int ans = 0;
  int abriu_em = t;
  int fecha_em = t+T;
  while (cin >> t) {
    if (t <= fecha_em)
      fecha_em = t+T;
    else { //vai fechar em algum momento
      ans += fecha_em - abriu_em;
      abriu_em = t;
      fecha_em = t + T; 
    }
  }
  ans += fecha_em - abriu_em;
  cout << ans << ende;
  return 0;
}
