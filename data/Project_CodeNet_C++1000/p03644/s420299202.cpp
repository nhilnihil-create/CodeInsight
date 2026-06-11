#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n==1){
    cout<<1<<endl;
    return 0;
  }
  int count=0;
  for(int i=6;i>=0;i--){
    if(pow(2,i)<=n){
      cout<<pow(2,i)<<endl;
      return 0;
    }
  }
}