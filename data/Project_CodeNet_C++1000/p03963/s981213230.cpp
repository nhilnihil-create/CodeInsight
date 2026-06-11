#include <iostream>
#include <string>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];

int main() {

  int n, pos = 1, p, ans = 1;
  string GUIDO;
  cin >> n >> p;
  ans *= p;
  for(int i = 1;i < n;i++){
    ans *= (p - 1);
  }
  cout << ans;
  return 0;
}
