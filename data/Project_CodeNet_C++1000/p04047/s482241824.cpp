#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
  int n,a[10000],sum=0;
  cin>>n;
  for(int i=0;i<n*2;i++){
    cin>>a[i];
  }
  sort(a,a+n*2);
  for(int i=0;i<n*2;i+=2){
    sum+=a[i];
  }
  cout<<sum<<"\n";
}

