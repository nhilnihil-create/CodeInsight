#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int N,W; cin>>N>>W;
  vector<ll> w0,w1,w2,w3;
  ll base;
  for(int i=0;i<N;i++){
    ll wei,val; cin>>wei>>val;
    if(i==0){
      base=wei;
      w0.push_back(val);
    }else{
      if(base==wei){
        w0.push_back(val);
      }else if(base+1==wei){
        w1.push_back(val);
      }else if(base+2==wei){
        w2.push_back(val);
      }else{
        w3.push_back(val);
      }
    }
  }
  sort(w0.rbegin(),w0.rend());
  sort(w1.rbegin(),w1.rend());
  sort(w2.rbegin(),w2.rend());
  sort(w3.rbegin(),w3.rend());
  vector<ll> sum0(w0.size()+1,0),sum1(w1.size()+1,0),sum2(w2.size()+1,0),sum3(w3.size()+1,0);
  for(int i=1;i<=w0.size();i++){
    sum0[i]=sum0[i-1]+w0[i-1];
  }
  for(int i=1;i<=w1.size();i++){
    sum1[i]=sum1[i-1]+w1[i-1];
  }
  for(int i=1;i<=w2.size();i++){
    sum2[i]=sum2[i-1]+w2[i-1];
  }
  for(int i=1;i<=w3.size();i++){
    sum3[i]=sum3[i-1]+w3[i-1];
  }
  ll sum,ans=0;
  for(int i=0;i<sum0.size();i++){
    if(W<i*base) break;
    for(int j=0;j<sum1.size();j++){
      if(W<i*base+(base+1)*j) break;
      for(int k=0;k<sum2.size();k++){
        if(W<i*base+(base+1)*j+(base+2)*k) break;
        for(int l=0;l<sum3.size();l++){
          if(W<i*base+(base+1)*j+(base+2)*k+(base+3)*l) break;
          sum=sum0[i]+sum1[j]+sum2[k]+sum3[l];
          if(sum>ans) ans=sum;
        }
      }
    }
  }
  cout<<ans<<endl;
}