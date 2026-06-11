#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, t, a, x = 1, y = 1;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> t >> a;
    int64_t x_t = (x % t == 0) ? x / t : x / t + 1;
    int64_t y_a = (y % a == 0) ? y / a : y / a + 1;
    x = t * max(x_t, y_a);
    y = a * max(x_t, y_a);
  }
  cout << x + y << endl;
}