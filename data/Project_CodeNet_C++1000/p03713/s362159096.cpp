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

  if((H % 3 == 0) || (W % 3 == 0)){
    cout << 0 << endl;
    return 0;
  }

  ll h1 = H / 2;
  ll h2 = H / 2 + H % 2;
  ll s1, s2, s3;
  ll dif1 = (ll)pow(10, 10);

  rep2(i, 1, W){
    s1 = h1 * i;
    s2 = h2 * i;
    s3 = H * (W - i);
    
    dif1 = min(dif1, max(s2, s3) - min(s1, s3));
  }

  ll w1 = W / 2;
  ll w2 = W / 2 + W % 2;
  ll dif2 = (ll)pow(10, 10);

  rep2(i, 1, H){
    s1 = i * w1;
    s2 = i * w2;
    s3 = (H - i) * W;

    dif2 = min(dif2, max(s2, s3) - min(s1, s3));
  }
  
  cout << min(dif1, min(dif2, min(H, W))) << endl;
  
  return 0;
}
