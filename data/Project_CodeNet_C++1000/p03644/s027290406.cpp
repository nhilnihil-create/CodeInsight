#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin>>n;
  int ans=1;
  int M=0;
  for(int i=1;i<=n;i++){
    int x=0;
    int y=i;
    while(y%2==0){
      x++;
      y/=2;
    }
    if(M<x){
      M=x;
      ans=i;
    }
  }
  cout<<ans<<endl;
}