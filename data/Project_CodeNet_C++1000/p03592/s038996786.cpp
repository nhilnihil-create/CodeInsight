#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
using Graph = vector<vector<int>>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m, k;
  cin >> n >> m >> k;
  ll ans;
  bool f = false;
  Rep(h, 0, n){
    Rep(w, 0, m){
      ans = h*w + (n-h)*(m-w);
      if(ans == k) f = true;
    }
  }
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
