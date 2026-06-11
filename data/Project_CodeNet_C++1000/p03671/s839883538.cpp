#include<iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int max=a;
  if(max<b)max=b;
  if(max<c)max=c;
  if(max==a)cout<<b+c<<endl;
  else if(max==b)cout<<a+c<<endl;
  else cout<<a+b<<endl;
}