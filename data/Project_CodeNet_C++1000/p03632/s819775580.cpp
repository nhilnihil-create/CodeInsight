#include <bits/stdc++.h>
using namespace std;


int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int kotae=min(b,d)-max(a,c);
  if(kotae<=0){
    cout<<0<<endl;
  }else{
    cout<<kotae<<endl;
  }
  return 0;
}