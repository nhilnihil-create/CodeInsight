#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int k;
  cin >> k;
  
  ll res = 1;
  
  for (int i = 1; i <= k; ++i) {
    res = (res * i) % 1000000007;
  }
  
  cout << res << endl;
  return 0;
}