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
  ll x;
  cin >> x;

  ll div11 = x / 11;
  ll rem = x - 11 * div11;

  if(rem == 0) cout << 2 * div11 << endl;
  else if(rem <= 6) cout << 2 * div11 + 1 << endl;
  else cout << 2 * div11 + 2 << endl;
  
  return 0;
}