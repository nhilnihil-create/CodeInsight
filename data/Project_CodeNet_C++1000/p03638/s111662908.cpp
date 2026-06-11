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
  ll H, W;
  cin >> H >> W;
  ll N;
  cin >> N;
  vl a(N);
  rep(i, N) cin >> a[i];

  vvl c(H, vl(W, 0));
  ll h = 0, w = 0, d = 1;
  rep(i, N){
    rep(j, a[i]){
      c[h][w] = i + 1;

      if(d == 1){
	if(w == W - 1){
	  h++;
	  d = -1;
	} else{
	  w++;
	}
      } else{
	if(w == 0){
	  h++;
	  d = 1;
	} else{
	  w--;
	}
      }
    }
  }

  rep(i, H){
    rep(j, W){
      cout << c[i][j] << ' ';
    }
    cout << endl;
  }
  
  return 0;
}
