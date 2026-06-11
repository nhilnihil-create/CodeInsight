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

ll MOD = 1000000007;

int main(){
  ll N;
  cin >> N;
  string s;
  vvc ss(2, vc(N));
  rep(i, 2){
    cin >> s;

    rep(j, N) ss[i][j] = s[j];
  }
  
  ll h = 0, w = 0;
  ll ans = 1;
  
  while(w < N){
    if(w == 0){
      if(ss[0][0] == ss[1][0]){
        ans *= 3;
        ans %= MOD;
      } else{
        ans *= 6;
        ans %= MOD;
      }
    } else{
      if(ss[0][w - 1] == ss[1][w - 1]){
		ans *= 2;
		ans %= MOD;
      } else if(ss[0][w] != ss[1][w]){
        ans *= 3;
        ans %= MOD;
      }
    }

    if(ss[0][w] == ss[1][w])
      w++;
    else
      w += 2;
  }
  
  cout << ans << endl;
    
  return 0;
}
