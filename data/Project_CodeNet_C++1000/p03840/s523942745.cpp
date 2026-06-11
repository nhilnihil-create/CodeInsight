#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 2100000000
#define MOD 1000000007

int main(){
  vector<ll> a(7);
  for(int i=0;i<7;i++){
    cin>>a.at(i);
  }
  ll ans=0;
  ll x=a.at(0)%2+a.at(3)%2+a.at(4)%2;
  if(x==3){
    a.at(0)--;
    a.at(3)--;
    a.at(4)--;
    ans+=3;
  }else if(x==2){
    if(a.at(0)>0&&a.at(3)>0&&a.at(4)>0){
      a.at(0)--;
      a.at(3)--;
      a.at(4)--;
      ans+=3;
    }
  }
  ans+=a.at(1);
  ans+=(a.at(0)/2)*2;
  ans+=(a.at(3)/2)*2;
  ans+=(a.at(4)/2)*2;
  cout<<ans<<endl;
}
