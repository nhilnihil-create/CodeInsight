#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,ans=0,P=1;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A.at(i);
  rep(i,N){
    if(i==0){
      ans+=A.at(i)-1;
      P++;
    }else if(A.at(i)==P){
      P++;
    }else{
      if(A.at(i)%P!=0){
        ans+=A.at(i)/P;
      }else{
        ans+=1;
        A.at(i)-=P+1;
        ans+=A.at(i)/P;
      }
    }
  }
  cout << ans << endl;
  
    
}