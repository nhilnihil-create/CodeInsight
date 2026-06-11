#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<max(a*b,c*d)<<"\n";
  
  return 0;
}