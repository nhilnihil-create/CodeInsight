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
  ll A, B;
  cin >> A >> B;

  if((A % 3 == 0) || (B % 3 == 0) || ((A + B) % 3 == 0))
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  
  return 0;
}
