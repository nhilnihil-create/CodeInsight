#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll ans=0,vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  ll sum=0,sumb=0;
  for(int i=0;i<n;i++){
    sum+=vec[i];
    if(i%2==0){
      if(sum<1){
        sumb+=1-sum;
        sum=1;
      }
    }
    if(i%2==1){
      if(sum>-1){
        sumb+=sum+1;
        sum=-1;
      }
    }
  }
  ans=sumb;
  sumb=0;
  sum=0;
  for(int i=0;i<n;i++){
    sum+=vec[i];
    if(i%2==0){
      if(sum>-1){
        sumb+=sum+1;
        sum=-1;
      }
    }
    if(i%2==1){
      if(sum<1){
        sumb+=1-sum;
        sum=1;
      }
    }
  }
  cout<<min(ans,sumb)<<endl;
}