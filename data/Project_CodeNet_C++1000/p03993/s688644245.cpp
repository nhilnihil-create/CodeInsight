#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n,a[10000000],sum=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    if(i+1==a[a[i]-1]) sum++;
  }
  cout<<sum/2<<"\n";
}