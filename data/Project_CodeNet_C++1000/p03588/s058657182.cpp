#include <bits/stdc++.h>
using namespace std;
int64_t INF = 10000000000;

int main()
{
  int64_t N, a, b, maxp = INF;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a >> b;
    maxp = min(maxp, a + b);
  }
  cout << maxp << endl;
}
