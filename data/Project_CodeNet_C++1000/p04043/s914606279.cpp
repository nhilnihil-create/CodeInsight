#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a;
  int f=0,s=0;
  for(int i=0;i<3;i++){
    cin>>a;
    if(a==5){
      f++;
    }
    else if(a==7){
      s++;
    }
  }
  if(f==2 && s==1){
    cout<<"YES"<<"\n";
  }
  else{
    cout<<"NO"<<"\n";
  }
  return 0;
}