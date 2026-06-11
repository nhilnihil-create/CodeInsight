#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N, T, l = 0, r = 0, cnt = 0;
  cin >> N >> T;

  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    if (r < t) {
      cnt += r - l;
      l = t;
    }
    r = t + T;
  }
  cnt += r - l;

  cout << cnt << endl;
    return 0;
}
