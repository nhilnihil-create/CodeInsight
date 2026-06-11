#include<iostream>
using namespace std;

int main(){
 int a,b,c;
  cin>>a>>b>>c;
  bool flag=false;
  
  if((a+b)==c)flag=true;
  if((b+c)==a)flag=true;
  if((c+a)==b)flag=true;
  
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}
