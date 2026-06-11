#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, a, mx = 0, gc;
  cin >> N >> K;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    mx = max(mx, a);
    if (i)
      gc = __gcd(gc, a);
    else
      gc = a;
  }
  cout << ((!(K % gc) && K <= mx) ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
