#include <bits/stdc++.h>
using namespace std;
int main(){
int x,a,b,c,d,e;
  cin>>x>>a>>b;
  c=abs(x-a);
  d=abs(x-b);
  e=min(c,d);
  if(e==c){
  cout<<"A"<<endl;
  }
  else{
  cout<<"B"<<endl;
  }
  

}