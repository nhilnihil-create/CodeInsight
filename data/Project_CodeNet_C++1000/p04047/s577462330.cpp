#include <iostream>
#include <algorithm>

using namespace std;

int const NMAX = 100;
int v[1 + NMAX + 1];

int main() {

  int n, p, ans = 0;
  cin >> n;
  n *= 2;
  for(int i = 1;i <= n;i++){
    cin >> v[i];
  }
  sort(v+1, v+n+1);
  for(int i = 1;i <= n;i+=2){
    ans += v[i];
  }
  cout << ans;
  return 0;
}
