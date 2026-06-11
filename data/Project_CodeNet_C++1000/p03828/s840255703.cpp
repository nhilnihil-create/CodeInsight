#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;

map<ll, ll> res;
const int mod = 1000000007;

void prime_factor(ll n){
  for (ll i = 2; i * i <= n; i++){
    while (n % i == 0){
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) res[n]++;
}

int main(){
  ll n;
  cin >> n;
  for (ll i = 2; i <= n; i++) prime_factor(i);
  ll ans = 1;
  for (auto tmp : res) {
    ll num = tmp.second + 1;
    ans = (ans * num) % mod;
  }
  cout << ans << endl;
}