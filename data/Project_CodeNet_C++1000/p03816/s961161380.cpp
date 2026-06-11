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

  map<ll, ll> cnt;
  ll A;
  rep(i, N){
    cin >> A;
    cnt[A]++;
  }

  ll odd = 0, even = 0;
  for(auto itr = cnt.begin(); itr != cnt.end(); itr++){
    if((itr->second) % 2) odd++;
    else even++;
  }

  odd += 2 * (even / 2);

  cout << odd << endl;
  
  return 0;
}