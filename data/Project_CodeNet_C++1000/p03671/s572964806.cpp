#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a[5];
  for(int i=0;i<3;i++){
    cin>>a[i];
  }
  sort(a,a+3);
  cout<<a[0]+a[1]<<"\n";

  return 0;
}