#include <iostream>
#include <string>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];

int main() {

  int n, pos = 1, p, ans = 1;
  cin >> n;
  while(n > 1){
    n = n >> 1;
    ans = ans << 1;
  }
  cout << ans;
  return 0;
}
