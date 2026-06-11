#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mpower(ll a,ll b,ll c){
  int z;
  if(b==0){
    z=1;
    z%=c;
    return z;
  }
  if(b==1){
    z=a;
    z%=c;
    return z;
  }
  else{
    return (((mpower(a,b/2,c))*(mpower(a,b/2,c))%c)*mpower(a,b%2,c)%c);
  }
}

int main(){
  ll mod=1e9+7;
  int a;
  cin>>a;
  if(a%2==0){
    int vec[a];
    for(int i=0;i<a;i++){
      cin>>vec[i];
      if(vec[i]%2!=1){
        cout<<0<<endl;
        return 0;
      }
    }
    sort(vec,vec+a);
    for(int i=0;i<a;i++){
      if((i/2)*2+1!=vec[i]){
        cout<<0<<endl;
        return 0;
      }
    }
    cout<<mpower(2,a/2,mod)<<endl;
    return 0;
  }
  int vec[a];
  for(int i=0;i<a;i++){
    cin>>vec[i];
    if(vec[i]%2!=0){
      cout<<0<<endl;
      return 0;
    }
  }
  sort(vec,vec+a);
  for(int i=0;i<a;i++){
    if((i+1)/2*2!=vec[i]){
      cout<<0<<endl;
      return 0;
    }
  }
  cout<<mpower(2,a/2,mod)<<endl;
}