#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  vl a(3*N);
  rep(i, 3*N) cin >> a[i];

  priority_queue<ll, vl, greater<ll>> que1;
  vl fromL(N + 1, 0);
  rep(i, N){
    fromL[0] += a[i];
    que1.push(a[i]);
  }

  rep2(i, 1, N + 1){
    que1.push(a[N - 1 +  i]);
    fromL[i] = fromL[i - 1] + a[N - 1 + i] - que1.top();
    que1.pop();
  }

  priority_queue<ll> que2;
  vl fromR(N + 1, 0);
  rep(i, N){
    fromR[0] += a[3*N - 1 - i];
    que2.push(a[3*N - 1 - i]);
  }

  rep2(i, 1, N + 1){
    que2.push(a[2*N - i]);
    fromR[i] = fromR[i - 1] + a[2*N - i] - que2.top();
    que2.pop();
  }

  ll ans = (ll)(-pow(10, 17));

  rep(i, N + 1){
    ans = max(ans, fromL[i] - fromR[N - i]);
    // cout << fromL[i] << ' ' << fromR[N - i] << endl;
  }

  cout << ans << endl;
  
  return 0;
}
