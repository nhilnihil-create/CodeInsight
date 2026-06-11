#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1e17;
#define all(v) v.begin(), v.end()

int main(){
  ll N,ans=0;
  cin >> N;
  map<ll,ll> A;
  rep(i,N){
    ll a;
    cin >> a;
    A[a-1]=i;
  }
  set<ll> B;
  rep(i,N){
    if(i==0){
      ans+=(A.at(i)+1)*(N-A.at(i))*(i+1);
      B.insert(A.at(i));
    }else{
      auto a=B.lower_bound(A.at(i));
      if(a==B.begin()){
        ans+=(A.at(i)+1)*(*a-A.at(i))*(i+1);
        B.insert(A.at(i));
      }else if(a==B.end()){
        a--;
        ans+=(A.at(i)-*a)*(N-A.at(i))*(i+1);
        B.insert(A.at(i));
      }else{
        auto b=a;
        b--;
        ans+=(A.at(i)-*b)*(*a-A.at(i))*(i+1);
        B.insert(A.at(i));
      }
    }
  }
  cout << ans << endl;
}