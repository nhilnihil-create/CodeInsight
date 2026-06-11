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
  ll N, T;
  cin >> N >> T;
  vl t(N);
  rep(i, N) cin >> t[i];

  ll X = 0;

  rep2(i, 1, N)
    X += (t[i] - t[i - 1] >= T) ? T : (t[i] - t[i - 1]);
  
  X += T;

  cout << X << endl;
  
  return 0;
}
