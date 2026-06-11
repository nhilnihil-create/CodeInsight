#include <iostream>
using namespace std;
int main(){
  int x,t,ret;
  cin>>x>>t;
  ret=x-t;
  if(ret>0){
    cout<<ret;
  }else{
    cout<<0;
  }
  return 0;
}