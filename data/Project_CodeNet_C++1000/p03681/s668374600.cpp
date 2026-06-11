#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

ll fact_mod(ll N, ll MOD){
  ll retval = 1;
  rep(i,N) (retval *= (i+1))%= MOD;
  return retval;
}

int main(){
  ll N, M; cin >> N >> M;
  ll MOD = 1000000007;
  ll retval;
  if (abs(N-M)>1) {
    retval = 0;
  }
  else if (abs(N-M)==1){
    retval = fact_mod(N,MOD)*fact_mod(M,MOD)%MOD;
  }
  else retval = 2*fact_mod(N,MOD)*fact_mod(M,MOD)%MOD;

  cout << retval << endl;

  

  
  // cout << fixed << setprecision(10);
  
  return 0;
}
