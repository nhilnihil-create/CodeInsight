#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int main(){
  ll N;cin>>N;
  vll a(N);rep(i,N)cin>>a[i];
  vll cumsum(N);
  cumsum[0]=a[0];
  for(int i=1;i<N;++i){
    cumsum[i]=cumsum[i-1]+a[i];
  }
  //+-
  ll ans=0,tmp=0;
  for(int i=0;i<N;++i){
    if(i%2==0){
      if(cumsum[i]+tmp<=0){
        ans += abs(cumsum[i]+tmp)+1;
        tmp += abs(cumsum[i]+tmp)+1;
      }
    }
    else{
      if(cumsum[i]+tmp>=0){
        ans += cumsum[i]+tmp+1;
        tmp -= cumsum[i]+tmp+1;
      }
    }
  }
  //-+
  ll ans2=0,tmp2=0;
  for(int i=0;i<N;++i){
    if(i%2==1){
      if(cumsum[i]+tmp2<=0){
        ans2 += abs(cumsum[i]+tmp2)+1;
        tmp2 += abs(cumsum[i]+tmp2)+1;
      }
    }
    else{
      if(cumsum[i]+tmp2>=0){
        ans2 += cumsum[i]+tmp2+1;
        tmp2 -= cumsum[i]+tmp2+1;
      }
    }
  }
  cout << min(ans,ans2) << endl;
}