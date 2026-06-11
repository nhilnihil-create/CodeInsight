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
  ll a;
  ll cnt4 = 0, cntodd = 0;
  rep(i, N){
    cin >> a;

    if(a % 2 == 1)
      cntodd++;
    if(a % 4 == 0)
      cnt4++;
  }

  if(cntodd <= cnt4)
    cout << "Yes" << endl;
  else if((cntodd == cnt4 + 1) && (cntodd + cnt4 == N))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}
