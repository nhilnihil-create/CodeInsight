#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  ll N,sum=0,ans=0;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A.at(i);
    rep(i,N){
      if(i==0){
        if(A.at(i)>0){
          sum+=A.at(i);
          continue;
        }else{
          sum=1;
          ans+=1-A.at(i);
          continue;
        }
      }
      if(sum>0){
        if(sum+A.at(i)<0){
          sum+=A.at(i);
        }else{
          ans+=sum+A.at(i)+1;
          sum=-1;
        }
      }else{
        if(sum+A.at(i)>0){
          sum+=A.at(i);
        }else{
          ans+=1-(sum+A.at(i));
          sum=1;
        }
      }
    }
    ll ans1=0;
    sum=0;
    rep(i,N){
      if(i==0){
        if(A.at(i)<0){
          sum+=A.at(i);
          continue;
        }else{
          sum=-1;
          ans1+=1+A.at(i);
          continue;
        }
      }
      if(sum>0){
        if(sum+A.at(i)<0){
          sum+=A.at(i);
        }else{
          ans1+=sum+A.at(i)+1;
          sum=-1;
        }
      }else{
        if(sum+A.at(i)>0){
          sum+=A.at(i);
        }else{
          ans1+=1-(sum+A.at(i));
          sum=1;
        }
      }
    }
    cout << min(ans,ans1) << endl;

}