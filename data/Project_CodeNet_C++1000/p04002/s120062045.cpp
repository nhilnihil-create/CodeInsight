#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
ll H,W,N;
int main(){
  cin>>H>>W>>N;
  set<P>S;
  for(int i=0;i<N;i++){
  ll h,w;cin>>h>>w; P p(h,w);
    S.insert(p);
  }vector<ll>ans(10);
  for(auto x:S){
    ll i=x.first;ll j=x.second;
    for(ll a=-1;a<=1;a++)
      for(ll b=-1;b<=1;b++){
      ll I=i+a;
        ll J=j+b;
        if(1<=I-1 && I+1<=H && 1<=J-1 && J+1<=W){
        ll sum=0;
          for(ll a1=-1;a1<=1;a1++)
            for(ll b1=-1;b1<=1;b1++){
            P p(a1+I,b1+J);if(S.count(p))sum++;
            
            }ans[sum]++;
        }
      
      }
  }for(ll i=1;i<=9;i++)
    ans[i]/=i;
  ans[0]=(H-2)*(W-2);
  for(ll i=1;i<=9;i++)
    ans[0]-=ans[i];
  for(int i=0;i<10;i++)
    cout<<ans[i]<<endl;
    
    
  return 0;
}