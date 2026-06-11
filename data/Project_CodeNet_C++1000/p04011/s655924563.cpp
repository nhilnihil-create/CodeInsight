#include<iostream>
using namespace std;

int main(){
  int n,k,x,y,a;
  cin>>n>>k>>x>>y;
  
  if(k>n){
    a=n*x;
  }else{
  	a=k*x+(n-k)*y;
  }
  cout<<a;
  
  return 0;
}
  
