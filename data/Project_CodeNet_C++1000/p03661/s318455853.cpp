#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n;cin>>n;
  int a[n];
  for(int i = 0; n > i; i++)cin >> a[i];
  long long b[n];
  b[0] = a[0];
  for(int i = 1; n > i; i++){
    b[i] = b[i-1]+a[i];
  }
  //b[n-1]
  long long mn = 1000000000;
  for(int i = 1; n-1 > i; i++){
    long long tmp = max(b[n-1]-(b[i]*2),(b[i]*2)-b[n-1]);
    mn = min(tmp,mn);
  }
  if(n == 2){
    mn = abs(a[1]-a[0]);
  }
  cout << mn << endl;
}