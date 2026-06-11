#include <bits/stdc++.h>
#define int long long
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
main(){
  int n,m;
  cin>>n>>m;
  int a[n],b[n];
  r(i,n)cin>>a[i];
  b[n-1]=a[n-1];
  for(int i=n-1;i>0;i--){
    b[i-1]=max(a[i-1],b[i]);
  }
  int MAX=0;
  for(int i=0;i<n;i++){
    MAX=max(MAX,b[i]-a[i]);
  }
  int sum=0;
  r(i,n){
    if(b[i]-a[i]==MAX)sum++;
  }
  cout<<sum<<endl;
}