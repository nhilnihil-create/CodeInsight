#include <iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int r=a+b;
  while(r>=24){
    r=r-24;
  }
  cout<<r;
}