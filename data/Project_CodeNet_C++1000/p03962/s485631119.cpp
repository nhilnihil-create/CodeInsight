#include<iostream>
using namespace std;

int main(){
 int a,b,c;
  cin>>a>>b>>c;
  
  int count=1;
  if(b!=a)count++;
  if((c!=a) && (c!=b))count++;
  
  cout<<count<<endl;
  return 0;
}