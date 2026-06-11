#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

int main() {
  long long n,m;
  cin >> n >> m;
  long long ans = 0;
  if(m <= 2*n) {
    ans = m/2;
  }else {
    ans = n + (m-2*n)/4;
  }
  cout << ans << endl;
  return 0;
}