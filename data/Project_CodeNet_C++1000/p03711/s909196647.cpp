#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int c[]={0,1,2,1,3,1,3,1,1,3,1,3,1};
  if(c[a]==c[b])
    cout<<"Yes";
  else
    cout<<"No";
  
  return 0;
}