#include <iostream>

using namespace std;

int main() {

  long long n, t, a, b, ans = 0;
  cin >> n >> t;
  b = -t - 1;
  for(long long i = 1;i <= n;i++){
    cin >> a;
    ans += t;
    if(a <= b + t){
      ans -= b + t - a;
    }else{
      //..
    }
    b = a;
  }
  cout << ans;
  return 0;
}
