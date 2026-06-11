#include <iostream>
using namespace std;
int main(){
  long long n;
  long long x = 1;
  cin >> n;
  int i;
  for(i=1;i<=n;i++){
    x *= i;
    x %= 1000000007;
  }
  cout << x << "\n";
  return 0;
}