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

vl g1 = {1, 3, 5, 7, 8, 10, 12};
vl g2 = {4, 6, 9, 11};

int main(){
  ll x, y;
  cin >> x >> y;

  ll gx = 0, gy = 0;

  rep(i, g1.size()){
    if(g1[i] == x) gx = 1;
    if(g1[i] == y) gy = 1;
  }
  rep(i, g2.size()){
    if(g2[i] == x) gx = 2;
    if(g2[i] == y) gy = 2;
  }
  if(x == 2) gx = 3;
  if(y == 2) gy = 3;

  if(gx == gy) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
