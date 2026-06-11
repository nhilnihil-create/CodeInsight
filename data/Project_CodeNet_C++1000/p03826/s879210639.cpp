#include <iostream>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int ret;
  if(a*b>c*d){
    ret=a*b;
  }else{
    ret=c*d;
  }
  cout<<ret;
  return 0;
}