#include<iostream>
#include<math.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  
  int ans = 0;
  int i = 0;
  while (pow(2,i) <= n) {
    ans = pow(2,i);
    i++;
  }
  cout << ans << endl;
}