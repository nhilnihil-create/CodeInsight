#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n;
  cin>>n;
  ll a[n],b[n];
  for(i=0;i<n;i++)cin>>a[i]>>b[i];
  ll ma=0;
  for(i=0;i<n;i++){
    if(ma<a[i]){
      ma=a[i];
      cnt=i;
    }
  }
  cout<<a[cnt]+b[cnt];
}