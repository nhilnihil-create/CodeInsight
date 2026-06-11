#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,a;
  cin>>n>>a;
  n*=n;
  n-=a;
  cout<<n<<"\n";
  
  return 0;
}