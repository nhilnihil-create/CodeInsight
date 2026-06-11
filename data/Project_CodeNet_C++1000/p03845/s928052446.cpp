#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,sum=0;
  cin>>n;
  int a[n];
  for(int i=1;i<=n;i++){
    cin>>a[i];
    sum+=a[i];}
  int m;
  cin>>m;
  while(m--){
    int p,x;
    cin>>p>>x;
    cout<<sum-a[p]+x<<endl;}
  return 0;
}
