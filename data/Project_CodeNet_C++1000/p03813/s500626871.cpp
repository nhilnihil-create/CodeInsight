#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int x;
  cin>>x;
  if(x>=1200){
    cout<<"ARC"<<"\n";
  }
  else{
    cout<<"ABC"<<"\n";
  }
  
  return 0;
}