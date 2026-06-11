#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,ans=0;
  cin>>a>>b;
  ans=a+b;
  if(ans%3==0){
    cout<<"Possible"<<"\n";
  }
  else{
    if(a%3==0 || b%3==0){
      cout<<"Possible"<<"\n";
    }
    else{
      cout<<"Impossible"<<"\n";
    }
  }

  return 0;
}