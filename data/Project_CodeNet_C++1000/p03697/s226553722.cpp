#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c;
  cin>>a>>b;
  c=a+b;
  if(c>=10){
    cout<<"error"<<"\n";
  }
  else{
    cout<<c<<"\n";
  }
  return 0;
}