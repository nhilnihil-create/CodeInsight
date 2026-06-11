#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
 
long long lcm(long long a, long long b) {
    long long d = gcd(a, b);
    return a / d * b;
}

int main(){
  int n;
  cin >> n;
  long long ans = 1;
  for(int i=0; i<n; i++){
    long long num;
    cin >> num;
    ans = lcm(ans, num);
  }
  cout << ans << endl;
  return 0;
}
