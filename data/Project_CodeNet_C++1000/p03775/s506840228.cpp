#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

ll digit(ll n){
  ll i=1;
  while(n/(ll)pow(10,i)>0){
    i++;
  }
  return i;
}

int main(){
  ll N,ans=INF;
  cin >> N;
  for(ll i=1;i*i<=N;i++){
    if(N%i==0){
      ans=min(ans,max(digit(i),digit(N/i)));
    }
  }
  cout << ans << endl;
}
          
          