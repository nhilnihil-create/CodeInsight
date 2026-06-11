#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b;
  cin>>a>>b;
  if(a==1){
    a=14;
  }
  if(b==1){
    b=14;
  }
  if(a>b){
    cout<<"Alice"<<"\n";
  }
  else if(a<b){
    cout<<"Bob"<<"\n";
  }
  else{
    cout<<"Draw"<<"\n";
  }
    return 0;
}