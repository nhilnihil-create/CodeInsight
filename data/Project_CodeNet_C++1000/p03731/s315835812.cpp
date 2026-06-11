#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,t,vec[200000],sum;
  cin>>n>>t;
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  for(int i=0;i<n-1;i++){
    sum+=min(t,vec[i+1]-vec[i]);
  }
  cout<<sum+t<<endl;
  return 0;
}