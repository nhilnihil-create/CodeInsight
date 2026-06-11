#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

bool ans[100010];

int main() {
  ll n, m; cin >> n >> m;
  Vl x(m), y(m);
  rep(i, 0, m){
    cin >> x[i] >> y[i];
  }

  Vl cnt(n+1, 1);
  ans[1] = true;

  rep(i, 0, m){
    cnt[x[i]]--;
    cnt[y[i]]++;
    if(ans[x[i]]) ans[y[i]] = true;
    if(cnt[x[i]] == 0) ans[x[i]] = false;
  }


  ll sum = 0;
  Rep(i, 1, n) if(ans[i]) sum++;
  cout << sum << endl;
  
  return 0;
}
