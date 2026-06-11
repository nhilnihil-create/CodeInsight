#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,ans;
  string c;
  cin>>a>>c>>b;
  if(c[0]=='+'){
    ans=a+b;
  }
  else{
    ans=a-b;
  }
  cout<<ans<<"\n";
  return 0;
}