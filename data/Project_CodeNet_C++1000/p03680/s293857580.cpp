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
    

int main(){
  ll N,x=0,t=0;
  cin >> N;
  vec A(N);
  rep(i,N){
    cin >> A.at(i);
    A.at(i)--;
  }
  while(true){
    x=A.at(x);
    t++;
    if(x==1){
      cout << t << endl;
      return 0;
    }
    if(x==0){
      cout << -1 << endl;
      return 0;
    }
    if(t==N-1){
      cout << -1 << endl;
      return 0;
    }
  }
  
}
          
          
       