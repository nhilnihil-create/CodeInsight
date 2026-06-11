#include<iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans=1;
  if(a!=b)
    ans+=1;
  if(a!=c&&b!=c)
    ans+=1;
  cout<<ans<<endl;
}