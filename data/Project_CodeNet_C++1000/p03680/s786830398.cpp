#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector <int> a(N+1);
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
  }
  int ans = 0;
  int button = 1;
  for (ans = 0; ans < N; ans++) {
    if (button==2) break;
    button = a[button];
  }
  if (ans >= N) ans = -1;
  cout << ans << endl;
  return 0;
}
