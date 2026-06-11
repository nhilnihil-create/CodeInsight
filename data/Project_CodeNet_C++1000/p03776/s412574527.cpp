#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 50;

ll comb[MAX + 1][MAX + 1];

ll calc_comb(ll n, ll r){
  if(comb[n][r] != 0) return comb[n][r];
  ll ret = -1;
  if(n == r) ret = 1;
  else if(r == 0) ret = 1;
  else if(r == 1) ret = n;
  if(ret != -1) {
    comb[n][r] = ret; return ret;
  }
  
  ret = calc_comb(n-1, r-1) + calc_comb(n-1, r);
  comb[n][r] = ret; return ret;
}

int main(){
  ll N, A, B; cin >> N >> A >> B;
  vector<ll> val(N);
  for(ll i = 0; i < N; i++){
    cin >> val[i];
  }
  sort(val.begin(), val.end(), greater<ll>());
  
  double ans = 0.0;
  ll pat = 0LL;
  if(*val.begin() == *(val.begin()+A-1)){
    cout << fixed << setprecision(10) << (double)val[0] << endl;
    ll fin = A-1;
    while(val[fin] == val[0] && fin < N){
      fin++;
    }
    ll lim = min(fin, B);
    for(ll i = A; i <= lim; i++){
      pat += calc_comb(fin, i);
    }
    cout << pat << endl;
  }else{
    ll tmp = 0;
    for(ll i = 0; i < A; i++){
      tmp += val[i];
    }
    ans = (double)tmp / (double)A;
    cout << fixed << setprecision(10) << ans << endl;
    
    ll fst = A-1, scd = A-1, vmin = val[A-1];
    while(val[fst-1] == vmin){
      fst--;
    }
    while(val[scd] == vmin && scd < N){
      scd++;
    }
    pat = calc_comb(scd - fst, A - fst);
    cout << pat << endl;
  }
  return 0;
}