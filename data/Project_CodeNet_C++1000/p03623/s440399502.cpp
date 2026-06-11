#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int x,a,b;
  cin>>x>>a>>b;
  a=abs(x-a);
  b=abs(x-b);
  if(a<=b){
    cout<<"A"<<"\n";
  }
  else{
    cout<<"B"<<"\n";
  }
  return 0;
}