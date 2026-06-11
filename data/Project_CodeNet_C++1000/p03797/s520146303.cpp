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
  ll N, M;
  cin >> N >> M;

  if(2 * N >= M){
    cout << M / 2 << endl;
  } else{
    ll ans = 0;

    ans += N;
    M -= 2 * N;

    ans += M / 4;

    cout << ans << endl;
  }
  
  return 0;
}