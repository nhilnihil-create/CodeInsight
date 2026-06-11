#include <iostream>
using namespace std;

long int euc(long int x,long int y);

int main(void){
  long int n,x,ans;
  cin >> n >> x;
  if (n>x*2) ans=euc(n-x,x);
  else ans=euc(x,n-x);
  cout << ans*3 << endl;
  return 0;
}

long int euc(long int x,long int y){
  if (x%y==0) return x;
  long int nx,ny;
  nx=y;
  ny=x%y;
  return x-ny+euc(nx,ny);
}