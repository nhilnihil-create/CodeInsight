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

int main(){
  int n;
  ll k;
  cin>>n>>k;
  ll p;
  cin>>p;
  ll mx=p;
  ll z;
  for(int i=0;i<n-1;i++){
    cin>>z;
    if(z==k){
      cout<<"POSSIBLE"<<endl;
      return 0;
    }
    mx=max(mx,z);
    p=gcd(p,z);
  }
  if(mx<k){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  if(k%p!=0){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  cout<<"POSSIBLE"<<endl;
}