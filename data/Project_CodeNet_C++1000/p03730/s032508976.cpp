#include <bits/stdc++.h>
using namespace std;



int main(){
  
  int A,B,C;
  cin>>A>>B>>C;
  
  bool can=false;
  for(int i=1;i<=100;i++){
    if(i*A%B==C) can=true;
  }
  
  if(can) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

}