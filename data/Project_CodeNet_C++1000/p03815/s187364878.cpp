#include<iostream>
using namespace std;
int main(){
  long long x,ans;
  cin >> x;
  ans = x / 11;
  ans *= 2;
  x = x%11;
  if (x > 6) {
    ans += 2;
  } else if (x > 0) {
    ans += 1;
  }
  cout << ans << endl;
}