#include <iostream>

int main(){
 using namespace std;
  int d1,w1,a1;
  int d2,w2,a2;
  
  cin>>d1>>w1>>d2>>w2;
  a1=d1*w1;
  a2=d2*w2;
  
  a1<a2? cout<<a2:cout<<a1;
  return 0;
}