#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,ans;
  cin>>a>>b;
  ans=a+b;
  if(ans>=24){
    ans-=24;
  }
  cout<<ans<<"\n";
  
    return 0;
}