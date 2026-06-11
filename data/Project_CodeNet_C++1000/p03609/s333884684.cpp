#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int x,t;
  cin>>x>>t;
  x-=t;
  if(x<0){
    x=0;
  }
  cout<<x<<"\n";

  return 0;
}