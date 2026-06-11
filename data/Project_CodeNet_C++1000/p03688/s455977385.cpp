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
  ll N,ma=0,mi=INF,k=1;
  cin >> N;
  vec A(N);
  rep(i,N){
    cin >> A.at(i);
    if(ma==A.at(i)){
      k++;
    }else if(A.at(i)>ma){
      ma=max(ma,A.at(i));
      k=1;
    }
    mi=min(mi,A.at(i));
  }
  if(ma-mi>1){
    cout << "No" << endl;
    return 0;
  }
  if(ma-mi==0){
    if(N/2>=ma||N==ma+1){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    if(ma>N-k&&2*(ma-N+k)<=k){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}