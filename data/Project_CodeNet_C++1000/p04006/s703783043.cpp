#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  ll x;
  cin>>n>>x;
  ll vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  ll sum=1e15,p=0;
  ll ans[n];
  for(int i=0;i<n;i++){
    p=0;
    if(i==0){
      for(int j=0;j<n;j++){
        ans[j]=vec[j];
        p+=ans[j];
      }
      sum=min(sum,p);
    }
    else{
      for(int j=0;j<n;j++){
        ans[j]=min(ans[j],vec[(j-i+n)%n]);
        p+=ans[j];
      }
      sum=min(sum,p+x*i);
    }
  }
  cout<<sum<<endl;
}