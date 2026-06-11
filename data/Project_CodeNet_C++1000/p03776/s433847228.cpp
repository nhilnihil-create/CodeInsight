#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

vvl arr(51, vl(51, -1));

ll comb(ll n, ll r){
  if((n == r) || (r == 0)) return 1;
  if(arr[n][r] != -1) return arr[n][r];

  ll ans = comb(n - 1, r) + comb(n -1 , r - 1);
  arr[n][r] = ans;

  return ans;
}

int main(){
  ll N, A, B;
  cin >> N >> A >> B;
  vl v(N);
  map<ll, ll> cnt;
  rep(i, N){
    cin >> v[i];
    cnt[v[i]]++;
  }

  stable_sort(v.begin(), v.end(), greater<ll>());

  ll sum = 0;
  rep(i, A) sum += v[i];

  ld max_ave = (ld)sum / (ld)A;
  cout << fixed << setprecision(10) << max_ave << endl;

  ll ans = 0;

  rep2(i, A, B + 1){
    if(sum * i % A != 0) continue;

    ll s2 = sum * i / A;
    rep(j, i) s2 -= v[j];
    if(s2 > 0) continue;

    ll n = cnt[v[i - 1]];
    ll r = 0;
    while((v[i - r -1] == v[i - 1]) && (r <= i - 1)) r++;

    ll pat = comb(n, r);
    ans += pat;
  }

  cout << ans << endl;
  
  return 0;
}
