#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  int N,W;
  cin>>N>>W;
  vector<ll> w(N),v(N);
  for(int i=0;i<N;i++){
    cin>>w.at(i)>>v.at(i);
  }
  vector<vector<ll>> value(4);
  for(int i=0;i<N;i++){
    value.at(w.at(i)-w.at(0)).push_back(v.at(i));
  }

  vector<int> k(4);
  for(int i=0;i<4;i++){
    sort(value.at(i).begin(),value.at(i).end());
    reverse(value.at(i).begin(),value.at(i).end());
    k.at(i)=value.at(i).size();
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<k.at(i)-1;j++){
      value.at(i).at(j+1)+=value.at(i).at(j);
    }
  }
  ll ans=0;
  for(ll i1=0;i1<=k.at(0);i1++){
    for(ll i2=0;i2<=k.at(1);i2++){
      for(ll i3=0;i3<=k.at(2);i3++){
        for(ll i4=0;i4<=k.at(3);i4++){
          if(i1*w.at(0)+i2*(w.at(0)+1)+i3*(w.at(0)+2)+i4*(w.at(0)+3)>W){
            break;
          }
          ll sub=0;
          if(i1>0){
            sub+=value.at(0).at(i1-1);
          }
          if(i2>0){
            sub+=value.at(1).at(i2-1);
          }
          if(i3>0){
            sub+=value.at(2).at(i3-1);
          }
          if(i4>0){
            sub+=value.at(3).at(i4-1);
          }
          ans=max(ans,sub);
        }
      }
    }
  }
  cout<<ans<<endl;
}
