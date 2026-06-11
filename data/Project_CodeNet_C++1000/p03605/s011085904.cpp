#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  bool a=false;
  while(n>0){    
    if(n%10==9){a=true;
               break;
               }
    else{n/=10;}
  }
  if(a){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
}
  
