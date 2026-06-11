#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if(abs(x-b) > abs(x-a)){
    cout<<"A"<<'\n';
  }
  else{
    cout<<"B"<<'\n';
  }
  return 0;
}

