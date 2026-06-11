#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pp=pair<ll,pair<int,int>>;
using Graph=vector<vector<pair<int,ll>>>;

int main(){
  ll N,A,B,C,D;
  cin>>N>>A>>B>>C>>D;
  if(abs<ll>(A-B)>(N-1)*D){
    cout<<"NO"<<endl;
  }else{
    ll x=abs<ll>(A-B);
    ll y=D-C;
    bool flag=false;
    for(ll i=0;i<=N-1;i++){
      ll z=D*i-(N-1-i)*C;
      if(z>=x){
        if(z-y*(N-1)<=x){
          flag=true;
          break;
        }
      }
    }
    if(flag){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }

}
