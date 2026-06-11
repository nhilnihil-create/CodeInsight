#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,ans=0;
  cin >> N;
  vector<ll> A(N);
  rep(i,N){
    cin >> A.at(i);
  }
  rep(i,N){
    ans+=A.at(i)/2;
    if(i!=N-1&&A.at(i+1)>0&&A.at(i)%2==1){
      A.at(i+1)--;
      ans++;
    }
  }
  cout << ans << endl;
    
}