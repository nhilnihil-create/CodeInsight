#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
#define all(v) (v).begin(),(v).end()
#define vsort(v) sort(all(v))
 
int main(){
  ll i,j,k,N,M,L,cnt,ans=0;
  cin>>N>>M;
  mat v(M);
  pvec x(N);
  rep(i,N){
    cin>>x[i].second;
    x[i].first=x[i].second%M;
  }
  vsort(x);
  rep(i,N){
    v[x[i].first].push_back(x[i].second);
  }
  L=M/2+1;
  rep(i,L){
    j=(M-i)%M;
    if(i==j){
      cnt=v[i].size()/2;
      ans+=cnt;
      continue;
    }
    cnt=0;
    if(v[i].size()<v[j].size()){
      rep(k,(ll)v[j].size()-1){
        if(v[j][k]==v[j][k+1]){
          cnt++;
          k++;
        }
      }
      k=(v[j].size()-v[i].size())/2;
      ans+=v[i].size()+min(cnt,k);
    }else{
      if(v[i].size()==0)continue;
      rep(k,(ll)v[i].size()-1){
        if(v[i][k]==v[i][k+1]){
          cnt++;
          k++;
        }
      }
      k=(v[i].size()-v[j].size())/2;
      ans+=v[j].size()+min(cnt,k);
    }
  }
  cout<<ans<<endl;
  return 0;
}