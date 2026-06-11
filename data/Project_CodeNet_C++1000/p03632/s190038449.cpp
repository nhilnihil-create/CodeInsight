#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(b<=c){
    cout<<0<<endl;
  }
  else if(d<=a){
    cout<<0<<endl;
  }
  else{
    cout<<min(b,d)-max(a,c)<<endl;
  }
}
    
