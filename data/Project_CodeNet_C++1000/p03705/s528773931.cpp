#include <iostream>

using namespace std;

typedef long long ll;

int main () {
  ll n, a, b;
  cin >> n >> a >> b;

  if (a > b) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 1 && a != b) {
    cout << 0 << endl;
    return 0;
  } 
  
  ll mx = (n - 1) * b + a;
  ll mn = (n - 1) * a + b;
  cout << mx - mn + 1 << endl;
}
