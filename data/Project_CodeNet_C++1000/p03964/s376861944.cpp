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

  vvl TA(N, vl(2, 0));
  rep(i, N){
    cin >> TA[i][0] >> TA[i][1];
  }

  vl mul(N, 1);
  rep2(i, 1, N){
    ll m1 = 1, m2 = 1;
    
    if(TA[i][0]*mul[i]<TA[i-1][0]*mul[i-1]){
      m1 = TA[i-1][0]*mul[i-1]/TA[i][0];
      
      if(TA[i-1][0]*mul[i-1] % TA[i][0] != 0){
		m1++;
      }
    }
    if(TA[i][1]*mul[i]<TA[i-1][1]*mul[i-1]){
      m2 = TA[i-1][1]*mul[i-1]/TA[i][1];

      if(TA[i-1][1]*mul[i-1] % TA[i][1] != 0){
		m2++;
      }
    }

    mul[i] = max(m1, m2);
  }

  cout << mul[N-1]*(TA[N-1][0] + TA[N-1][1]) << endl;
  
  return 0;
}