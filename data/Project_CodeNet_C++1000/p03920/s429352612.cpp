#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n;
  cin>>n;
  int z=0;
  if(n==1){
    cout<<1;
  }
  else{
  for(int i=1;i<n;i++){
    if(((i*(i+1))/2)<=n&&(((i+1)*(i+2))/2)>n){
      z+=i+1;
      break;
    }
  }
  int jyogai=((z*(z+1))/2)-n;
  for(int i=1;i<=z;i++){
    if(i==jyogai){
      continue;
    }
    cout<<i<<endl;
  }
  }
}