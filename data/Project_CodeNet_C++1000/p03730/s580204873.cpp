#include <bits/stdc++.h>
using namespace std;

int prime(int A,int B){
  int ret=0;
  for(int i=2;i<=10;i++){
    if((A%i==0)&&(B%i==0)){
      ret=i;
    }
  }
  return ret;
}

int main() {
  int A,B,C;
  cin>>A>>B>>C;
  int factor=0;
  bool ans=true;
  while(ans){
    factor = prime(A,B);
    if(factor){
      A/=factor;
      B/=factor;
      if(C%factor==0)
        C/=factor;
      else
        ans=false;
    }
    else
      break;
  }
  if(ans)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}
