#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}
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
  int n,l;
  cin>>n>>l;
  ll vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  int p=0,q,r;
  for(int i=0;i<n-1;i++){
    if(vec[i]+vec[i+1]>=l){
      p++;
      q=i;
      r=i+1;
      break;
    }
  }
  if(p==0){
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<"Possible"<<endl;
  for(int i=1;i<r;i++){
    cout<<i<<endl;
  }
  for(int i=n-1;i>r;i--){
    cout<<i<<endl;
  }
  cout<<r<<endl;
  return 0;
}