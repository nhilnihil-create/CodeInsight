#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    ans += min(abs(x)*2, abs(x-K)*2);
  }
  cout << ans << endl;
  return 0;
}
